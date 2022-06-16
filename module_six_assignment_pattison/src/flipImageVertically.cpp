/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  flipImageVertically.cpp                         * *
* *   Description         :  Function to flip an image vertically because    * *
* *                          images are loaded with y-axis increasing up     * *
* *                          however openGL y-axi
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  02 June 2022   P. D. Pattison    Initial Coding...                      * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...



//  Project includes...

#include "graphics_includes.h"

//  Third party includes...



//  Global variable declarations...



//  Function   :  flipImageVertically()
//  Parameters :  unsigned char* image, int width, int height, int channels
//  Return     :  void
//  Description:  Flip an image vertically
void flipImageVertically(unsigned char* image, int width, int height, int channels)
{

   for (int j = 0; j < height / 2; ++j)
   {

      int index_one = j * width * channels;
      int index_two = (height - 1 - j) * width * channels;

      for (int i = width * channels; i > 0; --i)
      {

         unsigned char temp = image[index_one];
         image[index_one] = image[index_two];
         image[index_two] = temp;
         ++index_one;
         ++index_two;

      }  //  for (int i = width * channels; i > 0; --i)

   }  //  for (int j = 0; j < height / 2; ++j)

}  //  bool createTexture(string file_name, GLuint& texture_id)
