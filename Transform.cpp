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


//  System includes...
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>


//  Project includes...

#include "consts.h"
#include "Transform.h"


Transform::Transform()
{

   //  Create the matricies
   this->model = glm::mat4(1.0f);
   this->view = glm::mat4(1.0f);

   //  Set up the projection matrix.
   this->perspective = glm::perspective(glm::radians(45.0f), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);
   //glm::mat4 projection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 100.0f);

}


void Transform::setRotation(float degrees, glm::vec3 axis)
{

   this->model = glm::rotate(this->model, glm::radians(degrees), axis);

}


void Transform::setScale(glm::vec3 scale)
{

   this->model = glm::scale(this->model, scale);

}


void Transform::setTranslation(glm::vec3 trans)
{

   this->model = glm::translate(this->model, trans);

}


void Transform::setView(glm::vec3 view_origin)
{

   this->view = glm::translate(this->view, view_origin);

}


glm::mat4 Transform::getModel()
{

   return this->model;

}


glm::mat4 Transform::getView()
{

   return this->view;

}


glm::mat4 Transform::getPerspective()
{

   return this->perspective;

}
