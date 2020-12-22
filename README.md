# Where-Am-I
This is a project to localize a robot inside a building by using [adaptive monte-carlo localization(AMCL) algorithm](https://343b0276-a0ea-43f6-852b-d6db8e3570ce.filesusr.com/ugd/850e97_94ec4844112e483d91dc27f7e0604d7d.pdf). 

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
