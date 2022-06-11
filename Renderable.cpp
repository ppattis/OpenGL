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

//  System includes...

#include <fstream>
#include <sstream>

//  Project includes...

#include "Renderable.h"

//  Third party includes...




Renderable::Renderable()
{



}


Renderable::Renderable(std::string file_name)
{



}


void Renderable::loadFile(std::string file_name)
{

   //  First off, read the file into a vector of strings...
   std::vector<std::string> file;
   std::string              input_line;
   std::ifstream            input_file(file_name);

   if (input_file.is_open())
   {

      while (getline(input_file, input_line))
      {

         file.push_back(input_line);

      }  //  while (getline(input_file, input_line))

   }  //  if (input_file.is_open())
   else
   {

      throw "File Not Found.";

   }  //  else

   //  Now parse the file...


}


void Renderable::render()
{



}
