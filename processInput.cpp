/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  processInput.cpp                                * *
* *   Description         :  Function to check for keyboard input.           * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  10 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Cleanup and comment for turnin.        * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three.            * *
* *  28 May  2022   P. D. Pattison    Adding camera controls.  Changing this * *
* *                                   function to a callback for user input  * *
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  28 May  2022   P. D. Pattison    Added space bar to re-center view.     * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  29 May  2022   P. D. Pattison    Added "P" key to change projection.    * *
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


//  Function   :  processInput()
//  Parameters :  GLFWwindow* window
//  Return     :  void
//  Description:  Process input from main window.
void processInput(GLFWwindow* window, int key, int scan_code, int action, int mode)
{

   static const float camera_speed = 0.1f;

   //  If the action is GLFW_PRESS then switch on the scan_code for user input.
   if (action == GLFW_PRESS)
   {

      switch (key)
      {

         //  Escape Key; Exit program.
         case (GLFW_KEY_ESCAPE):
            glfwSetWindowShouldClose(window, true);
            break;
         //  'W' Key; Move camera forward
         case (GLFW_KEY_W):
            camera.camera.ProcessKeyboard(FORWARD, camera_speed);
            break;
         //  'A' Key; Move camera left
         case (GLFW_KEY_A):
            camera.camera.ProcessKeyboard(LEFT, camera_speed);
            break;
         //  'S' Key; Move camera backwards
         case (GLFW_KEY_S):
            camera.camera.ProcessKeyboard(BACKWARD, camera_speed);
            break;
         //  'D' Key; Move camera right
         case (GLFW_KEY_D):
            camera.camera.ProcessKeyboard(RIGHT, camera_speed);
            break;
         //  'Q' Key; Move camera up
         case (GLFW_KEY_Q):
            camera.camera.Position.y -= camera_speed;
            break;
         //  'E' Key; Move camera forward
         case (GLFW_KEY_E):
            camera.camera.Position.y += camera_speed;
            break;
         //  Up Key; Zoom in
         case (GLFW_KEY_UP):
            camera.camera.ProcessMouseScroll(1);
            break;
         //  Down Key; Zoom out
         case (GLFW_KEY_DOWN):
            camera.camera.ProcessMouseScroll(-1);
            break;
         case (GLFW_KEY_P):
            if (camera.current_projection == 0)
            {

               camera.current_projection = 1;

            }
            else
            {

               camera.current_projection = 0;

            }
            break;

      }

   }

}  //  void processInput(GLFWwindow* window)