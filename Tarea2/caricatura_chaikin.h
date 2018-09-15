#pragma once
#include <vector>
#include "vec2.h"
#include <iostream>
#include <gl/GL.h>
#include <gl/GLU.h>

class caricatura_chaikin
{
public:
	caricatura_chaikin();
	~caricatura_chaikin();

	
	std::vector<cgmath::vec2> chaikin(std::vector<cgmath::vec2>& posicion) {
		std::vector<cgmath::vec2> posicion_n;
		cgmath::vec2 a, b, anterior, act;
		for (int k = 1; k < posicion.size(); k++) {
			anterior = posicion[k - 1];
			act = posicion[k];
			a = anterior + 0.25f*(act - anterior);
			b = anterior + 0.75f*(act - anterior);
			posicion_n.push_back(a);
			posicion_n.push_back(b);
		}

		anterior = act;
		act = posicion[0];
		a = anterior + 0.25f*(act - anterior);
		b = anterior + 0.75f*(act - anterior);

		posicion_n.push_back(a);
		posicion_n.push_back(b);
		return posicion_n;
	}

	void init();

};

