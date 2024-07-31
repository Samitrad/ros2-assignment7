import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action import CancelResponse, GoalResponse
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from interfaces.action import LapTime
import time

class LapTimeActionServer(Node):
    def __init__(self):
        super().__init__('lap_time_action_server')
        self._action_server = ActionServer(
            self,
            LapTime,
            'measure_lap_time',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            handle_accepted_callback=self.handle_accepted_callback
        )

        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.scan_subscription = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            10
        )

        self.twist = Twist()
        self.closest_distance = float('inf')
        self.target_distance = 0.5  # Desired distance from the wall
        self.is_following_wall = False
        self.start_time = None
        self.lap_time = None
        self.get_logger().info('Lap Time Action Server Initialized')

    def goal_callback(self, goal_request):
        self.get_logger().info('Received goal request')
        return GoalResponse.ACCEPT

    def handle_accepted_callback(self, goal_handle):
        self.get_logger().info('Goal accepted')
        goal_handle.execute()

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        self.is_following_wall = True
        self.start_time = time.time()

        while self.is_following_wall:
            rclpy.spin_once(self)

        self.lap_time = time.time() - self.start_time
        result = LapTime.Result()
        result.lap_time = self.lap_time
        self.get_logger().info(f'Lap completed in {result.lap_time} seconds')
        goal_handle.succeed()

        return result

    def scan_callback(self, msg):
        valid_ranges = [r for r in msg.ranges if r > 0 and r < float('inf')]
        if valid_ranges:
            self.closest_distance = min(valid_ranges)
        else:
            self.closest_distance = float('inf')
        
        self.follow_wall_logic()

    def follow_wall_logic(self):
        if self.is_following_wall:
            if self.closest_distance < self.target_distance + 0.05 and self.closest_distance > self.target_distance - 0.05:
                self.twist.linear.x = 0.2
                self.twist.angular.z = 0.0
            elif self.closest_distance < self.target_distance:
                self.twist.linear.x = 0.0
                self.twist.angular.z = 0.5
            elif self.closest_distance > self.target_distance:
                self.twist.linear.x = 0.2
                self.twist.angular.z = -0.5

            self.cmd_vel_publisher.publish(self.twist)
            self.get_logger().info(f'Following wall. Distance: {self.closest_distance}, Linear Velocity: {self.twist.linear.x}, Angular Velocity: {self.twist.angular.z}')
        else:
            self.twist.linear.x = 0.0
            self.twist.angular.z = 0.0
            self.cmd_vel_publisher.publish(self.twist)

    def stop_following_wall(self):
        self.is_following_wall = False
        self.twist.linear.x = 0.0
        self.twist.angular.z = 0.0
        self.cmd_vel_publisher.publish(self.twist)
        self.get_logger().info('Stopped following wall')

def main(args=None):
    rclpy.init(args=args)
    node = LapTimeActionServer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.stop_following_wall()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

