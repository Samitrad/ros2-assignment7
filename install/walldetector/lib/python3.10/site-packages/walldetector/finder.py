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
        self.closest_distance = float('inf')
        self.moving_to_wall = False
        self.timer = None  # Initialize timer as None
        self.target_distance = 1 # Desired distance from the wall
        self.get_logger().info('Service Started')

    def handle_find_closest_wall(self, request, response):
        if self.moving_to_wall:
            response.success = False
            response.message = 'Already moving to the wall'
            return response
        
        self.moving_to_wall = True
        self.get_logger().info('Received request to follow the wall')
        
        # Ensure timer is created only once
        if self.timer is None:
            self.timer = self.create_timer(0.1, self.check_distance)
        
        response.success = True
        response.message = 'Following the wall'
        return response

    def check_distance(self):
        if self.moving_to_wall:
            if self.closest_distance <= self.target_distance + 0.05 and self.closest_distance >= self.target_distance - 0.05:
                # Move forward if within the target distance range
                self.twist.linear.x = 0.5
                self.twist.angular.z = 0.0 
            elif self.closest_distance < self.target_distance:
                # Turn away from the wall if too close
                self.twist.linear.x = 0.02
                self.twist.angular.z = 0.3
            elif self.closest_distance > self.target_distance:
                # Turn towards the wall if too far
                self.twist.linear.x = 0.02
                self.twist.angular.z = -0.3
            
            self.cmd_vel_pub.publish(self.twist)
            self.get_logger().info(f'Following wall. Distance: {self.closest_distance}, Linear Velocity: {self.twist.linear.x}, Angular Velocity: {self.twist.angular.z}')
        else:
            # Stop the robot if not in wall-following mode
            self.twist.linear.x = 0.0
            self.twist.angular.z = 0.0
            self.cmd_vel_pub.publish(self.twist)
            if self.timer:
                self.timer.cancel()
                self.timer = None

    def scan_callback(self, msg):
        # Handle cases where msg.ranges may contain invalid data
        valid_ranges = [r for r in msg.ranges if r > 0 and r < float('inf')]
        if valid_ranges:
            self.closest_distance = min(valid_ranges)
        else:
            self.closest_distance = float('inf')
        self.get_logger().info(f"Closest Distance: {self.closest_distance}")

def main(args=None):
    rclpy.init(args=args)
    node = WallFinderService()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
