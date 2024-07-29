import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from interfaces.srv import FindClosestWall

class WallFollowerNode(Node):
    def __init__(self):
        super().__init__('wall_follower_node')
        
        # Create a service client to call FindClosestWall
        self.find_closest_wall_client = self.create_client(FindClosestWall, 'find_closest_wall')
        while not self.find_closest_wall_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        
        # Create a publisher for /cmd_vel
        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        
        # Initialize Twist message
        self.twist = Twist()
        
        # Create a subscription to /scan
        self.scan_subscription = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            10
        )
        
        # Target distance to the wall in meters
        self.target_distance = 0.5
        
        # Call the service to find the closest wall
        req = FindClosestWall.Request()
        future = self.find_closest_wall_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        response = future.result()
        if response.success:
            self.get_logger().info('Successfully moved to the closest wall.')
        else:
            self.get_logger().error('Failed to move to the closest wall.')

    def scan_callback(self, msg):
        # Front distance (assuming 0 degree angle)
        front_distance = msg.ranges[0]
        # Left distance (assuming 90 degree angle)
        left_distance = msg.ranges[90]
        # Right distance (assuming -90 degree angle)
        right_distance = msg.ranges[-90]

        if front_distance < self.target_distance:
            self.twist.linear.x = 0.0
            self.twist.angular.z = -0.35
        elif left_distance < self.target_distance:
            self.twist.linear.x = 0.0
            self.twist.angular.z = -0.15
        elif right_distance < self.target_distance:
            self.twist.linear.x = 0.0
            self.twist.angular.z = 0.15
        else:
            self.twist.linear.x = 0.5
            self.twist.angular.z = 0.0
        self.cmd_vel_publisher.publish(self.twist)

def main(args=None):
    rclpy.init(args=args)
    node = WallFollowerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
