/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Three Assignment                         * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  Shader.cpp                                      * *
* *   Description         :  Definition of Shader class.                     * *
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

#include <iostream>

//  Project includes...

#include "externals.h"
#include "Shader.h"


Shader::Shader(std::string vector_file, std::string fragment_file)
{

   std::cout << "Shader constructor start...\n";
   this->program_id = glCreateProgram();
   this->vector_shader_source = readFile(vector_file);
   this->fragment_shader_source = readFile(fragment_file);

   //  Create the vertex and fragment shader objects.
   this->vertex_id = glCreateShader(GL_VERTEX_SHADER);
   this->fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
   std::cout << "Shader constructor end...\n";

}


Shader::~Shader()
{

   glDeleteProgram(this->program_id);
   glDeleteShader(this->vertex_id);
   glDeleteShader(this->fragment_id);

}


bool Shader::compileAndLink()
{

   std::cout << "Compile and link start...\n";
   //  c strings of the shader sources...
   std::cout << "Converting sources...\n";
   const char* vtx = this->vector_shader_source.c_str();
   const char* frg = this->fragment_shader_source.c_str();


   //  Compiliation and linkage error reporting
   int success = 0;
   char info_log[512];

   //  Store the shader sources for compilation.
   std::cout << "Store shader sources for compiliation...\n";
   glShaderSource(this->vertex_id, 1, &vtx, NULL);
   glShaderSource(this->fragment_id, 1, &frg, NULL);

   //  Compile vertex shader and check for any errors.
   std::cout << "Compile vertex shader...\n";
   glCompileShader(this->vertex_id);
   glGetShaderiv(this->vertex_id, GL_COMPILE_STATUS, &success);
   if (!success)
   {

      //  Error encountered, report it to stdout and abort.
      glGetShaderInfoLog(this->vertex_id, 512, NULL, info_log);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info_log << "\n";
      return false;

   }  //  if (!success)

   //  Compile fragment shader and check for any errors.
   std::cout << "Compile fragment shader...\n";
   glCompileShader(this->fragment_id);
   glGetShaderiv(this->fragment_id, GL_COMPILE_STATUS, &success);
   if (!success)
   {

      //  Error encountered, report it to stdout and abort.
      glGetShaderInfoLog(this->fragment_id, 512, NULL, info_log);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << info_log << "\n";
      return false;

   }  //  if (!success)

   // Attach compiled shaders to the shader program
   std::cout << "Attach compiled shaders...\n";
   glAttachShader(this->program_id, this->vertex_id);
   glAttachShader(this->program_id, this->fragment_id);

   //  Link shaders to program and check for any errors.
   std::cout << "Link shaders to program...\n";
   glLinkProgram(this->program_id);

   glGetProgramiv(this->program_id, GL_LINK_STATUS, &success);
   if (!success)
   {

      //  Error encountered, report it to stdout and abort.
      glGetProgramInfoLog(this->program_id, 512, NULL, info_log);
      std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info_log << "\n";
      return false;

   }  //  if (!success)
   std::cout << "Using the program...\n";
   glUseProgram(this->program_id);

   //  At this point everything worked, so return true so remainder of application can continue.
   return true;

}


void Shader::activate()
{

   glUseProgram(this->program_id);

}


unsigned int Shader::getProgramId()
{

   return this->program_id;

}