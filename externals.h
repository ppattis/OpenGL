/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
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
* *  27 May  2022   P. D. Pattison    Imported into Module Three 3D Scene    * *
* *                                   assignment.  Removed rotation from     * *
* *                                   rendering function.                    * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four              * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
*******************************************************************************/


#ifndef __MODULE_FIVE_MILESTONE__EXTERNALS_H__
#define __MODULE_FIVE_MILESTONE__EXTERNALS_H__

//  System includes...
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

//  Project includes...
#include "structs.h"


void        createMesh(std::vector<mesh_structure>& model, GLuint program_id);
bool        createShaderProgram(std::string vtx_source_file_name, std::string frag_source_file_name, GLuint& program_id);
void        destroyMesh(mesh_structure& model);
void        destroyShaderProgram(GLuint program_id);
bool        initialize(int argc, char* argv[], GLFWwindow** window);
void        mainRenderLoop(GLFWwindow* window, GLuint program_id, std::vector<mesh_structure> renderable);
void        processInput(GLFWwindow* window, int key, int scan_code, int action, int mode);
std::string readFile(std::string file_name);
void        render(const std::vector<mesh_structure>& renderable, const GLuint program_id, GLFWwindow* window);
void        resizeWindow(GLFWwindow* window, int width, int height);
void        mouseScrollCallback(GLFWwindow* window, double offset_x, double offset_y);
void        mouseMovementCallback(GLFWwindow* window, double mouse_x, double mouse_y);
bool        createTexture(std::string file_name, GLuint& texture_id);
void        flipImageVertically(unsigned char* image, int width, int height, int channels);

void GLAPIENTRY
errorCallback(GLenum source,
   GLenum type,
   GLuint id,
   GLenum severity,
   GLsizei length,
   const GLchar* message,
   const void* userParam);

#endif  //  __MODULE_FIVE_MILESTONE__EXTERNALS_H__