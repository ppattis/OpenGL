/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  render.cpp                                      * *
* *   Description         :  Function to render scene.                       * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  11 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Cleanup and comment for turn in.       * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three.  Modified  * *
* *                                   for drawing a 3D Pyramid.              * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *  03 June 2022   P. D. Pattison    Modified to use textures.              * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...
#include <iostream>

//  Project includes...
#include "consts.h"
#include "graphics_includes.h"
#include "Shader.h"
#include "structs.h"
#include "Texture.h"

//  Third party includes...
#include <learnOpengl/camera.h>


//  External global variable declaration
extern struct camera_structure camera;
extern bool                    debug_mode;

//  Function   :  render()
//  Parameters :  const GLMesh& mesh, const GLuint program_id, GLFWwindow *window
//  Return     :  void
//  Description:  Render the scene.
void render(const GLMesh& mesh, Shader shader, GLFWwindow *window, float rotate_index, Texture texture)
{

   //  Enable z-depth
   glEnable(GL_DEPTH_TEST);

   //  Clear the background
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   //  Scale objects by 2 in all axis
   glm::mat4 scale = glm::scale(glm::vec3(2.0f, 2.0f, 2.0f));
   //  Rotate objects
   glm::mat4 rotation = glm::rotate(4.0f, glm::vec3(0.0f, 1.0f, 0.0f));
   //  Place objects at the origin
   glm::mat4 translation = glm::translate(glm::vec3(0.0f, -1.0f, -2.0f));
   //glm::mat4 model = translation * rotation * scale;
   glm::mat4 model = glm::mat4(1.0f);
   //  Transform the camera:  Move the camera back (z axis)
   //glm::mat4 view = glm::translate(glm::vec3(0.0f, 0.0f, -5.0f));
   glm::mat4 view = camera.camera.GetViewMatrix();

   //  Create a orthographic projection
   //glm::mat4 projection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 100.0f);
   glm::mat4 projection = glm::perspective(glm::radians(camera.camera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);

   //  Set the shader to be used
   shader.bind();

   glm::vec3 light_one_position(0.7f, 0.2f, 2.0);
   glm::vec3 light_two_position(2.3f, -3.3f, -4.0);
   //  Retrieve and pass transforms to the shader program...
   /*
   GLint model_location = glGetUniformLocation(shader.getHandle(), "model");
   GLint view_location = glGetUniformLocation(shader.getHandle(), "view");
   GLint projection_location = glGetUniformLocation(shader.getHandle(), "projection");

   glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));
   glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));
   glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));
   */
   
   shader.setMat4("model_uniform", model);
   shader.setMat4("view_uniform", view);
   shader.setMat4("projection_uniform", projection);


   //  Retrieve and pass Light uniforms to the shader program...
   /*
   GLint object_color_location = glGetUniformLocation(shader.getHandle(), "object_color_uniform");
   GLint light_color_location = glGetUniformLocation(shader.getHandle(), "light_color_uniform");
   GLint light_one_position_location = glGetUniformLocation(shader.getHandle(), "light_one_position_uniform");
   GLint light_two_position_location = glGetUniformLocation(shader.getHandle(), "light_two_position_uniform");
   GLint view_position_location = glGetUniformLocation(shader.getHandle(), "view_position_uniform");

   glUniform3f(object_color_location, object_color.r, object_color.g, object_color.b);
   glUniform3f(light_color_location, light_color.r, light_color.g, light_color.b);
   glUniform3f(light_one_position_location, light_one_position.x, light_one_position.y, light_one_position.z);
   glUniform3f(light_two_position_location, light_two_position.x, light_two_position.y, light_two_position.z);
   const glm::vec3 camera_position = camera.camera.Position;
   glUniform3f(view_position_location, camera_position.x, camera_position.y, camera_position.z);

   GLint uv_scale_location = glGetUniformLocation(shader.getHandle(), "uv_scale_uniform");
   glUniform2fv(uv_scale_location, 1, glm::value_ptr(uv_scale));
   */

   shader.set1Int("material_uniform.diffuse", 0);
   shader.set1Int("material_uniform.specular", 1);
   shader.set1Float("material_uniform.shininess", 32.0f);

   const glm::vec3 camera_position = camera.camera.Position;

   //  Configure lights in shader...
        // directional light
   shader.setVec3("directional_light_uniform.direction", glm::vec3(- 0.2f, -1.0f, -0.3f));
   shader.setVec3("directional_light_uniform.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
   shader.setVec3("directional_light_uniform.diffuse", glm::vec3(0.4f, 0.4f, 0.4f));
   shader.setVec3("directional_light_uniform.specular", glm::vec3(0.5f, 0.5f, 0.5f));

   shader.setVec3("point_light_uniform[0].position", light_one_position);
   shader.setVec3("point_light_uniform[0].ambient", glm::vec3(0.05f, 0.05f, 0.05f));
   shader.setVec3("point_light_uniform[0].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
   shader.setVec3("point_light_uniform[0].specular", glm::vec3(1.0f, 1.0f, 1.0f));
   shader.set1Float("point_light_uniform[0].constant", 1.0f);
   shader.set1Float("point_light_uniform[0].linear", 0.09f);
   shader.set1Float("point_light_uniform[0].quadratic", 0.032f);

   shader.setVec3("point_light_uniform[1].position", light_two_position);
   shader.setVec3("point_light_uniform[1].ambient", glm::vec3(0.05f, 0.05f, 0.05f));
   shader.setVec3("point_light_uniform[1].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
   shader.setVec3("point_light_uniform[1].specular", glm::vec3(1.0f, 1.0f, 1.0f));
   shader.set1Float("point_light_uniform[1].constant", 1.0f);
   shader.set1Float("point_light_uniform[1].linear", 0.09f);
   shader.set1Float("point_light_uniform[1].quadratic", 0.032f);

   // spotLight
   shader.setVec3("spotLight.position", camera.camera.Position);
   shader.setVec3("spotLight.direction", camera.camera.Front);
   shader.setVec3("spotLight.ambient", glm::vec3(0.0f, 0.0f, 0.0f));
   shader.setVec3("spotLight.diffuse", glm::vec3(1.0f, 1.0f, 1.0f));
   shader.setVec3("spotLight.specular", glm::vec3(1.0f, 1.0f, 1.0f));
   shader.set1Float("spotLight.constant", 1.0f);
   shader.set1Float("spotLight.linear", 0.09f);
   shader.set1Float("spotLight.quadratic", 0.032f);
   shader.set1Float("spotLight.cut_off", glm::cos(glm::radians(12.5f)));
   shader.set1Float("spotLight.outer_cut_off", glm::cos(glm::radians(15.0f)));


   //  Active the VBOs contained within the mesh's VAO
   glBindVertexArray(mesh.vao);

   //glActiveTexture(GL_TEXTURE0);
   //glBindTexture(GL_TEXTURE_2D, mesh.texture_id);
   texture.bind(0);
   texture.bind(1);
   //  Draw the triangle.
   glDrawArrays(GL_TRIANGLES, 0, 36);
   //std::cout << mesh.nIndices << "\n";
   //  Deactivate the VAO
   glBindVertexArray(0);

   //  glfw:  swap buffers and poll IO events
   glfwSwapBuffers(window);

}  //  void render(const GLMesh& mesh, const GLuint program_id, GLFWwindow *window)