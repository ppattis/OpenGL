/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Six Assignment                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  vertex.glsl                                     * *
* *   Description         :  Vertex shader source code.                      * *
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
* *  27 May  2022   P. D. Pattison    Imported into Module Three.  Modified  * *
* *                                   for 3D rendering.                      * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *  02 June 2022   P. D. Pattison    Modified to use textures.  Changed the * *
* *                                   layout qualifiers, the output variable * *
* *                                   type and name, removed the uniforms    * *
* *                                   also changed main function to pass     * *
* *                                   texture coordinates instead of color.  * *
* *  11 June 2022   P. D. Pattison    Imported into Module Six.              * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

//  Version declaration
#version 440 core

//  Layout qualifiers
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texture;

//  Output declaration.
out vec2 vertex_texture_coordinate;
out vec3 vertex_normal_coordinate;
out vec3 vertex_fragment_coordinate;

//  Uniforms for 3D
uniform mat4 model_uniform;
uniform mat4 view_uniform;
uniform mat4 projection_uniform;

//  Main shader function.
void main()
{

   //  Pass out the fragment position
   vertex_fragment_coordinate = vec3(model_uniform * vec4(position, 1.0f));

   //  Pass out the normal
   vertex_normal_coordinate = mat3(transpose(inverse(model_uniform))) * normal;

   //  Pass out the color of the current vertex.
   vertex_texture_coordinate = texture;

   //  Get the position of the current vertex
   gl_Position = projection_uniform * view_uniform * model_uniform * vec4(position, 1.0f);


}  //  void main()