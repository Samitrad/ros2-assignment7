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
        self.start_time = None
        self.lap_completed = False

    async def execute_callback(self, goal_handle):
        self.get_logger().info('Executing lap time action...')
        clock = self.get_clock()
        self.start_time = clock.now()
        self.lap_completed = False

        while not self.lap_completed:
            feedback_msg = LapTime.Feedback()
            elapsed_time = (clock.now() - self.start_time).nanoseconds / 1e9
            feedback_msg.elapsed_time = elapsed_time
            goal_handle.publish_feedback(feedback_msg)

            # Calculate the time to sleep
            end_time = clock.now() + rclpy.duration.Duration(seconds=1)
            while clock.now() < end_time:
                await asyncio.sleep(0.1)  # Small sleep to prevent busy waiting

        result = LapTime.Result()
        result.total_time = (clock.now() - self.start_time).nanoseconds / 1e9
        goal_handle.succeed()
        return result

def main(args=None):
    rclpy.init(args=args)
    node = LapTimeActionServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

