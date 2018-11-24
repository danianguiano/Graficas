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
#include "quad.h"


void particula::init(cgmath::vec3 v, cgmath::vec3 p, float t, cgmath::vec3 acel)
{
	//Definidas en el .h
	position.x = p.x;
	position.y = p.y;
	position.z = p.z;

	velocity.x = v.x;
	velocity.y = v.y;
	velocity.z = v.z;

	a = acel;

	size = 10;
	timeToLive = t;

}


void particula::update()
{	

	//Movimiento
	velocity = velocity + a * time::delta_time().count();
	position = position + velocity * time::delta_time().count();
	timeToLive = timeToLive - time::delta_time().count();

}

void particula::draw(GLuint shader_program)
{
	// Matriz modelo - Matriz translación
	cgmath::mat4 translationMat(1.0f);

	translationMat[3][0] = position.x;
	translationMat[3][1] = position.y;
	translationMat[3][2] = position.z;

	GLuint model = glGetUniformLocation(shader_program, "mModelo");
	glUniformMatrix4fv(model, 1, GL_FALSE, &translationMat[0][0]);
	part.draw();

}
