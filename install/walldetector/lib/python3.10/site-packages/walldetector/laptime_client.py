import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from interfaces.action import LapTime
from rclpy.exceptions import ParameterAlreadyDeclaredException

class LapTimeActionClient(Node):
    def __init__(self):
        super().__init__('lap_time_action_client')
        self._action_client = ActionClient(self, LapTime, 'lap_time')
        self.get_logger().info('Lap Time Action Client Initialized')
        self.send_goal()

    def send_goal(self):
        # Wait for the action server to be available
        self._action_client.wait_for_server()

        # Create a goal message
        goal_msg = LapTime.Goal()
        
        # Send the goal and handle the result
        future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        result = future.result()
        if result.accepted:
            self.get_logger().info('Goal accepted by server')
            # Wait for the result
            self._action_client.wait_for_result()
            result_future = self._action_client.get_result_async()
            result_future.add_done_callback(self.result_callback)
        else:
            self.get_logger().error('Goal rejected by server')

    def result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Action result: Total time = {result.total_time} seconds')

    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f'Feedback: Elapsed time = {feedback_msg.feedback.elapsed_time} seconds')

def main(args=None):
    rclpy.init(args=args)
    node = LapTimeActionClient()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

