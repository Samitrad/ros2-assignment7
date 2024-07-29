# wall_finder_service.py
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from interfaces.srv import FindClosestWall

class WallFinderService(Node):
    def __init__(self):
        super().__init__('wall_finder_service')
        
        self.service = self.create_service(
            FindClosestWall,
            'find_closest_wall',
            self.handle_find_closest_wall
        )
        
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.scan_sub = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            10
        )

        self.twist = Twist()
        self.distance = float('inf')
        self.closest_distance = float('inf')
        self.moving_to_wall = False
        self.get_logger().info('Service Started')

    def handle_find_closest_wall(self, request, response):
        self.moving_to_wall = True
        self.get_logger().info('Received request to find the closest wall')
        
        self.timer = self.create_timer(0.1, self.check_distance)
        
        response.success = True
        return response

    def check_distance(self):
        if self.moving_to_wall:
            self.twist.linear.x = 0.2
            self.cmd_vel_pub.publish(self.twist)

            if self.distance <= 0.5:
                self.twist.linear.x = 0.0
                self.cmd_vel_pub.publish(self.twist)
                self.get_logger().info('Stopped, wall detected')
                self.timer.cancel()
                self.moving_to_wall = False

    def scan_callback(self, msg):
        if len(msg.ranges) > 0:
            self.distance = min(msg.ranges)
        self.get_logger().info(f"Distance: {self.distance}")

def main(args=None):
    rclpy.init(args=args)
    node = WallFinderService()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

