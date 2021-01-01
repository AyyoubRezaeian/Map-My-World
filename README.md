# SLAM: Map my world
This is a project to run SLAM for a robot moving inside a building by using rtabmap graph-based SLAM using RGB-D and lidar. 

# Run the project: 
* Clone the repository
* Open the repository and build/make (`catkin_make`)
* Launch the robot in Gazebo to load plug-ins, world, and rviz
```
roslaunch my_robot world.launch
```
* Use teleop node to move robot around
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
* Launch amcl node
```
roslaunch my_robot mapping.launch
```


