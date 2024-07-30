import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from interfaces.action import LapTime  # Import the LapTime action

class LapTimeActionServer(Node):
    def __init__(self):
        super().__init__('lap_time_action_server')
        self._action_server = ActionServer(self, LapTime, 'measure_lap_time', self.execute_callback)
        self.get_logger().info('Lap Time Action Server Initialized')

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        # Add your code here to measure the lap time
        # For now, let's just simulate a lap time measurement
        self.get_logger().info('Measuring lap time...')
        self.sleep(5)  # Simulate a 5-second lap time measurement
        result = LapTime.Result()
        result.lap_time = 5.0  # Set the lap time to 5 seconds
        goal_handle.succeed()
        return result

def main(args=None):
    rclpy.init(args=args)
    node = LapTimeActionServer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
