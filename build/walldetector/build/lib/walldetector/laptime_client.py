import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from interfaces.action import LapTime

class LapTimeActionClient(Node):
    def __init__(self):
        super().__init__('lap_time_action_client')
        self._action_client = ActionClient(self, LapTime, 'lap_time')

    def send_goal(self):
        goal_msg = LapTime.Goal()
        self._action_client.wait_for_server()
        self.get_logger().info('Sending lap time goal...')
        self._send_goal_future = self._action_client.send_goal_async(goal_msg)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Lap Time: {result.total_time} seconds')

def main(args=None):
    rclpy.init(args=args)
    node = LapTimeActionClient()
    node.send_goal()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
