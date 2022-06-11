/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  mouseScrollCallback.cpp                         * *
* *   Description         :  Callback function to process mouse scroll wheel * *
* *                          events.                                         * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  28 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...
#include <iostream>

//  Project includes...
#include "graphics_includes.h"
#include "structs.h"

//  Third party includes...
#include <learnOpengl/camera.h>


//  External global variable declaration...
extern struct camera_structure camera;


//  Function   :  mouseMovementCallback()
//  Parameters :  GLFWwindow* window
//                double      mouse_x
//                double      mouse_y
//  Return     :  void
//  Description:  Process mouse movement
void mouseScrollCallback(GLFWwindow* window, double offset_x, double offset_y)
{

   if (offset_y < 0)
   {

      camera.camera.MouseSensitivity *= 0.1;

   }
   else
   {

      camera.camera.MouseSensitivity /= 0.1;

   }

}  //  void mouseScrollCallback(GLFWwindow* window, double mouse_x, double mouse_y)