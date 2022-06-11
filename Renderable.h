/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
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
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


#ifndef __MODULE_FIVE_MILESTONE__RENDERABLE_H__
#define __MODULE_FIVE_MILESTONE__RENDERABLE_H__

//  System includes...

#include <cstdint>
#include <string>
#include <vector>

//  Project includes...

#include "Texture.h"

//  Third party includes...




class Renderable
{

public:

   Renderable();
   Renderable(std::string file_name);


   void loadFile(std::string file_name);

   void render();

private:

   uint32_t                        _vao;
   std::vector<uint32_t>           _vbo;
   std::vector<std::vector<float>> _vertices;
   std::vector<std::vector<int>>   _indicies;
   std::vector<Texture>            _textures;


};

#endif  //  __MODULE_FIVE_MILESTONE__RENDERABLE_H__