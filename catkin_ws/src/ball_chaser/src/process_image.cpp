#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>
#include <cmath> 

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255; //Pixel value of white
    bool is_white = false; // Assume no white pixel found
    int index; // Index value of the white pixel
    int R; // Row number of the white pixel
    float left_bar;
    float right_bar;

    // Loop through each pixel in the image and check if its equal to the white pixel value
    for (int i = 0; i < img.height * img.step; i++) {
        if (img.data[i] == white_pixel) {
            is_white = true;
            index = i; 
            R = std::floor(index / img.step); 
            left_bar = (R*img.step) + (img.step/3);
            right_bar = (R*img.step) + (2*img.step/3) - 1;
            break;
        }
    }

    //If white ball is found drive robot towards the white ball
    if (is_white == true){
        if (index < left_bar ){ //Check if ball is on the left side

        }
        else if (index > right_bar ){  //Check if ball is on the right side

        } 
        else{  //Move robot forward

        }
    }
    else{ //Stop robot's movement

    }
        
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
