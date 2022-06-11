/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  mainRenderLoop.cpp                              * *
* *   Description         :  Main "Game Loop".                               * *
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
* *  27 May  2022   P. D. Pattison    Imported into Module Three, and added  * *
* *                                   a mechanism to slowly rotate the       * *
* *                                   pyramid to make viewing it easier.     * *
* *  27 May  2022   P. D. Pattison    Imported into Module THree 3D Scene    * *
* *                                   assignment.  Removed the rotation.     * *
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


//  Function   :  mainRenderLoop()
//  Parameters :  void
//  Return     :  void
//  Description:  Main rendering loop.
void mainRenderLoop(GLFWwindow* window, GLuint program_id, std::vector<mesh_structure> renderable)
{

    //  "Game" loop.
   while (!glfwWindowShouldClose(window))
   {

      //  Enable z-depth
      glEnable(GL_DEPTH_TEST);

      //  Clear the background
      glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      //  Render the screen...
      render(renderable, program_id, window);

      //  glfw:  swap buffers and poll IO events
      glfwSwapBuffers(window);

      //  Poll events.
      glfwPollEvents();


   }  //  while (!glfwWindowShouldClose(window))

}  //  void mainRenderLoop(GLFWwindow* window, GLuint program_id, GLMesh mesh)