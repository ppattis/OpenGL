/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Six Assignment                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  basic_fragment.glsl                             * *
* *   Description         :  Basic Fragment shader source code.              * *
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

//  Version declaration.
#version 330 core

//  Shader output declaration.
out vec4 fragment_color;

//  Main shader function.
void main()
{

   //  Pass the input color to the output.
   fragment_color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
   

}  //  void main()