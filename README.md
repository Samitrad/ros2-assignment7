# ros2-assignment7
This package demonstrates a ROS 2-based robotic system for wall-following and lap timing. It includes an action server for lap time tracking, an action client for interacting with the server, and a wall-following node to navigate the robot along walls.
Package Structure

    wall_follower_node.py: Contains the node responsible for wall-following behavior.
    wall_finder_service.py: Provides a service to move the robot to the closest wall.
    laptime_server.py: Implements the action server to track lap times.
    laptime_client.py: Contains the action client to request lap timing and handle results.
    launch/: Directory containing launch files to start the nodes.

Dependencies

Ensure you have ROS 2 installed on your system. This package is compatible with ROS 2 Humble.
Launch File

To start all the nodes together, use the provided launch file:

    Launch all nodes:

    ros2 launch walldetector file.launch.py

Parameters

    target_distance: Desired distance from the wall for the wall-following node.
    stop_distance: Minimum distance to stop if the robot is too close to the wall.
    safety_margin: Margin to prevent collision with the wall.

Troubleshooting

    No output or errors: Ensure all nodes are running and properly configured.
    Robot behavior issues: Adjust PID gains and distance parameters in the wall_follower_node.py file.

Contributing

If you encounter issues or have suggestions for improvements, please submit a pull request or open an issue on the repository.

