#pragma once

#include <GL/glew.h>
#include <vector>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Mesh {
public:
	Mesh();
	~Mesh();

	void CreateMesh(GLuint vertexCount);
	void Draw(GLenum primitive);
	void SetPositionAttribute(vector<vec2> vectores, GLenum usage, GLuint locationIndex);
	void SetPositionAttribute(vector<vec3> vectores, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(vector<vec3> colors, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(vector<vec4> colors, GLenum usage, GLuint locationIndex);
	void SetIndices(vector<unsigned int> indices, GLenum usage);

private:
	void SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void * data, GLenum usage,
		GLuint locationIndex, const GLuint components);

	GLuint _vertexArrayObject;
	GLuint _vectoresVertexBufferObject;
	GLuint _colorsVertexBufferObject;
	GLuint _vertexCount;
	GLuint _indexBufferObject;
	GLint  _indexCount;

	
};