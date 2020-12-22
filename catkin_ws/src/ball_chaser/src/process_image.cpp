#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    ROS_INFO_STREAM("Moving toward white ball!!!!");
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;
    
    if (!client.call(srv))
    {
       ROS_ERROR("Failed to call service DriveToTarget");
     }
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{ 
    //ROS_INFO_STREAM("Enter Callback!!!!");

    int white_pixel = 255;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
    
    
    float lin_x = 0;
    float ang_z = 0;
    bool ball_exist = false;  
    int number_of_pixel = img.height*img.width;
    int left_side =  img.width/3;
    //ROS_INFO_STREAM("img_step=%1.2f", img.step);
    //ROS_INFO_STREAM("Enter Callback2!!!!");
    for (int i=0;i<img.height*img.step;i=i+3){
        int pixel_column = (i/3)%img.width;
        //ROS_INFO_STREAM("Enter loop!!!!");
        if (img.data[i]==white_pixel && img.data[i+1]==white_pixel && img.data[i+2]==white_pixel){
            ball_exist = true;
            
            if (pixel_column<left_side){
               lin_x = 0.05;
               ang_z = 0.03;  
     
            }
            else if(pixel_column<2*left_side) {              
               lin_x = 0.05;
               ang_z = 0.0; }
            else {     
               lin_x = 0.05;
               ang_z = -0.03; }
            ROS_INFO_STREAM("White ball!!!!");
            break;
			
        } 
     

    }
    if (ball_exist){drive_robot(lin_x, ang_z);}
    else {drive_robot(0, 0);} 
          // ROS_INFO_STREAM("NO MOVE!!!!");


 
    

	
	
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
