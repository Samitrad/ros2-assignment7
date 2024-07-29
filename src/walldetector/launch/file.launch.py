import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node1=Node(
            package='walldetector',
            executable='finder',
            name='wall_finder'
        ),
        Node2=Node(
            package='walldetector',
            executable='follower',
            name='wall_follower'
        ),
        Node3=Node(
            package='walldetector',
            executable='laptime_server',
            name='lap_time_server'
        ),
        Node4=Node(
            package='walldetector',
            executable='laptime_client',
            name='lap_time_client'
        )
        return launch.LaunchDescription([
       		 Node1,
       		 Node2,
       		 Node3,
        	 Node4
    ])
