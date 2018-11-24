#pragma once
#include "scene.h"
#include "particula.h"
#include "vec3.h"
#include <vector>
#include <random>

class sistema
{
public:
	sistema();
	~sistema();
	void init(cgmath::vec3 velocity, cgmath::vec3 maxvelocity, cgmath::vec3 position, cgmath::vec3 maxposition, float timeToLive, float maxtimeToLive, cgmath::vec3 ac);
	void update(cgmath::vec3 camara);
	void draw(GLuint shader_program);
	particula part;
	std::vector<particula> particulas;
	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution{ 0.0,1.0 };
	cgmath::vec3 position;
	cgmath::vec3 velocity;
	float timeToLive = 10.0f;
	cgmath::vec3 maxposition;
	cgmath::vec3 maxvelocity;
	float maxtimeToLive = 10.0f;
	int cantidadParticulas = 10000;
	cgmath::vec3 acel;
	cgmath::vec3 camara;

};

