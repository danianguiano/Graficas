#include "shader.h"
#include "InputFile.h"

shader::shader() {
	_shaderHandle = 0;
}

shader::~shader() {
	glDeleteShader(_shaderHandle);
}

void shader::CreateShader(string path, GLenum type) {

	if (_shaderHandle != 0) {
		glDeleteShader(_shaderHandle);
	}

	InputFile myfile;
	myfile.Read(path);
	string ShaderSource = myfile.GetContents();
	_shaderHandle = glCreateShader(type);
	const GLchar *ShaderSource_c = (const GLchar*)ShaderSource.c_str();
	glShaderSource(_shaderHandle, 1, &ShaderSource_c, nullptr);
	glCompileShader(_shaderHandle);
}

GLuint shader::getHandle() {
	return _shaderHandle;
}