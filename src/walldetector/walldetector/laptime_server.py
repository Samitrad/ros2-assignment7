import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from interfaces.action import LapTime
from rclpy.duration import Duration
import time

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
        self.start_time = time.time()
        self.lap_completed = False

        while not self.lap_completed:
            feedback_msg = LapTime.Feedback()
            feedback_msg.elapsed_time = time.time() - self.start_time
            goal_handle.publish_feedback(feedback_msg)
            await rclpy.sleep(1)

        result = LapTime.Result()
        result.total_time = time.time() - self.start_time
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
