/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Milestone                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  destroyMesh.cpp                                 * *
* *   Description         :  Destroy the data structures associated with     * *
* *                          the mesh, and free up the memory.               * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  10 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Cleanup and comment for turn in        * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three.            * *
* *  27 May  2022   P. D. Pattison    Modified for the model_structure.      * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  05 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...
#include <GL/glew.h>

//  Project includes...
#include "structs.h"


//  Function   :  destroyMesh()
//  Parameters :  GLMesh &mesh
//  Return     :  void
//  Description:  Delete the VAO and the VBOs.
void destroyMesh(mesh_structure& model)
{

   glDeleteVertexArrays(1, &model.vertex_array);
   glDeleteVertexArrays(1, &model.vertex_buffer);
   glDeleteVertexArrays(1, &model.index_buffer);
   glDeleteVertexArrays(1, &model.vertex_array);
   glDeleteVertexArrays(1, &model.vertex_buffer);
   glDeleteVertexArrays(1, &model.index_buffer);


}  //  void destroyMesh(GLMesh& mesh)