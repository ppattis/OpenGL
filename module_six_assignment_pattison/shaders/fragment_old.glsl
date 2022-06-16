/*******************************************************************************
* **************************************************************************** *
* *                                                                          * *
* *   Project Name        :  Module Six Assignment                           * *
* *   Project Description :  OpenGL Assignment                               * *
* *   File Name           :  fragment.glsl                                   * *
* *   Description         :  Fragment shader source code.                    * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
* *                                                                          * *
* *                                                                          * *
* *                                Change Log                                * *
* *      Date        Author            Description                           * *
* *  ************   ***************   *************************************  * *
* *  10 May  2022   P. D. Pattison    Initial Coding...                      * *
* *  12 May  2022   P. D. Pattison    Cleanup and comment for turn in.       * *
* *  27 May  2022   P. D. Pattison    Imported into Module Three.  Modified  * *
* *                                   for 3D rendering.                      * *
* *  28 May  2022   P. D. Pattison    Imported into Module Four.             * *
* *  02 June 2022   P. D. Pattison    Imported into Module Five.             * *
* *  02 June 2022   P. D. Pattison    Modified to use textures.  Changed     * *
* *                                   in variable name and type, added       * *
* *                                   uniforms for textures, also modified   * *
* *                                   the main function heavily.             * *
* *  11 June 2022   P. D. Pattison    Imported into Module Six.              * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

//  Version declaration.
#version 440 core

//  Shader input declaration.
in vec2 vertex_texture;
in vec3 vertex_normal;
in vec3 vertex_fragment_position;

//  Shader output declaration.
out vec4 fragment_color;

//  Texture uniforms.
uniform sampler2D texture_uniform;
uniform vec2      uv_scale_uniform;
uniform vec3      object_color_uniform;
uniform vec3      light_color_uniform;
uniform vec3      light_one_position_uniform;
uniform vec3      light_two_position_uniform;
uniform vec3      view_position_uniform;

//  Main shader function.
void main()
{

   //  Phong lighting model calculations...
   //  Calculate the ambient lighting...
   float ambient_strength = 0.1f;
   vec3 ambient = ambient_strength * light_color_uniform;

   //  Calculate the diffuse lighting...
   vec3 norm = normalize(vertex_normal);
   vec3 light_direction = normalize(light_one_position_uniform - vertex_fragment_position);
   float impact = max(dot(norm, light_direction), 0.0);
   vec3 diffuse = impact * light_color_uniform;

   //  Calculate specular lighting...
   float specular_intensity = 0.8f;
   float highlight_size = 16.0f;
   vec3 view_direction = normalize(view_position_uniform - vertex_fragment_position);
   vec3 reflect_direction = reflect(-light_direction, norm);

   float specular_component = pow(max(dot(view_position_uniform, reflect_direction), 0.0), highlight_size);
   vec3 specular = specular_intensity * specular_component * light_color_uniform;

   vec4 texture_color = texture(texture_uniform, vertex_texture * uv_scale_uniform);

   //  Calculate Phong...
   vec3 phong = (ambient + diffuse + specular) * texture_color.xyz;

   //  Pass the input color to the output.
   fragment_color = vec4(phong, 1.0f);
   

}  //  void main()