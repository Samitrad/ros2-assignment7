from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='walldetector',
            executable='finder',
            name='wall_finder',
            output='screen',
        ),
        Node(
            package='walldetector',
            executable='follower',
            name='wall_follower',
            output='screen',
        ),
        Node(
            package='walldetector',
            executable='laptime_server',
            name='lap_time_server',
            output='screen',
        ),
        Node(
            package='walldetector',
            executable='laptime_client',
            name='lap_time_client',
            output='screen',
        ),
    ])

