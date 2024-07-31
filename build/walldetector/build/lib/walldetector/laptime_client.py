import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from interfaces.action import LapTime

class LapTimeActionClient(Node):

    def __init__(self):
        super().__init__('lap_time_action_client')
        self._action_client = ActionClient(self, LapTime, 'measure_lap_time')

    def send_goal(self):
        goal_msg = LapTime.Goal()
        self.get_logger().info('Sending goal request...')
        self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback).add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')
        goal_handle.get_result_async().add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Received feedback: Elapsed Time = {feedback.elapsed_time:.2f} seconds')

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Result received: Total Time = {result.total_time:.2f} seconds')

def main(args=None):
    rclpy.init(args=args)
    node = LapTimeActionClient()
    node.send_goal()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
