#include "scene_fragment.h"

#include "ifile.h"
#include "time.h"
#include "vec2.h"
#include <vector>

scene_fragment::~scene_fragment()
{
}

void scene_fragment::init()
{
	std::vector<cgmath::vec2> positions;
	positions.push_back(cgmath::vec2(-1.0f, -1.0f));
	positions.push_back(cgmath::vec2(1.0f, -1.0f));
	positions.push_back(cgmath::vec2(1.0f, 1.0f));
	positions.push_back(cgmath::vec2(-1.0f, 1.0f));

	std::vector<unsigned int> indices{ 0, 1, 2, 0, 2, 3 };

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(cgmath::vec2) * positions.size(),
		positions.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &indicesBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(unsigned int) * indices.size(),
		indices.data(),
		GL_STATIC_DRAW);

	glBindVertexArray(0);


	ifile shader_file;
	shader_file.read("shaders/Default.vert");
	std::string vertex_source = shader_file.get_contents();
	const GLchar* vertex_source_c = (const GLchar*)vertex_source.c_str();
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source_c, nullptr);
	glCompileShader(vertex_shader);

	shader_file.read("shaders/palmtree.frag");
	std::string fragment_source = shader_file.get_contents();
	const GLchar* fragment_source_c = (const GLchar*)fragment_source.c_str();
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source_c, nullptr);
	glCompileShader(fragment_shader);

	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glBindAttribLocation(shader_program, 0, "VertexPosition");
	glLinkProgram(shader_program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	glUseProgram(shader_program);
	GLuint resolution_location = glGetUniformLocation(shader_program,
		"iResolution");
	glUniform2f(resolution_location, 400, 400);
	glUseProgram(0);
}

void scene_fragment::awake()
{
}

void scene_fragment::sleep()
{
}

void scene_fragment::mainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader_program);

	GLuint time_location = glGetUniformLocation(shader_program, "iTime");
	glUniform1f(time_location, time::elapsed_time().count());

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(vao);

	glUseProgram(0);
}

void scene_fragment::resize(int width, int height)
{
	glViewport(0, 0, width, height);

	glUseProgram(shader_program);
	GLuint resolution_location = glGetUniformLocation(shader_program,
		"iResolution");
	glUniform2f(resolution_location, width, height);
	glUseProgram(0);
}
