/*
 * Copyright 1996-2023 Cyberbotics Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Description:  An example of use of a camera device.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <webots/display.h>
#include <webots/camera.h>
#include <webots/motor.h>
#include <webots/robot.h>
#include <webots/utils/system.h>
#include <webots/camera_recognition_object.h>

#define SPEED 6 
#define GRIPPER_MOTOR_MAX_SPEED 2.0

//enum BLOB_TYPE { RED, GREEN, BLUE, NONE };
  typedef struct {
          double *color;
          int number;
  }Box;


  static WbDeviceTag camera, fcamera, left_motor, right_motor;
  static int left_speed, right_speed;
  static WbDeviceTag gripper_motors[2];
  static bool grab = 0;
  


int main() {
  int width, height;
  int pause_counter = 0;
  int i = 0, pos = 0;
  bool end = 0;
  bool start = 0;
  
  Box info[6];
  //int i, j;
  //int red, blue, green;
  //const char *color_names[3] = {"red", "green", "blue"};

  wb_robot_init();

  const int time_step = wb_robot_get_basic_time_step();

  /* Get the camera device, enable it, and store its width and height */
  camera = wb_robot_get_device("camera");
  wb_camera_enable(camera, time_step);
  wb_camera_recognition_enable(camera, time_step);
  wb_camera_recognition_enable_segmentation(camera);
  width = wb_camera_get_width(camera);
  height = wb_camera_get_height(camera);
  
  fcamera = wb_robot_get_device("camera(1)");
  wb_camera_enable(fcamera, time_step);
  wb_camera_recognition_enable(fcamera, time_step);
  wb_camera_recognition_enable_segmentation(fcamera);
  width = wb_camera_get_width(fcamera);
  height = wb_camera_get_height(fcamera);
  
  gripper_motors[0] = wb_robot_get_device("horizontal_motor");
  gripper_motors[1] = wb_robot_get_device("finger_motor::left");

  /* get a handler to the motors and set target position to infinity (speed control). */
  left_motor = wb_robot_get_device("left wheel motor");
  right_motor = wb_robot_get_device("right wheel motor");
  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(left_motor, left_speed);
  wb_motor_set_velocity(right_motor, right_speed);
  
  while(wb_robot_step(time_step) != -1)
  {
     const unsigned char *data = wb_camera_recognition_get_segmentation_image(camera);
     const WbCameraRecognitionObject *objects = wb_camera_recognition_get_objects(camera);
     const WbCameraRecognitionObject *fobjects = wb_camera_recognition_get_objects(fcamera);
     
     if (!data) {  // image may be NULL if Robot.synchronization is FALSE
      left_speed = 0;
      right_speed = 0;
     }
     
     /*
     while((wb_robot_step(time_step) != -1) && (i < 6))
     {
         pause_counter = 0;
         RUN();
         if(wb_camera_recognition_get_number_of_objects(camera) == 1)
         {
             while((wb_robot_step(time_step) != -1) && (pause_counter < 80))
             {
                 pause_counter++;
             }
             info[i].color = objects[0].colors;
             i++;
         }
         if(i == 6)
         {
           pause_counter = 0;
           end = 1;
         }
     }
     while((wb_robot_step(time_step) != -1) && (pause_counter < 45))
     {
         left(SPEED);
         pause_counter++;
     }
     while((wb_robot_step(time_step) != -1) && (pause_counter < 890))
     {
         RUN();
         pause_counter++;
     }
     while((wb_robot_step(time_step) != -1) && (pause_counter < 935))
     {
         right(SPEED);
         pause_counter++;
         if(pause_counter == 935)
         {
             stop();
             start = 1;
         }
     }
     
     */
     
     while((wb_robot_step(time_step) != -1) && (pos < 6))
     {
         pause_counter = 0;
         RUN();
         if(wb_camera_recognition_get_number_of_objects(camera) == 1)
         {
             while((wb_robot_step(time_step) != -1) && (pause_counter < 80))
             {
                 pause_counter++;
             }
             info[i].color = objects[0].colors;
             i++;
             pos++;
         }
         if(pos == 6)
         {
           pause_counter = 0;
           end = 1;
         }
     }
     
     while((wb_robot_step(time_step) != -1) && (pos > 0))
     {
         pause_counter = 0;
         RUNB();
         if(wb_camera_recognition_get_number_of_objects(camera) == 1)
         {
             while((wb_robot_step(time_step) != -1) && (pause_counter < 80))
             {
                 pause_counter++;
             }
             pos--;
         }
         if(pos == 0)
         {
           pause_counter = 0;
           start = 1;
         }
     }
     
/*     if(start == 1)
     {
         if(grab == 0)
         {
                   if ((objects[0].position_on_image[0] < 332) && (objects[0].position_on_image[0] > 289))
                   {
                     left(SPEED); 
                   }
                   if ((fobjects[0].position_on_image[0] < 332) && (fobjects[0].position_on_image[0] > 289))
                   {
                     moveForwards(); 
                   }
                   if ((fobjects[0].position_on_image[0] < 260) && (fobjects[0].position_on_image[0] > 247))
                   {
                     stop();
                     moveFingers(-0.6);
                     moveArms(-2.5);
                 
                     while ((pause_counter < 50)&&(wb_robot_step(time_step) != -1)){
                       pause_counter++;
                       }
                     moveFingers(0.0);
                     pause_counter = 0;
                     grab = 1;
                     while ((pause_counter < 50)&&(wb_robot_step(time_step) != -1)){
                       pause_counter++;
                     }
                     moveArms(0.0);
                     pause_counter = 0;
                    }
           }
           else
           {
               while((wb_robot_step(time_step) != -1) && (pause_counter < 50)){
               moveBackwards();
               pause_counter++;
           }
               while((wb_robot_step(time_step) != -1) && (pause_counter < 66)){
               right(SPEED);
               pause_counter++;
           }
           RUN();
           }  
      }
      */
      /*
      wb_motor_set_velocity(left_motor, left_speed);
      wb_motor_set_velocity(right_motor, right_speed);
      */
  }

  wb_robot_cleanup();

  return 0;
}

void RUN() {
    left_speed = SPEED;
    right_speed = SPEED;
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
}

void RUNB() {
    left_speed = -SPEED;
    right_speed = -SPEED;
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
}

void moveForwards() {
    left_speed = 1;
    right_speed = 1;
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
}

void moveBackwards() {
    left_speed = -1;
    right_speed = -1;
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
}

void left(int speed) {
    left_speed = -speed;
    right_speed = speed;
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
}

void right(int speed) {
    left_speed = speed;
    right_speed = -speed;
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
}

void stop() {
    left_speed = 0;
    right_speed = 0;
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
}

void moveArms(double position) {
  wb_motor_set_velocity(gripper_motors[0], GRIPPER_MOTOR_MAX_SPEED);
  wb_motor_set_position(gripper_motors[0], position);
}

void moveFingers(double position) {
  wb_motor_set_velocity(gripper_motors[1], GRIPPER_MOTOR_MAX_SPEED);
  wb_motor_set_position(gripper_motors[1], position);
}