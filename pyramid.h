/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Three Assignment                         * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  pyramid.h                                       * *
* *   Description         :  Temporary declaration of the vertices and       * *
* *                          indices for the pyramid to draw.  This is a     * *
* *                          temporary solution until the program can be     * *
* *                          refactored to read shape information from       * *
* *                          an external resource file.                      * *
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

#ifndef __MODULE_THREE_ASSIGNMENT__PYRAMID_H__
#define __MODULE_THREE_ASSIGNMENT__PYRAMID_H__

#include <vector>

std::vector<float> vertices =
{

   //  index 0
   -0.5f,  0.0f,  0.5f,
    1.0f,  0.0f,  0.0f,  1.0f,

   //  index 1
   -0.5f,  0.0f, -0.5f,
    0.0f,  1.0f,  0.0f,  1.0f,

   //  index 2
    0.5f,  0.0f, -0.5f,
    0.0f,  0.0f,  1.0f,  1.0f,

   //  index 3
    0.5f,  0.0f,  0.5f,
    0.0f,  1.0f,  0.0f,  1.0f,

   //  index 4
    0.0f,  0.5f,  0.0f,
    0.5f,  0.5f,  1.0f,  1.0f

};  //  GLfloat verts[]


//  Assign vertices to triangles.
std::vector<int> indices =
{

   0, 1, 2,
   0, 2, 3,
   0, 1, 4,
   1, 2, 4,
   2, 3, 4,
   3, 0, 4

};
/*


std::vector<float> vertices{
   // Vertex Positions    // Colors (r,g,b,a)
    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f, // Top Right Vertex 0
    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f, // Bottom Right Vertex 1
   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f, // Bottom Left Vertex 2
   -0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 1.0f, 1.0f, // Top Left Vertex 3

    0.5f, -0.5f, -1.0f,  0.5f, 0.5f, 1.0f, 1.0f, // 4 br  right
    0.5f,  0.5f, -1.0f,  1.0f, 1.0f, 0.5f, 1.0f, //  5 tl  right
   -0.5f,  0.5f, -1.0f,  0.2f, 0.2f, 0.5f, 1.0f, //  6 tl  top
   -0.5f, -0.5f, -1.0f,  1.0f, 0.0f, 1.0f, 1.0f  //  7 bl back
};

// Index data to share position data
std::vector<int> indices = {
    0, 1, 3,  // Triangle 1
    1, 2, 3,   // Triangle 2
    0, 1, 4,  // Triangle 3
    0, 4, 5,  // Triangle 4
    0, 5, 6, // Triangle 5
    0, 3, 6,  // Triangle 6
    4, 5, 6, // Triangle 7
    4, 6, 7, // Triangle 8
    2, 3, 6, // Triangle 9
    2, 6, 7, // Triangle 10
    1, 4, 7, // Triangle 11
    1, 2, 7 // Triangle 12
};

*/
#endif  //  __MODULE_THREE_ASSIGNMENT__CONSTS_H__