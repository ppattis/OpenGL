/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
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
* *  27 May  2022   P. D. Pattison    Imported into Module Three 3D Scene    * *
* *                                   assignment.  Removed rotation from     * *
* *                                   rendering function.                    * *
* *  29 May  2022   P. D. Pattison    Imported into Module Four.  Modified   * *
* *                                   to use the camera controls from my     * *
* *                                   module four assignment.                * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...
#include <iostream>
#include <vector>

//  Project includes...
#include "consts.h"
#include "graphics_includes.h"
#include "structs.h"

//  Third party includes...
#include <learnOpengl/camera.h>

//  External global variable declarations...
extern struct camera_structure camera;


//  Function   :  render()
//  Parameters :  const GLMesh& mesh, const GLuint program_id, GLFWwindow *window
//  Return     :  void
//  Description:  Render the scene.
void render(const std::vector<mesh_structure>& renderable, const GLuint program_id, GLFWwindow *window)
{

   //  Scale objects by 2 in all axis
   glm::mat4 scale = glm::scale(glm::vec3(2.0f, 2.0f, 2.0f));
   //  Rotate objects
   glm::mat4 rotation = glm::rotate(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
   //  Place objects at the origin
   glm::mat4 translation = glm::translate(glm::vec3(0.0f, 0.0f, 0.0f));
   glm::mat4 model = translation * rotation * scale;

   //  Transform the camera:  Move the camera back (z axis)
   glm::mat4 view = camera.camera.GetViewMatrix();

   //  Create a orthographic projection
   glm::mat4 projection = glm::mat4(1.0f);
   switch (camera.current_projection)
   {

      case (0):  //  Perspective
         projection = glm::perspective(glm::radians(camera.camera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);
         break;
      case (1):  //  Orthographic
         projection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 100.0f);
         break;

   }

   //  Set the shader to be used
   glUseProgram(program_id);

   //  Retrieve and pass transforms to the shader program...
   GLint model_location = glGetUniformLocation(program_id, "model");
   GLint view_location = glGetUniformLocation(program_id, "view");
   GLint projection_location = glGetUniformLocation(program_id, "projection");

   glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));
   glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));
   glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));

   //  Draw the outline...
   //glBindVertexArray(renderable.outline.vertex_array);
   //glDrawElements(GL_LINES, renderable.outline.number_indices, GL_UNSIGNED_SHORT, NULL);

   //  Draw the surface...
   for (int index = 0; index < renderable.size(); index++)
   {
      std::cout << "Rendering texture_id " << renderable[index].texture_id << "\n";
      glActiveTexture(GL_TEXTURE0/* + renderable[index].texture_offset*/);
      glBindTexture(GL_TEXTURE_2D, renderable[index].texture_id);
      glBindVertexArray(renderable[index].vertex_array);
      glDrawElements(GL_TRIANGLES, renderable[index].number_indices, GL_UNSIGNED_SHORT, NULL);

   }

   glBindVertexArray(0);

}  //  void render(const GLMesh& mesh, const GLuint program_id, GLFWwindow *window)