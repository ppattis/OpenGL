/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  mouseMovementCallback.cpp                       * *
* *   Description         :  Callback function to process mouse events.      * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  28 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
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


//  Function   :  processInput()
//  Parameters :  GLFWwindow* window
//  Return     :  void
//  Description:  Process input from main window.
void mouseMovementCallback(GLFWwindow* window, double mouse_x, double mouse_y)
{

   if (!camera.mouse_seen)
   {

      camera.last_x = mouse_x;
      camera.last_y = mouse_y;
      camera.mouse_seen = true;

   }  //  if (!camera.mouse_seen)

   camera.camera.ProcessMouseMovement(camera.last_x - mouse_x, mouse_y - camera.last_y);

   camera.last_x = mouse_x;
   camera.last_y = mouse_y;

}  //  void mouseMovementCallback(GLFWwindow* window, double mouse_x, double mouse_y)