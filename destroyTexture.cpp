/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  destroyTexture.cpp                              * *
* *   Description         :  Remove the texture and free up the memory.      * *
* *                                                                          * *
* *                                                                          * *
* *                                                                          * *
* *************************************************************************  * *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  03 June 2022   P. D. Pattison    Initial Coding...                      * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five Milestone    * *
* *                                   baseline.                              * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...

//  Project includes..
#include "graphics_includes.h"

//  Function   :  destroyShaderProgram()
//  Parameters :  GLuint program_id
//  Return     :  void
//  Description:  Destroy the shaders...
void destroyTexture(GLuint texture_id)
{

   glGenTextures(1, &texture_id);

}  //  void destroyShaderProgram(GLuint texture_id)