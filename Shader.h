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

#ifndef __MODULE_THREE_ASSIGNMENT__SHADER_H__
#define __MODULE_THREE_ASSIGNMENT__SHADER_H__

//  System includes...
#include <GL/glew.h>
#include <string>


//  Project includes...


class Shader
{

   public:

           Shader(std::string vector_file, std::string fragment_file);
           ~Shader();
      bool compileAndLink();
      void activate();

      unsigned int getProgramId();

   private:

      unsigned int program_id;
      unsigned int vertex_id;
      unsigned int fragment_id;
      std::string  vector_shader_source;
      std::string  fragment_shader_source;

};


#endif