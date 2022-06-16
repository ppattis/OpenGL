/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Six Assignment                           * *
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
* *  ************   ***************   *************************************  * *
* *  13 June 2022   P. D. Pattison    Initial Coding...                      * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

//  Project includes...

#include "graphics_includes.h"
#include "Shader.h"

//  Third party includes...




Shader::Shader()
{

   _handle = glCreateProgram();

}


Shader::~Shader()
{

   if (_handle)
   {

      glDeleteProgram(_handle);

   }

}


void Shader::load(GLenum type, std::string filename)
{

   std::string source = readFile(filename);
   _shader_sources.push_back(source);
   _shader_types.push_back(type);

}


int32_t Shader::compile()
{

   int32_t  ret_value = 0;
   std::cout << "Verification of shader components integrity.\n";
   if ((_shader_sources.size() != _shader_types.size()) && (_shader_types.size() != _shader_handles.size()))
   {

      std::cout << "Error in loaded shaders!\n";
      return ret_value;

   }
   std::wcout << "Compiling and attatching shaders.\n";
   for (int index = 0; index < _shader_sources.size(); index++)
   {

      std::cout << "Creating shader...\n";
      uint32_t shader = glCreateShader(_shader_types[index]);
      std::cout << "Converting shader source...\n";
      const char* cstr = _shader_sources[index].c_str();
      std::wcout << "Sending shader source to GPU...\n";
      glShaderSource(shader, 1, &cstr, NULL);
      std::wcout << "Compiling shader...\n";
      glCompileShader(shader);
      std::wcout << "Checking for compiliation errors...\n";
      glGetShaderiv(shader, GL_COMPILE_STATUS, &ret_value);
      if (!ret_value)
      {

         char info_log[512];
         glGetShaderInfoLog(shader, 512, NULL, info_log);
         std::cout << "ERROR::SHADER::";
         switch (shader)
         {

         case GL_VERTEX_SHADER:
            std::cout << "VERTEX::";
            break;
         case GL_FRAGMENT_SHADER:
            std::cout << "FRAGMENT::";
            break;
         case GL_GEOMETRY_SHADER:
            std::cout << "GEOMETRY::";
            break;

         }
         std::cout << "COMPILATION_FAILED\n" << info_log << "\n";
         return ret_value;

      }
      std::wcout << "Attaching shader...\n";
      glAttachShader(_handle, shader);
      _shader_handles.push_back(shader);

   }
   std::wcout << "Linking shader program.\n";
   glLinkProgram(_handle);
   glGetShaderiv(_handle, GL_LINK_STATUS, &ret_value);
   if (ret_value)
   {

      bind();
      for (uint32_t shader : _shader_handles)
      {

         glDeleteShader(shader);

      }

   }
   else
   {

      //  Error encountered, report it to stdout and abort.
      char info_log[512];
      glGetProgramInfoLog(_handle, 512, NULL, info_log);
      std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info_log << "\n";

   }


   return ret_value;

}


void Shader::bind()
{

   glUseProgram(_handle);

}


void Shader::unbind()
{

   glUseProgram(0);

}


void Shader::set1Float(std::string name, float value)
{

   glUniform1f(getUniform(name), value);

}


void Shader::set2Float(std::string name, float value_one, float value_two)
{

   glUniform2f(getUniform(name), value_one, value_two);

}


void Shader::set3Float(std::string name, float value_one, float value_two, float value_three)
{

   glUniform3f(getUniform(name), value_one, value_two, value_three);

}


void Shader::set4Float(std::string name, float value_one, float value_two, float value_three, float value_four)
{

   glUniform4f(getUniform(name), value_one, value_two, value_three, value_four);

}


void Shader::set1Int(std::string name, int32_t value)
{

   glUniform1i(getUniform(name), value);

}


void Shader::set2Int(std::string name, int32_t value_one, int32_t value_two)
{

   glUniform2i(getUniform(name), value_one, value_two);

}


void Shader::set3Int(std::string name, int32_t value_one, int32_t value_two, int32_t value_three)
{

   glUniform3i(getUniform(name), value_one, value_two, value_three);

}


void Shader::set4Int(std::string name, int32_t value_one, int32_t value_two, int32_t value_three, int32_t value_four)
{

   glUniform4i(getUniform(name), value_one, value_two, value_three, value_four);

}

void Shader::setVec2(std::string name, glm::vec2 value)
{

   set2Float(name, value[0], value[1]);

}


void Shader::setVec3(std::string name, glm::vec3 value)
{

   set3Float(name, value[0], value[1], value[2]);

}


void Shader::setVec4(std::string name, glm::vec4 value)
{

   set4Float(name, value[0], value[1], value[2], value[3]);

}


void Shader::setMat2(std::string name, glm::mat2 value)
{

   glUniformMatrix2fv(getUniform(name), 1, GL_FALSE, glm::value_ptr(value));

}


void Shader::setMat3(std::string name, glm::mat3 value)
{

   glUniformMatrix3fv(getUniform(name), 1, GL_FALSE, glm::value_ptr(value));

}


void Shader::setMat4(std::string name, glm::mat4 value)
{

   glUniformMatrix4fv(getUniform(name), 1, GL_FALSE, glm::value_ptr(value));

}


int32_t Shader::getUniform(std::string name)
{

   if (_uniform_locations.find(name) == _uniform_locations.end())
   {

      _uniform_locations[name] = glGetUniformLocation(_handle, name.c_str());

   }

   return _uniform_locations[name];

}


uint32_t Shader::getHandle()
{

   return _handle;

}


std::string Shader::readFile(std::string filename)
{

   //  Create std::stringstream to create the std::string return.
   std::stringstream input_buffer;

   //  Create std::fstream to read in the text file.
   std::ifstream input_file(filename);
   input_buffer << input_file.rdbuf();

   //  Return the std::string representation of the text file.
   return input_buffer.str();

}
