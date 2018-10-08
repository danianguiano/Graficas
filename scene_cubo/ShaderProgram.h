#pragma once
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include "shader.h"
using namespace std;
using namespace glm;

class ShaderProgram {
public:
	ShaderProgram();
	~ShaderProgram();

	void CreateProgram();
	void AttachShader(string a, GLenum tipo);
	void LinkProgram();
	void Activate();
	void Desactivate();
	void SetAttribute(GLuint locationIndex, string nombre);
	void SetUniformf(string nombre, float value);
	void SetUniformf(string nombre, float x, float y);
	void SetUniformf(string nombre, float x, float y, float z);
	void SetUniformf(string nombre, float x, float y, float z, float w);
	void SetUniformMatrix(string nombre, mat4 matriz);


private:
	GLuint _programHandle;
	vector<unique_ptr<shader>> _attachedShaders;

	void DeleteAndDetachShaders();
	void DeleteProgram();
};