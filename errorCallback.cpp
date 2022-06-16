/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  createMesh.cpp                                  * *
* *   Description         :  Function to create a mesh.                      * *
* *                                                                          * *
* *                                                                          * *
* *************************************************************************  * *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  25 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
*******************************************************************************/


//  System includes...
#include <iostream>

//  Project includes...
#include "consts.h"
#include "graphics_includes.h"
#include "structs.h"


//  Function   :  errorCallback()
//  Parameters :  GLenum        source,
//                GLenum        type,
//                GLuint        id,
//                GLenum        serverity,
//                GLsizei       length,
//                const GLchar* message,
//                const void*   userParam
//  Return     :  void
//  Description:  Callback for the GPU to report problems with OpenGL
void GLAPIENTRY errorCallback(GLenum source,
                              GLenum type,
                              GLuint id,
                              GLenum severity,
                              GLsizei length,
                              const GLchar* message,
                              const void* userParam)
{

   fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
           type, severity, message);

}  //  void GLAPIENTRY errorCallback

