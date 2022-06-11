/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  createTexture.cpp                               * *
* *   Description         :  Function to read in an image file and link      * *
* *                          it to a texture.                                * *
* *                                                                          * *
* *                                                                          * *
* *************************************************************************  * *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  02 June 2022   P. D. Pattison    Initial Coding...                      * *
* *  05 June 2022   P. D. Pattison    Imported into the Module Five          * *
* *                                   Milestone baseline.                    * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...

#include <iostream>
#include <string>

//  Project includes...

#include "externals.h"
#include "graphics_includes.h"

//  Third party includes...



//  Global variable declarations...



//  Function   :  createTexture()
//  Parameters :  string filename, GLuint &textureId
//  Return     :  bool
//  Description:  Load an image file and generate a texture from it
bool createTexture(std::string file_name, GLuint& texture_id)
{

   std::cout << "Start of createTexture(" << file_name << ", " << texture_id << ")\n";


   //  Local variables...
   int            width;
   int            height;
   int            channels;
   std::cout << "Converting file name, and loading the image...\n";
   const char*    cstr_file_name = file_name.c_str();
   //const char* cstr_file_name = "not_a_file";
   unsigned char* image          = stbi_load(cstr_file_name, &width, &height, &channels, 0);

   std::cout << "file_name: " << file_name << " cstr_file_name: " << cstr_file_name << "\n";
   std::cout << "image height: " << height << " image width: " << width << " channels: " << channels << "\n";

   if (image)
   {

      std::cout << "Flipping the image vertically...\n";
      flipImageVertically(image, width, height, channels);
      std::cout << "Generating the texture ID...\n";
      glGenTextures(1, &texture_id);
      std::cout << "Binding the texture ID...\n";
      glBindTexture(GL_TEXTURE_2D, texture_id);

      //  Set the texture wrapping parameters...
      std::cout << "Setting the texture wrapping parameters...\n";
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      //  Set texture filtering parameters...
      std::cout << "Setting the texture filtering parameters...\n";
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


      if (channels == 3)
      {
         std::cout << "Linking the image to the texture...\n";
         glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

      }  //  if (channels == 3)
      else if (channels == 4)
      {

         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

      }  //  else if (channels == 4)
      else
      {

         std::cout << "Not implemented to handle an image with " << channels << " channels...\n";
         return false;

      }  //  else

      //  Generate the mipmap...
      std::cout << "Generating the mipmap...\n";
      glGenerateMipmap(GL_TEXTURE_2D);

      //  Free the temp memory used by the image...
      std::cout << "Freeing the image memory...\n";
      stbi_image_free(image);

      //  Unbind the texture...
      std::cout << "Unbinding the texture...\n";
      glBindTexture(GL_TEXTURE_2D, 0);

      std::cout << "End of createTexture(" << file_name << ", " << texture_id << ")\n";

      return true;

   }  //  if (image)

   return false;

}  //  bool createTexture(string file_name, GLuint& texture_id)
