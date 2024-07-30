import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from interfaces.action import LapTime
import asyncio

class LapTimeActionServer(Node):
    def __init__(self):
        super().__init__('lap_time_action_server')
        self._action_server = ActionServer(
            self,
            LapTime,
            'lap_time',
            self.execute_callback
        )
        self.get_logger().info('Lap Time Action Server Initialized')

    async def execute_callback(self, goal_handle):
        self.get_logger().info('Executing lap time action...')
        clock = self.get_clock()
        start_time = clock.now()
        lap_completed = False

        while not lap_completed:
            feedback_msg = LapTime.Feedback()
            elapsed_time = (clock.now() - start_time).nanoseconds / 1e9
            feedback_msg.elapsed_time = elapsed_time
            goal_handle.publish_feedback(feedback_msg)
            
            # Sleep for 1 second
            await asyncio.sleep(1)
            
            # Check if lap is completed
            lap_completed = True  # For testing, set to True; modify as needed

        result = LapTime.Result()
        result.total_time = (clock.now() - start_time).nanoseconds / 1e9
        goal_handle.succeed()
        self.get_logger().info('Lap time action completed.')
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

