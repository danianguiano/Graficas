#include <iostream>
#include <vector>
#include "cgmath.h"
#include "vec3.h"
#include "vec4.h"
#include "vec2.h"
#include "ifile.h"
#include "quad.h"
#include <GL/glut.h>

quad::quad()
{
	std::vector<cgmath::vec3> p_indices;
	std::vector<cgmath::vec2> textCoords;

	//Cordenadas de textura
	textCoords.push_back(cgmath::vec2(1.0f, 0.0f));
	textCoords.push_back(cgmath::vec2(1.0f, 1.0f));
	textCoords.push_back(cgmath::vec2(0.0f, 0.0f));
	textCoords.push_back(cgmath::vec2(0.0f, 1.0f));


	//tamaño más chico = 0.5
	float x = 0.10f;
	float y = 0.10f;
	float z = 0.1f;
	
	//Cordenadas indice
	p_indices.push_back(cgmath::vec3(x, -y, z));
	p_indices.push_back(cgmath::vec3(x, y, z));
	p_indices.push_back(cgmath::vec3(-x, -y, z));
	p_indices.push_back(cgmath::vec3(-x, y, z));

	size = p_indices.size();

	//Buffers indices
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &p_indicesVBO);
	glBindBuffer(GL_ARRAY_BUFFER, p_indicesVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec3) * p_indices.size(), p_indices.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Buffers textura
	glGenBuffers(1, &textCoordsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, textCoordsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec2) * textCoords.size(), textCoords.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

quad::~quad()
{
}

void quad::draw() 
{
	//draw
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP,0, size);
	glBindVertexArray(0);
}