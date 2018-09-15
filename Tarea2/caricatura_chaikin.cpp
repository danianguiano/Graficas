#include "caricatura_chaikin.h"
#include <vector>
#include "vec2.h"
#include "scene_primitives.h"
#include "scene.h"
#include "scene_primitives.h"


inline void caricatura_chaikin::init() {
	std::vector<cgmath::vec2> posicion;

	puntos(posicion);

	for (int i = 0; i < inter; i++) {
		posicion = chaikin(posicion);
	}

	npuntos = posicion.size();
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(cgmath::vec2) * posicion.size(),
		posicion.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
}
