/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  consts.h                                        * *
* *   Description         :  declaration of project constants.               * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  10 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Moved VALUES_PER_VERTEX and            * *
* *                                   VALUES_PER_COLOR here.                 * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three.            * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *  05 June 2022   P. D. Pattison    Added VALUES_PER_TEXTURE               * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

#ifndef __MODULE_FIVE_MILESTONE__CONSTS_H__
#define __MODULE_FIVE_MILESTONE__CONSTS_H__

//  System includes...
#include <GL/glew.h>


//  Project includes...


const int         WINDOW_WIDTH      = 800;
const int         WINDOW_HEIGHT     = 600;
const char* const WINDOW_TITLE      = "Module Three Assignment - Pattison";

//  Number of values that represent coordinate points per vertex, (X, Y, Z)
const GLuint      VALUES_PER_VERTEX = 3;
//  Number of values that represent a points color, (r, g, b, a)
const GLuint      VALUES_PER_COLOR  = 4;
//  Number of values that represent a texture coordinate, (u, v)
const GLuint      VALUES_PER_TEXTURE = 2;


#endif  //  __MODULE_FIVE_MILESTONE__CONSTS_H__