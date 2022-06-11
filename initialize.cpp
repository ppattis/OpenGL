/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
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
* *  ************   ***************   *************************************  * *
* *  10 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Cleanup and comment for turn in.       * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three.            * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  29 May  2022   P. D. Pattison    Added initialization of initial        * *
* *                                   projection setting to perspective.     * *
* *  05 June 2022   P. D. Pattison    Imported into module five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...
#include <iostream>

//  Project includes...
#include "consts.h"
#include "externals.h"
#include "graphics_includes.h"

//  Third party includes...
#include <learnOpengl/camera.h>

//  External global variable declarations...
extern struct camera_structure camera;


//  Function   :  initialize()
//  Parameters :  int argc, char* argv[], GLFWwindow** window
//  Return     :  bool
//  Description:  OpenGL initialization function.
bool initialize(int argc, char* argv[], GLFWwindow** window)
{

   //  GLFW:  initialize and configure (specify desired OpenGL version)
   glfwInit();
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

   //  GLFW:  window creation
   *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
   if (*window == NULL)
   {

      std::cout << "Failed to create GLFW window\n";
      glfwTerminate();
      return false;

   }  //  if (*window == NULL)
   glfwMakeContextCurrent(*window);
   glfwSetFramebufferSizeCallback(*window, resizeWindow);

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
   //glEnable(GL_DEPTH_TEST || GL_DEBUG_OUTPUT);
   //glDebugMessageCallback(errorCallback, 0);

      //  Register callback functions...
   glfwSetKeyCallback(*window, processInput);
   glfwSetCursorPosCallback(*window, mouseMovementCallback);
   glfwSetScrollCallback(*window, mouseScrollCallback);

   //  Capture the mouse
   glfwSetInputMode(*window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

   //  Initialize the camera...
   camera.last_x = WINDOW_WIDTH / 2;
   camera.last_y = WINDOW_HEIGHT / 2;
   camera.camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
   camera.mouse_seen = false;
   camera.current_projection = 0;

   //  Initialization was successfull.
   return true;

}  //  bool initialize(int argc, char* argv[], GLFWwindow** window)