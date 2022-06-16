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
* *  06 June 2022   P. D. Pattison    Initial Coding...                      * *
* *  11 June 2022   P. D. Pattison    Imported into Module Six.              * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


#ifndef __MODULE_FIVE_MILESTONE__TEXTURE_H__
#define __MODULE_FIVE_MILESTONE__TEXTURE_H__

//  System includes...

#include <cstdint>
#include <string>

//  Project includes...



//  Third party includes...




class Texture
{

public:

            Texture(std::string file_name);

   uint32_t getHandle();

   void     bind(uint32_t unit = 0);

private:

   uint32_t _handle;

};

#endif