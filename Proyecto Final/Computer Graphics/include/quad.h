#pragma once

#include "scene.h"

class quad
{
public:
	quad();
	~quad();
	void draw();
	int size;

private:
	GLuint vao;
	GLuint p_indicesVBO;
	GLuint textCoordsVBO;


};

