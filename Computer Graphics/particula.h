#pragma once

#include "scene.h"
#include "quad.h"

class particula : public scene
{
public:
	particula(cgmath::vec3 pos, <cgmath::vec3> vel, float s, cgmath::vec3 ac);
	~particula();
	void update();
	void draw(GLuint shader_program);
	quad part;
	cgmath::vec3 position;
	cgmath::vec3 velocity;
	float size;
	float timeToLive = 10.0f;
	cgmath::vec3 a;
	GLuint vao;


private:
};

