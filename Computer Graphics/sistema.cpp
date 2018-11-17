#include <iostream>
#include <vector>
#include "cgmath.h"
#include "vec3.h"
#include "vec4.h"
#include "particula.h"
#include "time.h"
#include "ifile.h"
#include "quad.h"
#include "sistema.h"
#include "mat4.h"


std::vector<cgmath::vec3> particula::particulaList;

sistema::sistema()
{
}

sistema::~sistema()
{
}

void sistema::init()// puede recibir rangos
{
	particula part;
}

void sistema::update()
{
	for (int i = 0; i < (partList.size - 1); i++)
		part(i).update()
//si murio
//reinicio 

}

void sistema::draw(GLuint shader_program)
{
	for (int i = 0; i < (partList.size - 1); i++)
		part(i).draw(GLuint shader_program);
}
