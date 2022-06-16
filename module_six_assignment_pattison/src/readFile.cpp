/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Five Assignment                          * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  readFile.cpp                                    * *
* *   Description         :  Utility function to read in a text file and     * *
* *                          return the entire contents as a std::string.    * *
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
* *  27 May  2022   P. D. Pattison    Imported into Module Three.            * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/


//  System includes...
#include <fstream>
#include <string>
#include <sstream>

//  Project includes...


//  Function   :  readFile()
//  Parameters :  std::string file_name
//  Return     :  std::string
//  Description:  Reads file_name into a string.
std::string readFile(std::string file_name)
{

   //  Create std::stringstream to create the std::string return.
   std::stringstream input_buffer;

   //  Create std::fstream to read in the text file.
   std::ifstream input_file(file_name);
   input_buffer << input_file.rdbuf();

   //  Return the std::string representation of the text file.
   return input_buffer.str();

}  //  std::string readFile(std::string file_name)