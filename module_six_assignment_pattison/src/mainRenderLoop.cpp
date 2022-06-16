/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
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
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  28 May  2022   P. D. Pattison    Removed call to processInput due to    * *
* *                                   function becoming a callback.          * *
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...

//  Project includes...

#include "externals.h"
#include "graphics_includes.h"
#include "Shader.h"


//  Function   :  mainRenderLoop()
//  Parameters :  void
//  Return     :  void
//  Description:  Main rendering loop.
void mainRenderLoop(GLFWwindow* window, Shader shader, GLMesh mesh, Texture texture)
{

   //  Declare a variable to control the rotation.
   float rotate_index = 0.0f;

   //  "Game" loop.
   while (!glfwWindowShouldClose(window))
   {

      //  Get input...
      //processInput(window);

      //  Render the screen...
      render(mesh, shader, window, rotate_index, texture);

      //  Poll events.
      glfwPollEvents();

      rotate_index += 0.01f;
      if (rotate_index > 360.0f)
      {

         rotate_index = 0.0f;

      }  //  if (rotate_index > 360.0f)

   }  //  while (!glfwWindowShouldClose(window))

}  //  void mainRenderLoop(GLFWwindow* window, GLuint program_id, GLMesh mesh)