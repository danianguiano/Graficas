
#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>

using namespace std;

class shader {
public:
	shader();
	~shader();

	void CreateShader(string path, GLenum type);
	GLuint getHandle();
private:
	GLuint _shaderHandle;
};