#pragma once

#include "scene.h"

class quad
{
public:
	cgmath::vec3 position;
	quad();
	~quad();
	void draw();
	int size;

private:
	GLuint shader_program;
	GLuint vao;
	GLuint positionsVBO;
	GLuint colorsVBO;
	GLuint indicesBuffer;
	virtual void init() = 0;
};

