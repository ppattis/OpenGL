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

#ifndef __MODULE_THREE_ASSIGNMENT__MESH_H__
#define __MODULE_THREE_ASSIGNMENT__MESH_H__

//  System includes...
#include <GL/glew.h>
#include <vector>


//  Project includes...

#include "Shader.h"
#include "Transform.h"

class Mesh
{

public:

                      Mesh();
                      ~Mesh();
   void               initialize(std::vector<float> vertices, std::vector<int> indices);
   void               assignShader(Shader* shader);
   void               assignTransform(Transform* transform);
   void               assignWindow(struct GLFWwindow* window);
   struct GLFWwindow* getWindow();
   void               render();
                      
private:              
                      
   unsigned int       vertex_array;
   unsigned int       vertex_buffer;
   unsigned int       index_buffer;
   Shader*            shader;
   Transform*         transform;
   std::vector<float> vertices;
   std::vector<float> colors;
   std::vector<int>   indices;
   int                vertex_array_offset;
   int                values_per_vertex;
   int                values_per_color;
   struct GLFWwindow* window;
};


#endif  //  __MODULE_THREE_ASSIGNMENT__MESH_H__