/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Six Assignment                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  Texture.h                                       * *
* *   Description         :  Definition of Texture class.                    * *
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


#ifndef __MODULE_SIX_MILESTONE__SHADER_H__
#define __MODULE_SIX_MILESTONE__SHADER_H__

//  System includes...

#include <cstdint>
#include <map>
#include <string>
#include <vector>

//  Project includes...



//  Third party includes...




class Shader
{

   public:

                                     Shader();
                                     ~Shader();
                                     
      void                           load(GLenum type, std::string filename);
      int32_t                        compile();
      void                           bind();
      void                           unbind();

      //  class methods to handle uniforms...
      void                           set1Float(std::string name, float value);
      void                           set2Float(std::string name, float value_one, float value_two);
      void                           set3Float(std::string name, float value_one, float value_two, float value_three);
      void                           set4Float(std::string name, float value_one, float value_two, float value_three, float value_four);

      void                           set1Int(std::string name, int32_t value);
      void                           set2Int(std::string name, int32_t value_one, int32_t value_two);
      void                           set3Int(std::string name, int32_t value_one, int32_t value_two, int32_t value_three);
      void                           set4Int(std::string name, int32_t value_one, int32_t value_two, int32_t value_three, int32_t value_four);

      void                           setVec2(std::string name, glm::vec2 value);
      void                           setVec3(std::string name, glm::vec3 value);
      void                           setVec4(std::string name, glm::vec4 value);

      void                           setMat2(std::string name, glm::mat2 value);
      void                           setMat3(std::string name, glm::mat3 value);
      void                           setMat4(std::string name, glm::mat4 value);

      uint32_t                       getHandle();

   private:

      int32_t                        getUniform(std::string name);
      std::string                    readFile(std::string filename);
      std::map<std::string, int32_t> _uniform_locations;
      uint32_t                       _handle;
      std::vector<std::string>       _shader_sources;
      std::vector<GLenum>            _shader_types;
      std::vector<uint32_t>          _shader_handles;

};

#endif  //  __MODULE_SIX_MILESTONE__SHADER_H__