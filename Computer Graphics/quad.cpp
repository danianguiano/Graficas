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

	size = p_indices.size();

	float x = 3.0f;
	float y = 3.0f;
	float z = 3.0f;

	p_indices.push_back(cgmath::vec3(-x, -y, z));
	p_indices.push_back(cgmath::vec3(x, -y, z));
	p_indices.push_back(cgmath::vec3(x, y, z));
	p_indices.push_back(cgmath::vec3(-x, y, z));

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec3) * p_indices.size(), p_indices.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
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