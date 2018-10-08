#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp>
#include <iostream>

#include "inputFile.h"
#include "Mesh.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Camera.h"

using namespace std;
using namespace glm;

Mesh mesh;
ShaderProgram program;
Transform _transform;
Camera _camera;

void Initialize() {

	vector<vec3> colores;
	vector<vec3> vectores;

	//Colores por cara
	colores.push_back(vec3(1.0f, 1.0f, 0));
	colores.push_back(vec3(1.0f, 1.0f, 0));
	colores.push_back(vec3(1.0f, 1.0f, 0));
	colores.push_back(vec3(1.0f, 1.0f, 0));

	colores.push_back(vec3(0.93f, 0.51f, 0.93f));
	colores.push_back(vec3(0.93f, 0.51f, 0.93f));
	colores.push_back(vec3(0.93f, 0.51f, 0.93f));
	colores.push_back(vec3(0.93f, 0.51f, 0.93f));

	colores.push_back(vec3(0.19f, 0.80f, 0.19f));
	colores.push_back(vec3(0.19f, 0.80f, 0.19f));
	colores.push_back(vec3(0.19f, 0.80f, 0.19f));
	colores.push_back(vec3(0.19f, 0.80f, 0.19f));

	colores.push_back(vec3(1.0f, 0.0f, 0.0f));
	colores.push_back(vec3(1.0f, 0.0f, 0.0f));
	colores.push_back(vec3(1.0f, 0.0f, 0.0f));
	colores.push_back(vec3(1.0f, 0.0f, 0.0f));

	colores.push_back(vec3(0.68f, 0.93f, 0.93f));
	colores.push_back(vec3(0.68f, 0.93f, 0.93f));
	colores.push_back(vec3(0.68f, 0.93f, 0.93f));
	colores.push_back(vec3(0.68f, 0.93f, 0.93f));

	colores.push_back(vec3(0.98f, 0.50f, 0.44f));
	colores.push_back(vec3(0.98f, 0.50f, 0.44f));
	colores.push_back(vec3(0.98f, 0.50f, 0.44f));
	colores.push_back(vec3(0.98f, 0.50f, 0.44f));

	//Posiciones por cara
	vectores.push_back(vec3(3.0f, -3.0f, -3.0f));
	vectores.push_back(vec3(3.0f, 3.0f, -3.0f));
	vectores.push_back(vec3(-3.0f, -3.0f, -3.0f));
	vectores.push_back(vec3(-3.0f, 3.0f, -3.0f));

	vectores.push_back(vec3(3.0f, -3.0f, -3.0f));
	vectores.push_back(vec3(3.0f, 3.0f, -3.0f));
	vectores.push_back(vec3(3.0f, -3.0f, 3.0f));
	vectores.push_back(vec3(3.0f, 3.0f, 3.0f));

	vectores.push_back(vec3(3.0f, -3.0f, 3.0f));
	vectores.push_back(vec3(3.0f, -3.0f, -3.0f));
	vectores.push_back(vec3(-3.0f, -3.0f, 3.0f));
	vectores.push_back(vec3(-3.0f, -3.0f, -3.0f));

	vectores.push_back(vec3(3.0f, -3.0f, 3.0f));
	vectores.push_back(vec3(3.0f, 3.0f, 3.0f));
	vectores.push_back(vec3(-3.0f, -3.0f, 3.0f));
	vectores.push_back(vec3(-3.0f, 3.0f, 3.0f));

	vectores.push_back(vec3(-3.0f, -3.0f, -3.0f));
	vectores.push_back(vec3(-3.0f, 3.0f, -3.0f));
	vectores.push_back(vec3(-3.0f, -3.0f, 3.0f));
	vectores.push_back(vec3(-3.0f, 3.0f, 3.0f));

	vectores.push_back(vec3(3.0f, 3.0f, 3.0f));
	vectores.push_back(vec3(3.0f, 3.0f, -3.0f));
	vectores.push_back(vec3(-3.0f, 3.0f, 3.0f));
	vectores.push_back(vec3(-3.0f, 3.0f, -3.0f));



	vector<unsigned int> indices = {
		0, 1, 2, 2, 1, 3,
		4, 5, 6, 6, 5, 7,
		8, 9, 10, 10, 9, 11,
		12, 13, 14, 14, 13, 15,
		16, 17, 18, 18, 17, 19,
		20,21,22,22,21,23,
	};
	mesh.CreateMesh(24);
	mesh.SetPositionAttribute(vectores, GL_STATIC_DRAW, 0);
	mesh.SetColorAttribute(colores, GL_STATIC_DRAW, 1);
	mesh.SetIndices(indices, GL_STATIC_DRAW);

	program.CreateProgram();
	program.AttachShader("Default.vert", GL_VERTEX_SHADER);
	program.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	program.SetAttribute(0, "VertexPosition");
	program.SetAttribute(1, "VertexColor");
	program.LinkProgram();

	_camera.SetPositionAttribute(0f,0f,10f); 
	_camera.SetOrthographic(6.0f, 1.0f);
}

void GameLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_transform.Rotate(0.30f, 0.60f, 0.30f, true);
												

	program.Activate();
	program.SetUniformMatrix("mvplMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);
	program.Desactivate();


	glutSwapBuffers();
}

void Idle() {
	glutPostRedisplay();
}

void ReshapeWindow(int w, int h) {
	glViewport(0, 0, w, h);

}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitContextVersion(4, 2);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); 
	glutInitWindowSize(400, 400);
	glutCreateWindow("Holi");
	glutDisplayFunc(GameLoop);
	glutReshapeFunc(ReshapeWindow);
	glutIdleFunc(Idle);
	glewInit();
	glClearColor(1.0f, 1.0f, 3.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	std::cout << glGetString(GL_VERSION) << std::endl;
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	Initialize();
	glutMainLoop();

	return 0;
}