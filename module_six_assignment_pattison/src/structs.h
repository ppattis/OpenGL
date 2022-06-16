/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  structs.h                                       * *
* *   Description         :  Definition of structs needed for the            * *
* *                          application                                     * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  11 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Cleanup and comment for turn in.       * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three.            * *
* *  28 May  2022   P. D. Pattison    Added a structure for camera controls. * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  28 May  2022   P. D. Pattison    Added x, y, and z for looking with the * *
* *                                   mouse and to zoom in and out.          * *
* *  28 May  2022   P. D. Pattison    Added mouse sensitivity.               * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


#ifndef __MODULE_FIVE_ASSIGNMENT__STRUCTS_H__
#define __MODULE_FIVE_ASSIGNMENT__STRUCTS_H__

//  System includes...

//  Project includes...
#include "graphics_includes.h"

//  Third party includes...
#include <learnOpengl/camera.h>



//  GLMesh struct to represent the OpenGL mesh.
struct GLMesh
{

   GLuint vao;            //  Handle for the Vertex Array Object
   GLuint vbos[2];        //  Handle for the Vertex Buffer Object array
   GLuint nIndices;       //  Number of vertices of the mesh
   GLuint texture_id;

};  //  struct GLMesh

//  Structure to store camera controls
struct camera_structure
{

   float  last_x;
   float  last_y;
   bool   mouse_seen;
   Camera camera;

};  //  struct camera_structure

#endif  //  __MODULE_FIVE_ASSIGNMENT__STRUCTS_H__