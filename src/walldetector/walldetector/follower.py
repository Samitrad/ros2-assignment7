import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, PoseWithCovarianceStamped
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
        
        # Subscribe to the odometry topic to get yaw
        self.odom_subscription = self.create_subscription(
            PoseWithCovarianceStamped,
            '/odometry/filtered',
            self.odom_callback,
            10
        )
        
        # Initialize parameters
        self.target_distance = 0.5
        self.stop_distance = 0.6  # Distance to stop to avoid collision
        self.safety_margin = 0.2  # Safety margin to prevent hitting the wall
        self.max_speed = 0.2  # Maximum speed
        self.rotation_speed = 0.5  # Speed for rotation
        self.rotation_angle = math.radians(90)  # 90 degrees in radians
        
        self.is_rotating = False
        self.initial_angle = 0.0
        self.current_yaw = 0.0
        
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
                self.initial_angle = self.current_yaw
                self.twist.linear.x = 0.0
                self.twist.angular.z = self.rotation_speed
                self.cmd_vel_publisher.publish(self.twist)
            else:
                # Continue rotating until the robot has rotated 90 degrees
                if self.check_rotation():
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

    def check_rotation(self):
        # Normalize the angle difference
        delta_angle = self.current_yaw - self.initial_angle
        if abs(delta_angle) > math.pi:
            delta_angle = delta_angle - (2 * math.pi * round(delta_angle / (2 * math.pi)))
        return abs(delta_angle) >= self.rotation_angle

    def odom_callback(self, msg):
        # Extract yaw from odometry message
        orientation = msg.pose.pose.orientation
        _, _, self.current_yaw = self.quaternion_to_euler(orientation.x, orientation.y, orientation.z, orientation.w)

    def quaternion_to_euler(self, x, y, z, w):
        # Convert quaternion to Euler angles
        siny_cosp = 2 * (w * z + x * y)
        cosy_cosp = 1 - 2 * (y * y + z * z)
        yaw = math.atan2(siny_cosp, cosy_cosp)
        return 0.0, 0.0, yaw

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
