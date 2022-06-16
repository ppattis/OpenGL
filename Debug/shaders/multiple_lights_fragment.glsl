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
* *  13 June 2022   P. D. Pattison    Modified to use multiple point lights  * *
* *                                                                          * *
* *                                                                          * *
* **************************************************************************** *
******************************************************************************/

//  Version declaration.
#version 440 core

//  Shader input declaration.
in vec3 vertex_fragment_coordinate;
in vec3 vertex_normal_coordinate;
in vec2 vertex_texture_coordinate;

//  Shader output declaration...
out vec4 fragment_color;

struct material_structure
{

	sampler2D texture;
	float     shininess;

};

struct point_light_structure
{

	vec3  position;

	float constant;
	float linear;
	float quadratic;

	vec3  ambient;
	vec3  diffuse;
	vec3  specular;

};

#define NUMBER_OF_POINT_LIGHTS 2

//  Uniform declarations...
uniform vec3      view_position_uniform;
uniform point_light_structure lights_uniform[NUMBER_OF_POINT_LIGHTS];
uniform material_structure material_uniform;


//  Forward function prototypes....
vec3 calculatePointLight(point_light_structure light, vec3 normal, vec3 fragment_position, vec3 view_direction);

//  Main shader function.
void main()
{

   //  Properties...
   vec3 norm = normalize(vertex_normal_coordinate);
   vec3 view_direction = normalize(view_position_uniform - vertex_fragment_coordinate);

   //  Point lights...
   vec3 result;
   for (int index = 0; index < NUMBER_OF_POINT_LIGHTS; index++)
   {
   
		result += calculatePointLight(lights_uniform[index], norm, vertex_fragment_coordinate, view_direction);
   
   }

   fragment_color = vec4(result, 1.0);
   

}  //  void main()

//
vec3 calculate_point_light(point_light_structure light, vec3 normal, vec3 fragment_position, vec3 view_direction)
{

	vec3 light_direction = normalize(light.position - fragment_position);
	//  Diffuse shading...
	float diff = max(dot(normal, light_direction), 0.0);
	//  Specular shading...
	vec3 reflect_direction = reflect(-light_direction, normal);
	float spec = pow(max(dot(view_direction, reflect_direction), 0.0), material_uniform.shininess);
	//  attenuation
	float distance    = length(light.position - fragment_position);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

	//  Combine results...
	vec3 ambient  = light.ambient  *        vec3(texture(material_uniform.texture,  vertex_texture_coordinate));
	vec3 diffuse  = light.diffuse  * diff * vec3(texture(material_uniform.texture,  vertex_texture_coordinate));
	vec3 specular = light.specular * spec * vec3(texture(material_uniform.texture, vertex_texture_coordinate));
	ambient      *= attenuation;
	diffuse      *= attenuation;
	specular     *= attenuation;

	return (ambient + diffuse + specular);

}  //  vec3 calculate_point_light(point_light_structure light, vec3 normal, vec3 fragment_position, vec3 view_direction)