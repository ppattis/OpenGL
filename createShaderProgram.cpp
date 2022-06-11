/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  createShaderProgram.cpp                         * *
* *   Description         :  Read in shader program sources, compile them,   * *
* *                          and link them into the application.             * *
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
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

//  System includes...
#include <GL/glew.h>
#include <iostream>

//  Project includes...
#include "externals.h"

/*Shader program Macro*/



//  Function   :  createShaderProgram()
//  Parameters :  std::string vtx_source_file_name,
//                std::string frag_source_file_name,
//                GLuint &program_id
//  Return     :  bool
//  Description:  Read in and compile the shaders...
bool createShaderProgram(
   std::string vtx_source_file_name, 
   std::string frag_source_file_name, 
   GLuint& program_id )
{

   //  Temporary shader programs...
   
   /* Vertex Shader Source Code*/
   
   //  Compiliation and linkage error reporting
   int success = 0;
   char info_log[512];

   //  Create a shader program object...
   program_id = glCreateProgram();

   //  Create the vertex and fragment shader objects.
   GLuint vertex_shader_id        = glCreateShader(GL_VERTEX_SHADER);
   GLuint fragment_shader_id      = glCreateShader(GL_FRAGMENT_SHADER);

   //  Retrive the shader source...
   std::string vtx_source_string  = readFile(vtx_source_file_name);
   std::string frag_source_string = readFile(frag_source_file_name);
   const char* vtx_source_c_str   = vtx_source_string.c_str();
   const char* frag_source_c_str  = frag_source_string.c_str();

   //  Store the shader sources for compilation.
   glShaderSource(vertex_shader_id, 1, &vtx_source_c_str, NULL);
   glShaderSource(fragment_shader_id, 1, &frag_source_c_str, NULL);

   //  Compile vertex shader and check for any errors.
   glCompileShader(vertex_shader_id);
   glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &success);
   if (!success)
   {

      //  Error encountered, report it to stdout and abort.
      glGetShaderInfoLog(vertex_shader_id, 512, NULL, info_log);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info_log << "\n";
      return false;

   }  //  if (!success)

   //  Compile fragment shader and check for any errors.
   glCompileShader(fragment_shader_id);
   glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &success);
   if (!success)
   {

      //  Error encountered, report it to stdout and abort.
      glGetShaderInfoLog(fragment_shader_id, 512, NULL, info_log);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << info_log << "\n";
      return false;

   }  //  if (!success)

   // Attach compiled shaders to the shader program
   glAttachShader(program_id, vertex_shader_id);
   glAttachShader(program_id, fragment_shader_id);

   //  Link shaders to program and check for any errors.
   glLinkProgram(program_id);
   glGetShaderiv(program_id, GL_LINK_STATUS, &success);
   if (!success)
   {

      //  Error encountered, report it to stdout and abort.
      glGetProgramInfoLog(program_id, 512, NULL, info_log);
      std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info_log << "\n";
      return false;

   }  //  if (!success)
   glUseProgram(program_id);

   //  At this point everything worked, so return true so remainder of application can continue.
   return true;

}  //  bool createShaderProgram