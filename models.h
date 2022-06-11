/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  models.h                                        * *
* *   Description         :  Definition of models for drawing.               * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  27 May  2022   P. D. Pattison    Initial development...                 * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


#ifndef __MODULE_FIVE_MILESTONE__MODELS_H__
#define __MODULE_FIVE_MILESTONE__MODELS_H__

//  System includes...
#include <GL/glew.h>
#include <string>

//  Project includes...
#include "consts.h"


//  Watch Box
//  Top of Bottom
GLfloat wb_bottom_top_vertices[] =
{

   -0.500000,  0.200000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //   0
   -0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //   1
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //   2

   -0.500000,  0.200000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //   3
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //   4
    0.500000,  0.200000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  0.000000   //   5

};

GLushort wb_bottom_top_indices[] =
{

   0, 1, 2,
   3, 4, 5

};

std::string wb_bottom_top_texture = "wb_bottom_top.jpg";

//  Bottom of Bottom
GLfloat wb_bottom_bottom_vertices[] =
{

   -0.500000,  0.000000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  0
   -0.500000,  0.000000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //  1
    0.500000,  0.000000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  2

   -0.500000,  0.000000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  3
    0.500000,  0.000000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  4
    0.500000,  0.000000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  0.000000   //  5

};

GLushort wb_bottom_bottom_indices[] =
{

   0, 1, 2,
   3, 4, 5

};

std::string wb_bottom_bottom_texture = "wb_bottom_bottom.jpg";

//  Inside of Lid
GLfloat wb_lid_inside_vertices[] =
{

   -0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  0
   -0.500000,  0.700000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //  1
    0.500000,  0.700000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  2

   -0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  3
    0.500000,  0.700000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  4
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  0.000000,  //  5

};

GLushort wb_lid_inside_indices[] =
{

   0, 1, 2,
   3, 4, 5

};

std::string wb_lid_inside_texture = "wb_lid_inside.jpg";

//  Outside of Lid
GLfloat wb_lid_outside_vertices[] =
{

   -0.385000,  0.265000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  0
   -0.385000,  0.635000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //  1
    0.385000,  0.635000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  2

   -0.385000,  0.265000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  3
    0.385000,  0.635000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  4
    0.385000,  0.265000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  0.000000  //  5

};

GLushort wb_lid_outside_indices[] =
{

   0, 1, 2,
   3, 4, 5

};

std::string wb_lid_outside_texture = "wb_lid_outside.jpg";

//  Edges of bottom and lid
GLfloat wb_box_edges_vertices[] =
{

   //  Front of Bottom of Box
   -0.500000,  0.000000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //   0
   -0.500000,  0.200000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //   1
    0.500000,  0.200000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //   2

   -0.500000,  0.000000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //   3
    0.500000,  0.200000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //   4
    0.500000,  0.000000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  0.000000,  //   5
   //  Back of Bottom of Box
   -0.500000,  0.000000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //   6
   -0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //   7
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //   8

   -0.500000,  0.000000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //   9
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  10
    0.500000,  0.000000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  0.000000,  //  11
   //  Left of Bottom of Box
   -0.500000,  0.000000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  12
   -0.500000,  0.200000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //  13
   -0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  14

   -0.500000,  0.000000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  15
   -0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  16
   -0.500000,  0.000000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  0.000000,  //  17
   //  Right of Bottom of Box
    0.500000,  0.000000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  18
    0.500000,  0.200000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //  19
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  20

    0.500000,  0.000000, -0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  21
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  22
    0.500000,  0.000000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  0.000000,  //  23
   //  Top of Top of Box
   -0.500000,  0.700000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  24
   -0.385000,  0.635000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //  25
    0.385000,  0.635000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  26

   -0.500000,  0.700000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  27
    0.385000,  0.635000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  28
    0.500000,  0.700000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  0.000000,  //  29
   //  Bottom of Top of Box
   -0.385000,  0.265000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  30
   -0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //  31
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  32

   -0.385000,  0.265000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  33
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  34
    0.385000,  0.265000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  0.000000,  //  35
   //  Left of Top of Box
   -0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  0.000000,  //  36
   -0.385000,  0.265000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    0.000000,  1.000000,  //  37
   -0.385000,  0.635000,  0.600000,    0.000000,  0.000000,  0.000000, 0.000000,    1.000000,  1.000000,  //  38

   -0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000,  0.000000,   0.000000,  0.000000,  //  39
   -0.385000,  0.635000,  0.600000,    0.000000,  0.000000,  0.000000,  0.000000,   1.000000,  1.000000,  //  40
   -0.500000,  0.700000,  0.500000,    0.000000,  0.000000,  0.000000,  0.000000,   1.000000,  0.000000,  //  41
   //  Right of Top of Box
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000,  0.000000,   0.000000,  0.000000,  //  42
    0.385000,  0.265000,  0.600000,    0.000000,  0.000000,  0.000000,  0.000000,   0.000000,  1.000000,  //  43
    0.385000,  0.635000,  0.600000,    0.000000,  0.000000,  0.000000,  0.000000,   1.000000,  1.000000,  //  44

    0.385000,  0.635000,  0.600000,    0.000000,  0.000000,  0.000000,  0.000000,   0.000000,  0.000000,  //  45
    0.500000,  0.200000,  0.500000,    0.000000,  0.000000,  0.000000,  0.000000,   1.000000,  1.000000,  //  46
    0.500000,  0.700000,  0.500000,    0.000000,  0.000000,  0.000000,  0.000000,   1.000000,  0.000000  //  47

};

GLushort wb_box_edges_indices[] =
{

    0,  1,  2,
    3,  4,  5,
    6,  7,  8,
    9, 10, 11,
   12, 13, 14,
   15, 16, 17,
   18, 19, 20,
   21, 22, 23,
   24, 25, 26,
   27, 28, 29,
   30, 31, 32,
   33, 34, 35,
   36, 37, 38,
   39, 40, 41,
   42, 43, 44,
   45, 46, 47

};

std::string wb_box_edges_texture = "wb_box_edges.jpg";





#endif  //  __MODULE_FIVE_MILESTONE__MODELS_H__