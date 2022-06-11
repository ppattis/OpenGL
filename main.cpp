/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
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
* *  27 May  2022   P. D. Pattison    Modified for model_structure.          * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

#define STB_IMAGE_IMPLEMENTATION

//  System includes...
#include <iostream>

//  Project includes...
#include "externals.h"
#include "graphics_includes.h"

//  Third party includes...
#include <learnOpengl/camera.h>

//  Global variable declaration...
struct camera_structure camera;

//  Function   :  main()
//  Parameters :  int argc, char* argv[]
//  Return     :  int
//  Description:  Main entry point.
int main(int argc, char* argv[])
{
    
   //  Create the main window...
   GLFWwindow* window = nullptr;
   GLuint      program_id;

   //  Initialize OpenGL
   if (!initialize(argc, argv, &window))
   {

      //  Something bad happened, abort.
      return EXIT_FAILURE;

   }  //  if (!initialize(argc, argv, &window))

   //  Create and compile the shaders...
   if (!createShaderProgram("shaders/vertex.glsl", "shaders/fragment.glsl", program_id))
   {

      //  Something bad happened, abort.
      return EXIT_FAILURE;

   }  //  if (!createShaderProgram("shaders/vertex.glsl", "shaders/fragment.glsl", program_id))

   //  Create the mesh.
   std::vector<mesh_structure> pocket_watch;
   createMesh(pocket_watch, program_id);

   //  Set background color of the window to black (it will be implicitely
   //  used by glClear)
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

   //  Main render loop...
   mainRenderLoop(window, program_id, pocket_watch);

   //  Destroy assets...
   for (int index = 0; index < pocket_watch.size(); index++)
   {
      destroyMesh(pocket_watch[index]);

   }
   destroyShaderProgram(program_id);

   //  Terminate the program successfully...
   exit(EXIT_SUCCESS);

}  //  int main(int argc, char* argv[])

