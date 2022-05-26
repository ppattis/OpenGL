/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Three Assignment                         * *
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
* *  *************  ****************  **************************************** *
* *   10 May 2022   P. D. Pattison    Initial Coding...                      * *
* *   12 May 2022   P. D. Pattison    Cleanup and comment for turnin.        * *
* *   17 May 2022   P. D. Pattison    Imported into module three.            * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//  Project includes...
#include "Mesh.h"
#include "structs.h"

//  Function   :  processInput()
//  Parameters :  GLFWwindow* window
//  Return     :  void
//  Description:  Process input from main window.
void processInput(Mesh* mesh)
{

   //  Poll if the Escape key is pressed.
   if (glfwGetKey(mesh->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
   {

      //  Escape was pressed, trigger application to close.
      glfwSetWindowShouldClose(mesh->getWindow(), true);

   }  //  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)

}  //  void processInput(GLFWwindow* window)