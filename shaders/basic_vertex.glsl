/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Six Assignment                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  basic_vertex.glsl                               * *
* *   Description         :  Basic vertex shader source code.                * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  10 May  2022   P. D. Pattison    Initial Coding...                      * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

//  Version declaration
#version 330 core

//  Layout qualifiers
layout (location = 0) in vec3 position;


//  Main shader function.
void main()
{
   //  Get the position of the current vertex
   gl_Position = vec4(position, 1.0f);


}  //  void main()