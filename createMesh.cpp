/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  createMesh.cpp                                  * *
* *   Description         :  Function to create a mesh.                      * *
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
* *  27 May  2022   P. D. Pattison    Imported into Module Three, modified   * *
* *                                   for 3D Pyramid.                        * *
* *  27 May  2022   P. D. Pattison    Modified code to have a model          * *
* *                                   consisting of a surface mesh and an    * *
* *                                   outline mesh.                          * *
* *  29 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
*******************************************************************************/


//  System includes...
#include <iostream>

//  Project includes...
#include "consts.h"
#include "externals.h"
#include "graphics_includes.h"
#include "models.h"
#include "structs.h"


//  Function   :  createMesh()
//  Parameters :  GLMesh &mesh
//  Return     :  void
//  Description:  Transfer vertices to the GPU
void createMesh(std::vector<mesh_structure>& model, GLuint program_id)
{

   GLint surface_array_offset = sizeof(float) * (VALUES_PER_VERTEX + VALUES_PER_COLOR + VALUES_PER_TEXTURE);
   
   //  Top of Bottom of Watch Box
   //  Offset into vertex array that represent a single triangle, (x, y, z, r, g, b, a).
   struct mesh_structure wb_bottom_top;

   //  Generate and bind the Vertex Array Objects.
   glGenVertexArrays(1, &wb_bottom_top.vertex_array);
   glBindVertexArray(wb_bottom_top.vertex_array);

   //  Create surface vertex buffer...
   glGenBuffers(1, &wb_bottom_top.vertex_buffer);
   glBindBuffer(GL_ARRAY_BUFFER, wb_bottom_top.vertex_buffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(wb_bottom_top_vertices), wb_bottom_top_vertices, GL_STATIC_DRAW);

   //  Create surface index buffer...
   glGenBuffers(1, &wb_bottom_top.index_buffer);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, wb_bottom_top.index_buffer);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(wb_bottom_top_indices), wb_bottom_top_indices, GL_STATIC_DRAW);
   
   //  Calculate number of indices
   wb_bottom_top.number_indices = sizeof(wb_bottom_top_indices) / sizeof(wb_bottom_top_indices[0]);
   
   //  Initialize texture...
   if (!createTexture(wb_bottom_top_texture, wb_bottom_top.texture_id))
   {

      std::cout << "Failed to load texture " << wb_bottom_top_texture << "\n";

   }
   wb_bottom_top.texture_offset = 0;
   model.push_back(wb_bottom_top);

   
   
   //  Bottom of Bottom of Watch Box
   //  Offset into vertex array that represent a single triangle, (x, y, z, r, g, b, a).
   struct mesh_structure wb_bottom_bottom;

   //  Generate and bind the Vertex Array Objects.
   glGenVertexArrays(1, &wb_bottom_bottom.vertex_array);
   glBindVertexArray(wb_bottom_bottom.vertex_array);

   //  Create surface vertex buffer...
   glGenBuffers(1, &wb_bottom_bottom.vertex_buffer);
   glBindBuffer(GL_ARRAY_BUFFER, wb_bottom_bottom.vertex_buffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(wb_bottom_top_vertices), wb_bottom_top_vertices, GL_STATIC_DRAW);

   //  Create surface index buffer...
   glGenBuffers(1, &wb_bottom_bottom.index_buffer);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, wb_bottom_bottom.index_buffer);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(wb_bottom_bottom_indices), wb_bottom_bottom_indices, GL_STATIC_DRAW);

   //  Calculate number of indices
   wb_bottom_bottom.number_indices = sizeof(wb_bottom_bottom_indices) / sizeof(wb_bottom_bottom_indices[0]);

   //  Initialize texture...
   if (!createTexture(wb_bottom_bottom_texture, wb_bottom_bottom.texture_id))
   {

      std::cout << "Failed to load texture " << wb_bottom_bottom_texture << "\n";

   }
   wb_bottom_bottom.texture_offset = 1;
   model.push_back(wb_bottom_bottom);
   
   //  Inside of Top of Watch Box
   //  Offset into vertex array that represent a single triangle, (x, y, z, r, g, b, a).
   struct mesh_structure wb_lid_inside;

   //  Generate and bind the Vertex Array Objects.
   glGenVertexArrays(1, &wb_lid_inside.vertex_array);
   glBindVertexArray(wb_lid_inside.vertex_array);

   //  Create surface vertex buffer...
   glGenBuffers(1, &wb_lid_inside.vertex_buffer);
   glBindBuffer(GL_ARRAY_BUFFER, wb_lid_inside.vertex_buffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(wb_lid_inside_vertices), wb_lid_inside_vertices, GL_STATIC_DRAW);

   //  Create surface index buffer...
   glGenBuffers(1, &wb_lid_inside.index_buffer);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, wb_lid_inside.index_buffer);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(wb_lid_inside_indices), wb_lid_inside_indices, GL_STATIC_DRAW);

   //  Calculate number of indices
   wb_lid_inside.number_indices = sizeof(wb_lid_inside_indices) / sizeof(wb_lid_inside_indices[0]);

   //  Initialize texture...
   if (!createTexture(wb_lid_inside_texture, wb_lid_inside.texture_id))
   {

      std::cout << "Failed to load texture " << wb_lid_inside_texture << "\n";

   }
   wb_lid_inside.texture_offset = 2;
   model.push_back(wb_lid_inside);
   
   //  Outside of Lid of Watch Box
   //  Offset into vertex array that represent a single triangle, (x, y, z, r, g, b, a).
   struct mesh_structure wb_lid_outside;

   //  Generate and bind the Vertex Array Objects.
   glGenVertexArrays(1, &wb_lid_outside.vertex_array);
   glBindVertexArray(wb_lid_outside.vertex_array);

   //  Create surface vertex buffer...
   glGenBuffers(1, &wb_lid_outside.vertex_buffer);
   glBindBuffer(GL_ARRAY_BUFFER, wb_lid_outside.vertex_buffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(wb_lid_outside_vertices), wb_lid_outside_vertices, GL_STATIC_DRAW);

   //  Create surface index buffer...
   glGenBuffers(1, &wb_lid_outside.index_buffer);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, wb_lid_outside.index_buffer);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(wb_lid_outside_indices), wb_lid_outside_indices, GL_STATIC_DRAW);

   //  Calculate number of indices
   wb_lid_outside.number_indices = sizeof(wb_lid_outside_indices) / sizeof(wb_lid_outside_indices[0]);

   //  Initialize texture...
   if (!createTexture(wb_lid_outside_texture, wb_lid_outside.texture_id))
   {

      std::cout << "Failed to load texture " << wb_lid_outside_texture << "\n";

   }
   wb_lid_outside.texture_offset = 3;
   model.push_back(wb_lid_outside);

   //  Box Edges of Watch Box
   //  Offset into vertex array that represent a single triangle, (x, y, z, r, g, b, a).
   struct mesh_structure wb_box_edges;

   //  Generate and bind the Vertex Array Objects.
   glGenVertexArrays(1, &wb_box_edges.vertex_array);
   glBindVertexArray(wb_box_edges.vertex_array);

   //  Create surface vertex buffer...
   glGenBuffers(1, &wb_box_edges.vertex_buffer);
   glBindBuffer(GL_ARRAY_BUFFER, wb_box_edges.vertex_buffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(wb_box_edges_vertices), wb_box_edges_vertices, GL_STATIC_DRAW);

   //  Create surface index buffer...
   glGenBuffers(1, &wb_box_edges.index_buffer);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, wb_box_edges.index_buffer);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(wb_box_edges_indices), wb_box_edges_indices, GL_STATIC_DRAW);

   //  Calculate number of indices
   wb_box_edges.number_indices = sizeof(wb_box_edges_indices) / sizeof(wb_box_edges_indices[0]);

   //  Initialize texture...
   if (!createTexture(wb_box_edges_texture, wb_box_edges.texture_id))
   {

      std::cout << "Failed to load texture " << wb_box_edges_texture << "\n";

   }
   wb_box_edges.texture_offset = 4;
   model.push_back(wb_box_edges);
   




   glUseProgram(program_id);
   glUniform1i(glGetUniformLocation(program_id, "texture_uniform"), 0);

   //  Instructs the GPU on how to handle the vertex buffer object data
   glVertexAttribPointer(0,
      VALUES_PER_VERTEX,
      GL_FLOAT,
      GL_FALSE,
      surface_array_offset,
      0);
   glEnableVertexAttribArray(0);

   // Build the attribPointerPosition
   glVertexAttribPointer(1,
      VALUES_PER_COLOR,
      GL_FLOAT,
      GL_FALSE,
      surface_array_offset,
      (void*)(sizeof(float) * VALUES_PER_VERTEX));
   glEnableVertexAttribArray(1);

   //  Build the attribPointerPosition for textures...
   glVertexAttribPointer(2,
      VALUES_PER_TEXTURE,
      GL_FLOAT,
      GL_FALSE,
      surface_array_offset,
      (void*)(sizeof(float) * (VALUES_PER_VERTEX + VALUES_PER_COLOR)));
   glEnableVertexAttribArray(2);



}  //  void createMesh(GLMesh& mesh)