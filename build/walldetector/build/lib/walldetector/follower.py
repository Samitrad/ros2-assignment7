import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
import math

class WallFollowerNode(Node):
    def __init__(self):
        super().__init__('wall_follower_node')
        
        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.twist = Twist()
        
        self.scan_subscription = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            10
        )
        
        self.target_distance = 0.5
        self.stop_distance = 0.3  # Distance to stop to avoid collision
        self.safety_margin = 0.1  # Safety margin to prevent hitting the wall
        self.max_speed = 0.2  # Maximum speed
        self.rotation_speed = 0.3  # Speed for rotation
        self.rotation_angle = math.radians(90)  # 90 degrees in radians
        
        self.is_rotating = False
        self.initial_angle = 0.0
        
        self.get_logger().info('Wall Follower Node Initialized')

    def scan_callback(self, msg):
        # Extract distances from laser scan
        front_distance = min(msg.ranges[:10] + msg.ranges[-10:])  # Front distances
        left_distance = min(msg.ranges[45:135])  # Left distances
        right_distance = min(msg.ranges[-135:-45])  # Right distances
        
        # Debug logs
        self.get_logger().info(f"Front Distance: {front_distance}, Left Distance: {left_distance}, Right Distance: {right_distance}")

        if front_distance < self.stop_distance + self.safety_margin:
            if not self.is_rotating:
                # Start rotation if not already rotating
                self.is_rotating = True
                self.initial_angle = self.get_current_yaw()
                self.twist.linear.x = 0.0
                self.twist.angular.z = self.rotation_speed
                self.cmd_vel_publisher.publish(self.twist)
            else:
                # Continue rotating until the robot has rotated 90 degrees
                current_angle = self.get_current_yaw()
                if abs(current_angle - self.initial_angle) >= self.rotation_angle:
                    # Stop after completing the 90-degree rotation
                    self.twist.angular.z = 0.0
                    self.cmd_vel_publisher.publish(self.twist)
                    self.is_rotating = False
        else:
            # Stop rotation if it was previously rotating
            if self.is_rotating:
                self.twist.angular.z = 0.0
                self.cmd_vel_publisher.publish(self.twist)
                self.is_rotating = False

            # Move forward if at the desired distance from the wall
            self.twist.linear.x = self.max_speed
            self.twist.angular.z = 0.0

        # Publish the command
        self.cmd_vel_publisher.publish(self.twist)

    def get_current_yaw(self):
        # Dummy implementation for current yaw, replace with actual sensor data
        # In a real implementation, you would get this from an odometry or IMU sensor
        return 0.0

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

