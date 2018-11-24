#include <iostream>
#include <algorithm>  
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
#include "scene_particula.h"

sistema::sistema()
{
}

sistema::~sistema()
{
}



void sistema::init(cgmath::vec3 v, cgmath::vec3 mv, cgmath::vec3 p, cgmath::vec3 mp, float tt, float mtt, cgmath::vec3 ac)// puede recibir rangos
{
	//part.init ();
	position=p;
	velocity=v;
	timeToLive=tt ;
	maxposition=mp;
	maxvelocity=mv;
	maxtimeToLive = mtt;
	acel = ac;



	for (int i = 0; i < cantidadParticulas; i++)
	{	
		float positionRX = distribution(generator)*(maxposition.x - position.x) + position.x;
		float positionRY = distribution(generator)*(maxposition.y - position.y) + position.y;
		float positionRZ = distribution(generator)*(maxposition.z - position.z) + position.z;
		cgmath::vec3 positionFinal = cgmath::vec3(positionRX, positionRY, positionRZ);

		float velocityRX = distribution(generator)*(maxvelocity.x - velocity.x) + velocity.x;
		float velocityRY = distribution(generator)*(maxvelocity.y - velocity.y) + velocity.y;
		float velocityRZ = distribution(generator)*(maxvelocity.z - velocity.z) + velocity.z;
		cgmath::vec3 velocityFinal = cgmath::vec3(velocityRX, velocityRY, velocityRZ);



		float timeToL = distribution(generator)*(maxtimeToLive - timeToLive) + timeToLive;

		particulas.push_back(particula());
		particulas[i].init(velocityFinal,positionFinal,timeToL,acel);
		}
		
}




void sistema::update(cgmath::vec3 camara)
{
//	part.update();
	for (int i = 0; i < cantidadParticulas; i++) {
		particulas[i].update();

		
		//Cuando llega a 0 ttl se reinicia
		if (particulas[i].timeToLive < 0) {
			float positionRX = distribution(generator)*(maxposition.x - position.x) + position.x;
			float positionRY = distribution(generator)*(maxposition.y - position.y) + position.y;
			float positionRZ = distribution(generator)*(maxposition.z - position.z) + position.z;
			cgmath::vec3 positionFinal = cgmath::vec3(positionRX, positionRY, positionRZ);

			float velocityRX = distribution(generator)*(maxvelocity.x - velocity.x) + velocity.x;
			float velocityRY = distribution(generator)*(maxvelocity.y - velocity.y) + velocity.y;
			float velocityRZ = distribution(generator)*(maxvelocity.z - velocity.z) + velocity.z;
			cgmath::vec3 velocityFinal = cgmath::vec3(velocityRX, velocityRY, velocityRZ);

			float timeToL = distribution(generator)*(maxtimeToLive - timeToLive) + timeToLive;
			particulas[i].init(velocityFinal, positionFinal, timeToL, acel);
			particulas[i].camara = camara;
		}
	}
	

}

bool funCamara(particula i, particula j)
{
	cgmath::vec3 d1 = i.camara - i.position;
	cgmath::vec3 d2 = j.camara - i.position;
	if (d1.magnitude() < d2.magnitude())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void sistema::draw(GLuint shader_program)
{
	/*
	Sort elements in range
	Sorts the elements in the range [first,last) into ascending order.
	The elements are compared using operator< for the first version, and comp for the second.
	Equivalent elements are not guaranted to keep their original relative order (see stable_sort).
	*/

	//+lejos -> primeros
	//+cerca -> últimos
	//z?? -> cámara
	
	//std::vector<particula> myvector(particulas);   


	std::sort (particulas.begin(), particulas.end(), funCamara );           
	for (int i = 0; i < cantidadParticulas; i++)
		particulas[i].draw(shader_program);
}
