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

//  Shader output declaration...
out vec4 fragment_color;

struct material_structure
{

	sampler2D diffuse;
	sampler2D specular;
	float     shininess;

};

struct directional_light_structure
{

	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

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

struct spot_light_structure
{

	vec3 position;
	vec3 direction;
	float cut_off;
	float outer_cut_off;

	float constant;
	float linear;
	float quadratic;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

};

#define NUMBER_OF_POINT_LIGHTS 2

//  Shader input declaration.
in vec3 vertex_fragment_coordinate;
in vec3 vertex_normal_coordinate;
in vec2 vertex_texture_coordinate;

//  Uniform declarations...
uniform vec3                        view_position_uniform;
uniform directional_light_structure directional_light_uniform;
uniform point_light_structure       point_light_uniform[NUMBER_OF_POINT_LIGHTS];
uniform spot_light_structure        spot_light_uniform;
uniform material_structure          material_uniform;


//  Forward function prototypes....
vec3 calculateDirectionalLight(directional_light_structure light, vec3 normal, vec3 view_direction);
vec3 calculatePointLight(point_light_structure light, vec3 normal, vec3 fragment_position, vec3 view_direction);
vec3 calculateSpotLight(spot_light_structure light, vec3 normal, vec3 fragment_position, vec3 view_direction);

//  Main shader function.
void main()
{

   //  Properties...
   vec3 norm = normalize(vertex_normal_coordinate);
   vec3 view_direction = normalize(view_position_uniform - vertex_fragment_coordinate);

   //  Directional lighting...
   vec3 result = calculateDirectionalLight(directional_light_uniform, norm, view_direction);

   //  Point lights...
   for (int index = 0; index < NUMBER_OF_POINT_LIGHTS; index++)
   {
   
		result += calculatePointLight(point_light_uniform[index], norm, vertex_fragment_coordinate, view_direction);
   
   }

   //  Spot lighting...
   result += calculateSpotLight(spot_light_uniform, norm, vertex_fragment_coordinate, view_position_uniform);

   fragment_color = vec4(result, 1.0);
   

}  //  void main()


//  
vec3 calculateDirectionalLight(directional_light_structure light, vec3 normal, vec3 view_direction)
{

	vec3 light_direction = normalize(-light.direction);
	//  diffuse shading
	float diff = max(dot(normal, light_direction), 0.0);
	//  Specular shading
	vec3 reflect_direction = reflect(-light_direction, normal);
	float spec = pow(max(dot(view_direction, reflect_direction), 0.0), material_uniform.shininess);
	//  Combine results...
	vec3 ambient = light.ambient * vec3(texture(material_uniform.diffuse, vertex_texture_coordinate));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material_uniform.diffuse, vertex_texture_coordinate));
	vec3 specular = light.specular * spec * vec3(texture(material_uniform.specular, vertex_texture_coordinate));
	return (ambient + diffuse + specular);

}

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
	vec3 ambient  = light.ambient  *        vec3(texture(material_uniform.diffuse,  vertex_texture_coordinate));
	vec3 diffuse  = light.diffuse  * diff * vec3(texture(material_uniform.diffuse,  vertex_texture_coordinate));
	vec3 specular = light.specular * spec * vec3(texture(material_uniform.specular, vertex_texture_coordinate));
	ambient      *= attenuation;
	diffuse      *= attenuation;
	specular     *= attenuation;

	return (ambient + diffuse + specular);

}  //  vec3 calculate_point_light(point_light_structure light, vec3 normal, vec3 fragment_position, vec3 view_direction)

//
vec3 calculateSpotLight(spot_light_structure light, vec3 normal, vec3 fragment_position, vec3 view_direction)
{

	vec3 light_direction = normalize(light.position - fragment_position);
	//  Diffuse shading
	float diff = max(dot(normal, light_direction), 0.0);
	//  Specular Shading
	vec3 reflect_direction = reflect(-light_direction, normal);
	float spec = pow(max(dot(view_direction, reflect_direction), 0.0), material_uniform.shininess);
	//  Attenuation
	float distance = length(light.position - fragment_position);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	//  Spot light intensity
	float theta = dot(light_direction, normalize(-light.direction));
	float epsilon = light.cut_off - light.outer_cut_off;
	float intensity = clamp((theta - light.outer_cut_off) / epsilon, 0.0, 1.0);
	//  Combine results...
	vec3 ambient = light.ambient * vec3(texture(material_uniform.diffuse, vertex_texture_coordinate));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material_uniform.diffuse, vertex_texture_coordinate));
	vec3 specular = light.specular * spec * vec3(texture(material_uniform.specular, vertex_texture_coordinate));
	ambient *= attenuation * intensity;
	diffuse *= attenuation * intensity;
	specular *= attenuation * intensity;
	return (ambient + diffuse + specular);

}