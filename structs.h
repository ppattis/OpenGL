/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
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
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  28 May  2022   P. D. Pattison    Added camera_structure to control the  * *
* *                                   camera for the scene.                  * *
* *  29 May  2022   P. D. Pattison    Added to camera_structure to keep      * *
* *                                   track of which projection should be    * *
* *                                   used.                                  * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *  07 June 2022   P. D. Pattison    Added texture information to the       * *
* *                                   renderable_structure struct.           * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


#ifndef __MODULE_TWO_ASSIGNMENT__STRUCTS_H__
#define __MODULE_TWO_ASSIGNMENT__STRUCTS_H__

//  System includes...


//  Project includes...
#include "graphics_includes.h"

//  Third Party includes...
#include <learnOpengl/camera.h>


//  mesh_structure struct to represent the OpenGL mesh.
struct mesh_structure
{

   GLuint vertex_array;   //  Handle for the surface Vertex Array Object
   GLuint vertex_buffer;  //  Handle for the vertex Buffer Object
   GLuint index_buffer;   //  Handle for the indices Buffer Object.
   GLuint number_indices; //  Number of vertices of the mesh
   GLuint texture_id;
   int    texture_offset;

};  //  struct GLMesh

//  struct to represent a whole model
struct renderable_structure
{

   struct mesh_structure surface;
   struct mesh_structure outline;
   GLuint                texture_id;
   int                   texture_offset;

};  //  struct renderable_structure

//  Structure to store camera controls
struct camera_structure
{

   float     last_x;
   float     last_y;
   bool      mouse_seen;
   Camera    camera;
   int       current_projection;

};  //  struct camera_structure

#endif  //  __MODULE_TWO_ASSIGNMENT__STRUCTS_H__