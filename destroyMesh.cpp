/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  destroyMesh.cpp                                 * *
* *   Description         :  Destroy the data structures associated with     * *
* *                          the mesh, and free up the memory.               * *
* *                                                                          * *
* *                                                                          * *
* *************************************************************************  * *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  10 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Cleanup and comment for turn in        * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three.            * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  28 May  2022   P. D. Pattison    Changed to standardized include of     * *
* *                                   graphics_includes.h header file.       * *
* *  02 May  2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...

//  Project includes...
#include "graphics_includes.h"
#include "structs.h"


//  Function   :  destroyMesh()
//  Parameters :  GLMesh &mesh
//  Return     :  void
//  Description:  Delete the VAO and the VBOs.
void destroyMesh(GLMesh& mesh)
{

   glDeleteVertexArrays(1, &mesh.vao);
   glDeleteBuffers(1, mesh.vbos);

}  //  void destroyMesh(GLMesh& mesh)