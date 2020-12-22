# Where-Am-I

# Run the project: 
* Clone the repository
* Open the repository and make it (`catkin_make`)
* Launch the robot in Gazebo to load plug-ins, world, and rviz
```
roslaunch my_robot world.launch
```
* Launch amcl node
```
roslaunch my_robot amcl.launch
```

* Use teleop node to move robot around
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
