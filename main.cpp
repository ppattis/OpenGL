/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Three Assignment                         * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  main.cpp                                        * *
* *   Description         :  Main applicaiton entry point.                   * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  *************  ****************  **************************************** *
* *   10 May 2022   P. D. Pattison    Initial Coding...                      * *
* *   11 May 2022   P. D. Pattison    Refactored to clean up main loop       * *
* *                                   into its own function.                 * *
* *   12 May 2022   P. D. Pattison    Clean up and comment for turn in.      * *
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
#include "externals.h"
#include "Mesh.h"
#include "pyramid.h"
#include "Shader.h"
#include "Transform.h"


//  Function   :  main()
//  Parameters :  int argc, char* argv[]
//  Return     :  int
//  Description:  Main entry point.
int main(int argc, char* argv[])
{

   //  Declare the mesh.
   Mesh* mesh = new Mesh();

   //  Initialize OpenGL
   if (!initialize(argc, argv, mesh))
   {

      //  Something bad happened, abort.
      return EXIT_FAILURE;

   }  //  if (!initialize(argc, argv, &window))

   mesh->initialize(vertices, indices);

   //  Declare and compile the shaders...
   std::cout << "Starting shader compiling and linking...\n";
   Shader* shader = new Shader("shaders/vertex.glsl", "shaders/fragment.glsl");
   if (!shader->compileAndLink())
   {

      //  Something bad happened, abort.
      return EXIT_FAILURE;

   }
   std::cout << "Shader compiling and linking done...\n";

   mesh->assignShader(shader);

   //  Set up transform
   Transform* transform = new Transform();
   transform->setView(glm::vec3(0.0f, -0.0f, -5.0f));
   transform->setRotation(15.0f, glm::vec3(1.0f, 1.0f, 1.0f));
   transform->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
   //transform->setTranslation(glm::vec3(0.0f, 0.0f, 0.0f));
   mesh->assignTransform(transform);

   //  Set background color of the window to black (it will be implicitely
   //  used by glClear)
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

   //  Main render loop...
   mainRenderLoop(mesh);

   //  Terminate the program successfully...
   exit(EXIT_SUCCESS);

}  //  int main(int argc, char* argv[])

