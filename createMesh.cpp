/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  createMesh.cpp                                  * *
* *   Description         :  Function to create a mesh.                      * *
* *                                                                          * *
* *                                                                          * *
* *************************************************************************  * *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  10 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Cleanup and comment for turn in.       * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three, modified   * *
* *                                   for 3D Pyramid.                        * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *  03 June 2022   P. D. Pattison    Modified for using textures...         * *
* *  11 June 2022   P. D. Pattison    Imported into Module Six.              * *
* *  12 June 2022   P. D. Pattison    Calculated and inputed the normals.    * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
*******************************************************************************/


//  System includes...
#include <iostream>

//  Project includes...
#include "consts.h"
#include "graphics_includes.h"
#include "structs.h"


//  Function   :  createMesh()
//  Parameters :  GLMesh &mesh
//  Return     :  void
//  Description:  Transfer vertices to the GPU
void createMesh(GLMesh& mesh)
{
   /*
   //  An array of values that represent points and colors for rendering triangles.
   //  Triangles are represented by the vertices (0, 1, 2) and (3, 1, 4)
   GLfloat verts[] =
   {
      
      // Vertex Positions                             Colors (r,g,b,a)                      Texture                     Normal
      // 
      //  Triangle 0
      -0.500000,  0.000000,  0.500000,   1.000000,  1.000000,  1.000000,  1.000000,   0.000000,  0.000000,   0.000000, -0.447214, -0.894427,  //  0 white
       0.000000,  1.000000,  0.000000,   1.000000,  1.000000,  1.000000,  1.000000,   0.500000,  1.000000,   0.000000, -0.447214, -0.894427,  //  1 white
       0.500000,  0.000000,  0.500000,   1.000000,  1.000000,  1.000000,  1.000000,   1.000000,  0.000000,   0.000000, -0.447214, -0.894427,  //  2 white
       //  Triangle 1
       0.500000,  0.000000,  0.500000,   1.000000,  1.000000,  1.000000,  1.000000,   0.000000,  0.000000,  -0.894427, -0.447214,  0.000000,  //  3 white
       0.000000,  1.000000,  0.000000,   1.000000,  1.000000,  1.000000,  1.000000,   0.500000,  1.000000,  -0.894427, -0.447214,  0.000000,  //  4 white
       0.500000,  0.000000, -0.500000,   1.000000,  1.000000,  1.000000,  1.000000,   1.000000,  0.000000,  -0.894427, -0.447214,  0.000000,  //  5 white
      //  Triangle 2
       0.500000,  0.000000, -0.500000,   1.000000,  0.000000,  0.000000,  1.000000,   0.000000,  0.000000,  -0.707107,  0.000000,  0.707107,  //  6 red
       0.000000,  1.000000,  0.000000,   1.000000,  0.000000,  0.000000,  1.000000,   0.500000,  1.000000,  -0.707107,  0.000000,  0.707107,  //  7 red
      -0.500000,  0.000000, -0.500000,   1.000000,  0.000000,  0.000000,  1.000000,   1.000000,  0.000000,  -0.707107,  0.000000,  0.707107,  //  8 red
      //  Triangle 3
      -0.500000,  0.000000, -0.500000,   0.000000,  1.000000,  0.000000,  1.000000,   0.000000,  0.000000,   0.894427, -0.447214,  0.000000,  //  9 green
       0.000000,  1.000000,  0.000000,   0.000000,  1.000000,  0.000000,  1.000000,   0.500000,  1.000000,   0.894427, -0.447214,  0.000000,  // 10 green
      -0.500000,  0.000000,  0.500000,   0.000000,  1.000000,  0.000000,  1.000000,   1.000000,  0.000000,   0.894427, -0.447214,  0.000000,  // 11 green
      //  Triangle 4
      -0.500000,  0.000000, -0.500000,   1.000000,  1.000000,  1.000000,  1.000000,   0.000000,  0.000000,   0.000000,  1.000000,  0.000000,  // 12 white
      -0.500000,  0.000000,  0.500000,   1.000000,  1.000000,  1.000000,  1.000000,   0.000000,  1.000000,   0.000000,  1.000000,  0.000000,  // 13 white
       0.500000,  0.000000,  0.500000,   1.000000,  1.000000,  1.000000,  1.000000,   1.000000,  1.000000,   0.000000,  1.000000,  0.000000,  // 14 white
      //  Triangle 5
      -0.500000,  0.000000, -0.500000,   1.000000,  1.000000,  1.000000,  1.000000,   0.000000,  0.000000,   0.000000,  1.000000,  0.000000,  // 15 white
       0.500000,  0.000000,  0.500000,   1.000000,  1.000000,  1.000000,  1.000000,   1.000000,  1.000000,   0.000000,  1.000000,  0.000000,  // 16 white
       0.500000,  0.000000, -0.500000,   1.000000,  1.000000,  1.000000,  1.000000,   1.000000,  0.000000,   0.000000,  1.000000,  0.000000  // 17 white
 
   };  //  GLfloat verts[]

   //  Assign vertices to triangles.
   GLushort indices[] = 
   { 
   
       0,  1,  2,
       3,  4,  5,
       6,  7,  8,
       9, 10, 11,
      12, 13, 14,
      15, 16, 17

   };  //  GLushort indices[]
   */

       GLfloat verts[] = {
         //Positions          //Normals
         // ------------------------------------------------------
         //Back Face          //Negative Z Normal  Texture Coords.
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

        //Front Face         //Positive Z Normal
       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,

       //Left Face          //Negative X Normal
      -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
      -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
      -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
      -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
      -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
      -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

      //Right Face         //Positive X Normal
      0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
      0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
      0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
      0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
      0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
      0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

      //Bottom Face        //Negative Y Normal
     -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
      0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
      0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
      0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
     -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
     -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

     //Top Face           //Positive Y Normal
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
 };


   //  Generate and bind the Vertex Array Object.
   glGenVertexArrays(1, &mesh.vao);
   glBindVertexArray(mesh.vao);

   //  Create first buffer.
   //glGenBuffers(2, mesh.vbos);
   glGenBuffers(1, &mesh.vbos[0]);
   glBindBuffer(GL_ARRAY_BUFFER, mesh.vbos[0]);
   glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
   //mesh.nIndices = sizeof(indices) / sizeof(indices[0]);
   mesh.nIndices = sizeof(verts) / (sizeof(verts[0]) * (VALUES_PER_VERTEX + VALUES_PER_NORMAL + VALUES_PER_TEXTURE));

   //  Create second buffer.
   //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.vbos[1]);
   //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

   //std::cout << "size of indices: " << sizeof(indices) << "\n";
   //  Offset into vertex array that represent a single triangle, (x, y, z, r, g, b, a).
   //GLint vertex_array_offset = sizeof(float) * (VALUES_PER_VERTEX + VALUES_PER_COLOR + VALUES_PER_TEXTURE + VALUES_PER_NORMAL);
   GLint vertex_array_offset = sizeof(float) * (VALUES_PER_VERTEX + VALUES_PER_NORMAL + VALUES_PER_TEXTURE);

   //  Instructs the GPU on how to handle the vertex buffer object data
   //  Build the attribPointerPosition for vertices...
   glVertexAttribPointer(0,
                         VALUES_PER_VERTEX, 
                         GL_FLOAT, 
                         GL_FALSE, 
                         vertex_array_offset, 
                         (void*)0);
   glEnableVertexAttribArray(0);


   //  Build the attribPointerPosition for textures...
   glVertexAttribPointer(1,
      VALUES_PER_NORMAL,
      GL_FLOAT,
      GL_FALSE,
      vertex_array_offset,
      (void*)(sizeof(float) * (VALUES_PER_VERTEX)));
   glEnableVertexAttribArray(1);

   //  Build the attribPointerPosition for normals...
   glVertexAttribPointer(2,
      VALUES_PER_TEXTURE,
      GL_FLOAT,
      GL_FALSE,
      vertex_array_offset,
      (void*)(sizeof(float) * (VALUES_PER_VERTEX + VALUES_PER_NORMAL)));
   glEnableVertexAttribArray(2);

}  //  void createMesh(GLMesh& mesh)