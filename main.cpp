/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
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
* *  ************   ***************   *************************************  * *
* *  10 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  11 May  2022   P. D. Pattison    Refactored to clean up main loop       * *
* *                                   into its own function.                 * *
* *  12 May  2022   P. D. Pattison    Clean up and comment for turn in.      * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three Assignment. * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *  03 June 2022   P. D. Pattison    Modified for using textures...         * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

#define STB_IMAGE_IMPLEMENTATION

//  System includes...
#include <iostream>
#include <string>

//  Project includes...
#include "externals.h"
#include "graphics_includes.h"
#include "Shader.h"
#include "structs.h"
#include "Texture.h"

//  Third party includes...
#include <learnOpengl/camera.h>


//  Global variable declarations...
struct camera_structure camera;
bool                    debug_mode = false;

//  Function   :  main()
//  Parameters :  int argc, char* argv[]
//  Return     :  int
//  Description:  Main entry point.
int main(int argc, char* argv[])
{
    
   //  Create the main window...
   GLFWwindow* window = nullptr;
   GLuint      program_id;
   std::string texture_file_name = "brick_wall.jpg";

   //  Initialize OpenGL
   if (!initialize(argc, argv, &window))
   {

      //  Something bad happened, abort.
      return EXIT_FAILURE;

   }  //  if (!initialize(argc, argv, &window))

   //  Create and compile the shaders...
   Shader shader = Shader();
   std::cout << "Shader handle -> " << shader.getHandle() << "\n";
   shader.load(GL_VERTEX_SHADER, "shaders/multiple_lights_vertex.glsl");
   shader.load(GL_FRAGMENT_SHADER, "shaders/multiple_lights_fragment.glsl");
   if (!shader.compile())
   {

      return EXIT_FAILURE;

   }

   //  Create the mesh.
   GLMesh mesh;
   createMesh(mesh);

   


   //  Create the texture...
   Texture     texture = Texture(texture_file_name);


   shader.set1Int("texture_uniform", 0);
   //  Set background color of the window to black (it will be implicitely
   //  used by glClear)
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

   //  Main render loop...
   mainRenderLoop(window, shader, mesh, texture);

   //  Destroy assets...
   destroyMesh(mesh);

   //  Terminate the program successfully...
   exit(EXIT_SUCCESS);

}  //  int main(int argc, char* argv[])

