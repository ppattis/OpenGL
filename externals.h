/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
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
* *  ************   ***************   *************************************  * *
* *  10 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Cleanup and comment for turn in.       * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three.            * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  28 May  2022   P. D. Pattison    Updated processInput function          * *
* *                                   signiture for update to callback.      * *
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  02 June 2022   P. D. Pattison    Iported into Module Five.              * *
* *  02 June 2022   P. D. Pattison    Added forward declaration of the       * *
* *                                   functions flipImageVertically and      * *
* *                                   createTexture.                         * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
*******************************************************************************/


#ifndef __MODULE_FIVE_ASSIGNMENT__EXTERNALS_H__
#define __MODULE_FIVE_ASSIGNMENT__EXTERNALS_H__

//  System includes...
#include <string>

//  Project includes...
#include "graphics_includes.h"
#include "Shader.h"
#include "structs.h"
#include "Texture.h"


//  Forward function declarations...
void        createMesh(GLMesh& mesh);
bool        createShaderProgram(std::string vtx_source_file_name, std::string frag_source_file_name, GLuint& program_id);
void        destroyMesh(GLMesh& mesh);
void        destroyShaderProgram(GLuint program_id);
bool        initialize(int argc, char* argv[], GLFWwindow** window);
void        mainRenderLoop(GLFWwindow* window, Shader shader, GLMesh mesh, Texture texture);
void        processInput(GLFWwindow* window, int key, int scan_code, int action, int mode);
std::string readFile(std::string file_name);
void        render(const GLMesh& mesh, Shader shader, GLFWwindow* window, float rotate_index, Texture texture);
void        resizeWindow(GLFWwindow* window, int width, int height);
void        mouseScrollCallback(GLFWwindow* window, double offset_x, double offset_y);
void        mouseMovementCallback(GLFWwindow* window, double mouse_x, double mouse_y);
void        flipImageVertically(unsigned char* image, int width, int height, int channels);
bool        createTexture(std::string file_name, GLuint& texture_id);
void        destroyTexture(GLuint texture_id);

void GLAPIENTRY
errorCallback(GLenum source,
   GLenum type,
   GLuint id,
   GLenum severity,
   GLsizei length,
   const GLchar* message,
   const void* userParam);


#endif  //  __MODULE_FIVE_ASSIGNMENT__EXTERNALS_H__