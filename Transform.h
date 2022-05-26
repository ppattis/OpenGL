/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Three Assignment                         * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  Transform.h                                     * *
* *   Description         :  Declaration of Shader class.                    * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  *************  ****************  **************************************** *
* *   24 May 2022   P. D. Pattison    Initial Coding...                      * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

#ifndef __MODULE_THREE_ASSIGNMENT__TRANSFORM_H__
#define __MODULE_THREE_ASSIGNMENT__TRANSFORM_H__

//  System includes...
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>


//  Project includes...


class Transform
{

public:

   Transform();
   ~Transform();

   void setRotation(float degrees, glm::vec3 axis);
   void setScale(glm::vec3 scale);
   void setTranslation(glm::vec3 trans);
   void setView(glm::vec3 view_origin);

   glm::mat4 getModel();
   glm::mat4 getView();
   glm::mat4 getPerspective();

private:

   glm::mat4 model;
   glm::mat4 view;
   glm::mat4 perspective;

};


#endif  //  __MODULE_THREE_ASSIGNMENT__TRANSFORM_H__