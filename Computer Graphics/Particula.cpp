#include <iostream>
#include <vector>
#include "cgmath.h"
#include "vec3.h"
#include "vec4.h"
#include "particula.h"
#include "time.h"
#include "ifile.h"
#include "quad.h"
#include "particula.h"
#include "mat4.h"


particula::particula(cgmath::vec3 pos, cgmath::vec3 vel, float s, cgmath::vec3 ac)
{
	quad part;
	cgmath::vec3 position= pos;
	cgmath::vec3 velocity = vel;
	float size;
	float timeToLive = 10.0f;
	cgmath::vec3 a=ac;
}

particula::~particula()
{
}

void particula::update()
{	
	position = position + velocity * time::delta_time().count();
	velocity = velocity + a * time::delta_time().count();
	timeToLive = timeToLive - time::delta_time().count();

}

void particula::draw(GLuint shader_program)
{
	

	float t = time::elapsed_time().count();

	float angleX = cgmath::radians(t * 30.0f);
	float angleY = cgmath::radians(t * 60.0f);
	float angleZ = cgmath::radians(t * 30.0f);

	// Matriz modelo

	glGetUniformLocation(shader_program);
	glUniformMatrix4fv(shader_program);
	part.draw();

}
