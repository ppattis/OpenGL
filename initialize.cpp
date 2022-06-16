/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
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
* *  28 May  2022   P. D. Pattison    Added registering callback for         * *
* *                                   keyboard interupts.                    * *
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  28 May  2022   P. D. Pattison    Added callback registration for mouse  * *
* *                                   movement and scroll wheel events.      * *
* *  28 May  2022   P. D. Pattison    Added camera initialization.           * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
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

   //  Set window as current...
   glfwMakeContextCurrent(*window);

   //  Register callbacks...
   glfwSetFramebufferSizeCallback(*window, resizeWindow);
   glfwSetKeyCallback(*window, processInput);
   glfwSetCursorPosCallback(*window, mouseMovementCallback);
   glfwSetScrollCallback(*window, mouseScrollCallback);

   //  Capture the mouse
   glfwSetInputMode(*window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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

   //  Initialize the camera...
   camera.last_x = WINDOW_WIDTH / 2.0f;
   camera.last_y = WINDOW_HEIGHT / 2.0f;
   camera.camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
   camera.mouse_seen = true;

   //  Initialization was successfull.
   return true;

}  //  bool initialize(int argc, char* argv[], GLFWwindow** window)