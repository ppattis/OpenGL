/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Three Assignment                         * *
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

//  Project includes...
#include "externals.h"
#include "Mesh.h"


//  Function   :  mainRenderLoop()
//  Parameters :  void
//  Return     :  void
//  Description:  Main rendering loop.
void mainRenderLoop(Mesh* mesh)
{

   //  "Game" loop.
   while (!glfwWindowShouldClose(mesh->getWindow()))
   {

      //  Get input...
      processInput(mesh);

      //  Render the screen...
      mesh->render();

      //  Poll events.
      glfwPollEvents();

   }  //  while (!glfwWindowShouldClose(window))

}  //  void mainRenderLoop(GLFWwindow* window, GLuint program_id, GLMesh mesh)