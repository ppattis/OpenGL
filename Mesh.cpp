/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Three Assignment                         * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  Shader.h                                        * *
* *   Description         :  Declaration of Shader class.                    * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  *************  ****************  **************************************** *
* *   23 May 2022   P. D. Pattison    Initial Coding...                      * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <sstream>
#include <string>

//  Project includes...

#include "consts.h"
#include "externals.h"
#include "Mesh.h"

Mesh::Mesh()
{


}


Mesh::~Mesh()
{

   glDeleteVertexArrays(1, &this->vertex_array);
   glDeleteBuffers(1, &this->vertex_buffer);
   glDeleteBuffers(1, &this->index_buffer);

}

void Mesh::initialize(std::vector<float> vertices, std::vector<int> indices)
{

   this->vertices = vertices;
   this->indices = indices;

   //  Set some standard values
   values_per_vertex = 3;
   values_per_color = 4;
   vertex_array_offset = sizeof(float) * (values_per_vertex + values_per_color);

   //  Generate and bind the Vertex Array Object
   glGenVertexArrays(1, &vertex_array);
   glBindVertexArray(vertex_array);

   //  Create vertices buffer
   glGenBuffers(1, &this->vertex_buffer);
   glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer);
   glBufferData(
      GL_ARRAY_BUFFER,
      this->vertices.size(),
      this->vertices.data(),
      GL_STATIC_DRAW
   );

   //  Create indices buffer
   glGenBuffers(1, &this->index_buffer);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->index_buffer);
   glBufferData(
      GL_ELEMENT_ARRAY_BUFFER,
      this->indices.size(),
      this->indices.data(),
      GL_STATIC_DRAW
   );

   glVertexAttribPointer(
      0,
      this->values_per_vertex,
      GL_FLOAT,
      GL_FALSE,
      this->vertex_array_offset,
      0
   );
   glEnableVertexAttribArray(0);

   glVertexAttribPointer(
      1,
      this->values_per_color,
      GL_FLOAT,
      GL_FALSE,
      this->vertex_array_offset,
      (char*)(sizeof(float) * this->values_per_vertex)
   );
   glEnableVertexAttribArray(1);

}


void Mesh::assignShader(Shader* shader)
{

   this->shader = shader;

}


void Mesh::assignTransform(Transform* trans)
{

   this->transform = trans;

}


void Mesh::assignWindow(struct GLFWwindow* window)
{

   this->window = window;

}


struct GLFWwindow* Mesh::getWindow()
{

   return this->window;

}



void Mesh::render()
{

   //  Clear the background
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   //  Set the shader to be used
   this->shader->activate(); 

   //  Retrieves and sends transform matrices to the vertex shader
   GLuint model_location = glGetUniformLocation(this->shader->getProgramId(), "model");
   GLuint view_location = glGetUniformLocation(this->shader->getProgramId(), "view");
   GLuint perspective_location = glGetUniformLocation(this->shader->getProgramId(), "projection");

   glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(this->transform->getModel()));
   glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(this->transform->getView()));
   glUniformMatrix4fv(perspective_location, 1, GL_FALSE, glm::value_ptr(this->transform->getPerspective()));

   //  Active the VBOs contained within the mesh's VAO
   glBindVertexArray(this->vertex_array);

   //  Draw the triangle.
   glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_SHORT, NULL);

   //  Deactivate the VAO
   glBindVertexArray(0);

   //  glfw:  swap buffers and poll IO events
   glfwSwapBuffers(this->window);

}
