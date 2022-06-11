/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  Texture.cpp                                     * *
* *   Description         :  Declaration of Texture class.                   * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  06 June 2022   P. D. Pattison    Initial Coding...                      * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

//  System includes...

#include <new>

//  Project includes...

#include "graphics_includes.h"
#include "Texture.h"

//  Third party includes...




Texture::Texture(std::string file_name, uint32_t unit)
{

   const char*    cstr_file_name = file_name.c_str();
   int            width;
   int            height;
   int            channels;
   unsigned char* data           = stbi_load(cstr_file_name, &width, &height, &channels, 0);

   this->_unit = unit;

   if (data)
   {

      //  First off flip the image vertically...
      for (int y = 0; y < height / 2; y++)
      {

         int index_one = y * width * channels;
         int index_two = (height - 1 - y) * width * channels;

         for (int x = width * channels; x > 0; --x)
         {

            unsigned char temp = data[index_one];
            data[index_one] = data[index_two];
            data[index_two] = temp;
            ++index_one;
            ++index_two;

         }  //  for (int x = width * channels; x > 0; --x)

      }  //  for (int y = 0; y < height / 2; y++)
      //  Create the texture handle...
      glGenTextures(1, &_handle);
      glBindTexture(GL_TEXTURE_2D, _handle);
      //  Set the texture wrapping parameters...
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      //  Set texture filtering parameters...
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      
      if (channels == 3)
      {

         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

      }  //  if (channels == 3)
      else if (channels == 4)
      {

         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

      }  //  else if (channels == 4)
      else
      {

         throw "Image format not supported.";

      }  //  else

      //  Generate the mipmap...
      glGenerateMipmap(GL_TEXTURE_2D);

      //  Free the temp memory used by the image...
      stbi_image_free(data);

      //  Unbind the texture...
      glBindTexture(GL_TEXTURE_2D, 0);

   }

}


uint32_t Texture::getHandle()
{

   return _handle;

}


void Texture::bind()
{

   glActiveTexture(GL_TEXTURE0 + this->_unit);
   glBindTexture(GL_TEXTURE_2D, this->_handle);

}

