/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  resizeWindow.cpp                                * *
* *   Description         :  Resize the OpenGL window to a specified size.   * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  11 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Cleanup and comment for turn in.       * *
* *  27 May  2022   P. D. Pattison    Imported into Module THree.            * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//  Project includes...
#include "externals.h"


//  Function   :  resizeWindow()
//  Parameters :  GLFWwindow* window, int width, int height
//  Return     :  void
//  Description:  Function to resize window.
void resizeWindow(GLFWwindow* window, int width, int height)
{

   //  Set the window dimensions.
   glViewport(0, 0, width, height);

}  //  void resizeWindow(GLFWwindow* window, int width, int height)