/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  consts.h                                        * *
* *   Description         :  declaration of project constants.               * *
* *                                                                          * *
* *                                                                          * *
* *************************************************************************  * *
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
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *  03 June 2022   P. D. Pattison    Added VALUES_PER_TEXTURE...            * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

#ifndef __MODULE_FIVE_ASSIGNMENT__CONSTS_H__
#define __MODULE_FIVE_ASSIGNMENT__CONSTS_H__

//  System includes...


//  Project includes...
#include "graphics_includes.h"

const int         WINDOW_WIDTH      = 800;
const int         WINDOW_HEIGHT     = 600;
const char* const WINDOW_TITLE      = "Module Six Assignment - Pattison";

//  Number of values that represent coordinate points per vertex.
const GLuint      VALUES_PER_VERTEX = 3;
//  Number of values that represent a points color, (r, g, b, a)
const GLuint      VALUES_PER_COLOR  = 4;
//  Number of values that represent a texture coordinate.
const GLuint      VALUES_PER_TEXTURE = 2;
//  Number of values that represent a normal 
const GLuint      VALUES_PER_NORMAL = 3;


#endif  //  __MODULE_FIVE_ASSIGNMENT__CONSTS_H__