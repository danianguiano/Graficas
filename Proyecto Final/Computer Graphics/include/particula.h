#pragma once

#include "scene.h"
#include "quad.h"
#include <vector>
#include "vec3.h"



class particula
{
public:
	void init(cgmath::vec3 velocity, cgmath::vec3 position,  float timeToLive, cgmath::vec3 acel);
	void update();
	void draw(GLuint shader_program);

	quad part;
	float size;
	cgmath::vec3 a;
	cgmath::vec3 position;
	cgmath::vec3 velocity;
	float timeToLive = 10.0f;
	cgmath::vec3 maxposition;
	cgmath::vec3 maxvelocity;
	float maxtimeToLive;
	cgmath::vec3 camara;
	

private:
	
};

