#include "Mesh.h"

Mesh::Mesh() {
	_vertexArrayObject = 0;
	_vectoresVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_vertexCount = 0;

	_indexCount = 0;
	_indexBufferObject = 0;

}

Mesh::~Mesh() {
	glDeleteBuffers(1, &_vectoresVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
	glDeleteVertexArrays(1, &_vertexArrayObject);
}

void Mesh::CreateMesh(GLuint vertexCount) {
	_vertexCount = vertexCount;
	glGenVertexArrays(1, &_vertexArrayObject);
}

void Mesh::Draw(GLenum primitive) {
	glBindVertexArray(_vertexArrayObject);
	if (_indexCount == 0) {
		glDrawArrays(primitive, 0, _vertexCount);
	}
	else {
		(_vertexArrayObject);
		glDrawElements(primitive, _indexCount, GL_UNSIGNED_INT, nullptr);
	}
	glBindVertexArray(0);
}

void Mesh::SetPositionAttribute(vector<vec2> vectores, GLenum usage, GLuint locationIndex) {
	if (vectores.size() == 0 || vectores.size() != _vertexCount) {
		return;
	}
	else {
		SetAttributeData(_vectoresVertexBufferObject, sizeof(vec2) * vectores.size(), vectores.data(), usage, locationIndex, 2);
	}
}

void Mesh::SetPositionAttribute(vector<vec3> vectores, GLenum usage, GLuint locationIndex) {
	if (vectores.size() == 0 || vectores.size() != _vertexCount) {
		return;
	}
	else {
		SetAttributeData(_vectoresVertexBufferObject, sizeof(vec3) * vectores.size(), vectores.data(), usage, locationIndex, 3);
	}
}

void Mesh::SetColorAttribute(vector<vec3> colors, GLenum usage, GLuint locationIndex) {
	if (colors.size() == 0 || colors.size() != _vertexCount) {
		return;
	}
	else {
		SetAttributeData(_colorsVertexBufferObject, sizeof(vec3) * colors.size(), colors.data(), usage, locationIndex, 3);
	}
}

void Mesh::SetColorAttribute(vector<vec4> colors, GLenum usage, GLuint locationIndex) {
	if (colors.size() == 0 || colors.size() != _vertexCount) {
		return;
	}
	else {
		SetAttributeData(_colorsVertexBufferObject, sizeof(vec4) * colors.size(), colors.data(), usage, locationIndex, 4);
	}
}

void Mesh::SetIndices(vector<unsigned int> indices, GLenum usage) {
	_indexCount = indices.size();

	if (_indexCount > 0) {
		glBindVertexArray(_vertexArrayObject);
		glGenBuffers(1, &_indexBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)* indices.size(), indices.data(), GL_STATIC_DRAW);
		glBindVertexArray(0);
	}
}

void Mesh::SetAttributeData(GLuint & buffer, const GLsizeiptr size, const void * data, GLenum usage, GLuint locationIndex, const GLuint components) {
	if (buffer != 0) {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	glBindVertexArray(_vertexArrayObject);
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glEnableVertexAttribArray(locationIndex);
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}