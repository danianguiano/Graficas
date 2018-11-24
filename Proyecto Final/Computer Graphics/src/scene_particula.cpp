#include <IL/il.h>

#include "cgmath.h"
#include "ifile.h"
#include "mat3.h"
#include "mat4.h"
#include "time.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include <vector>
#include "scene_particula.h"
#include "sistema.h"
#include <iostream>


void scene_particula::init()
{
	//blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//velocidad
	velocity.x = 1.0f;
	velocity.y = 0.0f;
	velocity.z = 0.0f;

	maxvelocity.x = 1.0f;
	maxvelocity.y = 0.0f;
	maxvelocity.z = 0.0f;

	//velocidad
	position.x = -12.0f;
	position.y = 6.0f;
	position.z = -8.0f;

	maxposition.x = 10.0f;
	maxposition.y = 7.0f;
	maxposition.z = 3.0f;

	//timetolive
	timeToLive = 5;
	maxtimeToLive = 8;

	//aceleración
	acel = cgmath::vec3(0.0f, -0.981f, 0.0f);

	//sistema de particulas
	sispart.init(velocity, maxvelocity, position, maxposition, timeToLive, maxtimeToLive, acel);


	//Textura
	//Load Texture
	ILuint imageID;

	ilGenImages(1, &imageID);
	ilBindImage(imageID);
	ilLoadImage("texturas/gotaTransp.png");

	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_TYPE), ilGetData());
	glBindTexture(GL_TEXTURE_2D, 0);

	ilBindImage(0);
	ilDeleteImages(1, &imageID);

	ifile shader_file;
	shader_file.read("shaders/particula.vert");
	std::string vertex_source = shader_file.get_contents();
	const GLchar* vertex_source_c = (const GLchar*)vertex_source.c_str();
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source_c, nullptr);
	glCompileShader(vertex_shader);


	shader_file.read("shaders/particula.frag");
	std::string fragment_source = shader_file.get_contents();
	const GLchar* fragment_source_c = (const GLchar*)fragment_source.c_str();
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source_c, nullptr);
	glCompileShader(fragment_shader);



	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glBindAttribLocation(shader_program, 0, "VertexPosition");
	glBindAttribLocation(shader_program, 1, "VertexTextCoord");
	glLinkProgram(shader_program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	// Set shader uniforms
	glUseProgram(shader_program);

	GLint tex_location = glGetUniformLocation(shader_program, "DiffuseTexture");
	glUniform1i(tex_location, 0);

	glUseProgram(0);

	/*if (glGetError() == GL_NO_ERROR)
	{
		std::cout << "TODO SALIO BIEN" << std::endl;
	}*/

	//iniciarposicioncamara
	camaraMov.x = 0;
	camaraMov.y = 0;
	camaraMov.z = 0;

}

void scene_particula::awake()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void scene_particula::sleep()
{
}



void scene_particula::mainLoop()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glUseProgram(shader_program);

	float radiusCamera = 2.0f;

	// View Matrix
	cgmath::mat4 view_matrix(1.0f);
	view_matrix[3][0] = camaraMov.x;// radiusCamera * sin(cgmath::radians(angleCamera));
	view_matrix[3][1] = camaraMov.y;
	view_matrix[3][2] = camaraMov.z; // radiusCamera * cos(cgmath::radians(angleCamera));;
	view_matrix = cgmath::mat4::inverse(view_matrix);



	// Projection Matrix
	float far = 1000.0f;
	float near = 1.0f;
	float half_fov = cgmath::radians(30.0f);

	cgmath::mat4 proj_matrix;
	proj_matrix[0][0] = 1.0f / (aspect * tan(half_fov));
	proj_matrix[1][1] = 1.0f / tan(half_fov);
	proj_matrix[2][2] = -((far + near) / (far - near));
	proj_matrix[2][3] = -1.0f;
	proj_matrix[3][2] = -((2 * far * near) / (far - near));

	GLuint model_location = glGetUniformLocation(shader_program, "mVista");
	glUniformMatrix4fv(model_location, 1, GL_FALSE, &view_matrix[0][0]);

	GLuint normal_location = glGetUniformLocation(shader_program, "mProyeccion");
	glUniformMatrix4fv(normal_location, 1, GL_FALSE, &proj_matrix[0][0]);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texID);

	sispart.update(camara);
	sispart.draw(shader_program);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);

	glUseProgram(0);

	/*if (glGetError() == GL_NO_ERROR)
	{
		std::cout << "TODO SALIO BIEN EN LOOP" << std::endl;
	}*/

	
}

void scene_particula::resize(int width, int height)
{
	glViewport(0, 0, width, height);

	aspect = static_cast<float>(width) / static_cast<float>(height);
}


void scene_particula::normalKeysDown(unsigned char key)
{
	switch (key) {
	case 'a':
		camaraMov.x = camaraMov.x - 0.1f;
		break;
	case 'd':
		camaraMov.x = camaraMov.x + 0.1f;
		break;
	case 'w':
		camaraMov.z = camaraMov.z - 0.1f;
		break;
	case 's':
		camaraMov.z = camaraMov.z + 0.1f;
		break;
	}
}
