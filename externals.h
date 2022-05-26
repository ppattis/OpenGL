/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module THree Assignment                         * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  externals.h                                     * *
* *   Description         :  Forward declaration of functions used           * *
* *                          throughout the application.                     * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  *************  ****************  **************************************** *
* *   10 May 2022   P. D. Pattison    Initial Coding...                      * *
* *   12 May 2022   P. D. Pattison    Cleanup and comment for turn in.       * *
* *   17 May 2022   P. D. Pattison    Imported into module three.            * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
*******************************************************************************/


#ifndef __MODULE_THREE_ASSIGNMENT__EXTERNALS_H__
#define __MODULE_THREE_ASSIGNMENT__EXTERNALS_H__

//  System includes...
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

//  Project includes...
#include "Mesh.h"
#include "structs.h"


void        createMesh(GLMesh& mesh);
bool        createShaderProgram(std::string vtx_source_file_name, std::string frag_source_file_name, GLMesh& mesh);
void        destroyMesh(GLMesh& mesh);
void        destroyShaderProgram(GLMesh& mesh);
bool        initialize(int argc, char* argv[], Mesh* mesh);
void        mainRenderLoop(Mesh* mesh);
void        processInput(Mesh* mesh);
std::string readFile(std::string file_name);
void        render(const GLMesh& mesh);
void        resizeWindow(GLFWwindow* window, int width, int height);

void GLAPIENTRY
errorCallback(GLenum source,
   GLenum type,
   GLuint id,
   GLenum severity,
   GLsizei length,
   const GLchar* message,
   const void* userParam);
void CheckShader(GLuint id, GLuint type, GLint* ret, const char* onfail);
#endif  //  __MODULE_THREE_ASSIGNMENT__EXTERNALS_H__