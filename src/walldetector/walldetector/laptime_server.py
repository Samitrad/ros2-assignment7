import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from sensor_msgs.msg import LaserScan
from interfaces.action import LapTime
import time
import os

class LapTimeActionServer(Node):

    def __init__(self):
        super().__init__('lap_time_action_server')
        self._action_server = ActionServer(
            self,
            LapTime,
            'measure_lap_time',
            self.execute_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback
        )

        self.scan_subscription = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            10
        )
        
        self.turns = 0
        self.laps = 0
        self.timer_started = False
        self.latest_lap_turn = 0
        self.front_distance = float('inf')
        self.left_distance = float('inf')
        self.right_distance = float('inf')
        self.close_wall_threshold = 0.8
        self.last_turn_time = time.time()
        self.delay_duration = 10.0  # 10-second delay between turn counts
        self.lap_start_time = None

        # Define log file path
        self.log_file_path = 'lap_times.log'

        # Ensure the log file exists
        if not os.path.exists(self.log_file_path):
            with open(self.log_file_path, 'w') as f:
                f.write("Lap Times Log:\n")

        self.get_logger().info('Lap Time Action Server Initialized')

    def goal_callback(self, goal_request):
        self.get_logger().info('Received goal request')
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle):
        self.get_logger().info('Received cancel request')
        return CancelResponse.ACCEPT

    def scan_callback(self, msg):
        self.front_distance = min(msg.ranges[:10] + msg.ranges[-10:])
        self.left_distance = min(msg.ranges[45:135])
        self.right_distance = min(msg.ranges[-135:-45])
        
        self.check_and_update_turns()

    def check_and_update_turns(self):
        if (self.front_distance < self.close_wall_threshold and
            self.right_distance < self.close_wall_threshold):
            
            current_time = time.time()
            if (current_time - self.last_turn_time) > self.delay_duration:  # 3-second delay
                self.last_turn_time = current_time
                self.turns += 1
                self.get_logger().info(f'Turns: {self.turns}')
                if self.turns % 4 == 0:  # Define a lap every 4 turns
                    self.laps += 1
                    lap_time = time.time() - self.lap_start_time if self.lap_start_time else 0
                    self.get_logger().info(f'Laps: {self.laps}')
                    self.get_logger().info(f'Lap {self.laps} completed in {lap_time:.2f} seconds')
                    self.lap_start_time = time.time()  # Start timing for the next lap

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        start_time = time.time()
        self.latest_lap_turn = self.turns
        self.lap_start_time = start_time  # Start timing for the lap
        self.get_logger().info(f'Start Time for Lap: {start_time}')

        while rclpy.ok():
            if self.turns % 4 == 0 and self.turns != self.latest_lap_turn:
                total_time = time.time() - self.lap_start_time if self.lap_start_time else 0
                result = LapTime.Result()
                result.total_time = total_time
                goal_handle.succeed()
                
                self.get_logger().info(f'Lap completed, Total Time = {total_time:.2f} seconds')
                self.get_logger().info(f'Final Turns: {self.turns}, Final Laps: {self.laps}')
                
                # Log result to file
                self.log_result(total_time)

                return result

            elapsed_time = time.time() - start_time
            feedback = LapTime.Feedback()
            feedback.elapsed_time = elapsed_time
            goal_handle.publish_feedback(feedback)

            self.get_logger().info(f'Current Turns: {self.turns}')
            self.get_logger().info(f'Elapsed Time: {elapsed_time:.2f} seconds')
            self.get_logger().info(f'Latest Turns: {self.latest_lap_turn}')
            self.get_logger().info(f'Timer started: {self.timer_started}')

            rclpy.spin_once(self)

    def log_result(self, total_time):
        self.get_logger().info('Logging result to file...')
        try:
            with open(self.log_file_path, 'a') as log_file:
                log_file.write(f'Lap {self.laps}: {total_time:.2f} seconds\n')
            self.get_logger().info('Result logged successfully')
        except Exception as e:
            self.get_logger().error(f'Failed to log result: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = LapTimeActionServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
