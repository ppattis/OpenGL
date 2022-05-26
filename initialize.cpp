/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Three Assignment                         * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  initialize.cpp                                  * *
* *   Description         :  Initialize the OpenGL system.                   * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  *************  ****************  **************************************** *
* *   10 May 2022   P. D. Pattison    Initial Coding...                      * *
* *   12 May 2022   P. D. Pattison    Cleanup and comment for turn in.       * *
* *   17 May 2022   P. D. Pattison    Imported into module three.            * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

//  Project includes...
#include "consts.h"
#include "externals.h"
#include "Mesh.h"


//  Function   :  initialize()
//  Parameters :  int argc, char* argv[], GLFWwindow** window
//  Return     :  bool
//  Description:  OpenGL initialization function.
bool initialize(int argc, char* argv[], Mesh* mesh)
{

   //  GLFW:  initialize and configure (specify desired OpenGL version)
   glfwInit();
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

   //  GLFW:  window creation
   mesh->assignWindow(glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL));
   if (mesh->getWindow() == NULL)
   {

      std::cout << "Failed to create GLFW window\n";
      glfwTerminate();
      return false;

   }  //  if (*window == NULL)
   glfwMakeContextCurrent(mesh->getWindow());
   glfwSetFramebufferSizeCallback(mesh->getWindow(), resizeWindow);

   //  GLFW:  initialize
   glewExperimental = GL_TRUE;
   GLenum GlewInitResult = glewInit();

   //  Check for initialization errors.
   if (GLEW_OK != GlewInitResult)
   {

      //  Error occured, report it to stderr and abort.
      std::cerr << glewGetErrorString(GlewInitResult) << "\n";
      return false;

   }  //  if (GLEW_OK != GlewInitResult)

   //  Displays GPU OpenGL version
   std::cout << "INFO:  OpenGL Version: " << glGetString(GL_VERSION) << "\n";

   //  Enable Z-depth
   glEnable(GL_DEPTH_TEST || GL_DEBUG_OUTPUT);
   glDebugMessageCallback(errorCallback, 0);


   //  Initialization was successfull.
   return true;

}  //  bool initialize(int argc, char* argv[], GLFWwindow** window)