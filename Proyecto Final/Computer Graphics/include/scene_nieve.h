#pragma once
#include "scene.h"
#include "sistema.h"

class scene_nieve : public scene
{
public:

	void init();
	void awake();
	void sleep() ;
	void reset() { }
	void mainLoop();
	void resize(int width, int height);
	void normalKeysDown(unsigned char key);
	void normalKeysUp(unsigned char key) { };
	void specialKeys(int key) { };
	void passiveMotion(int x, int y) { };


private:
	float aspect;
	sistema sispart;
	GLuint shader_program;
	GLuint vao;
	GLuint texID;
	float angleCamera;
	cgmath::vec3 position;
	cgmath::vec3 velocity;
	float timeToLive = 10.0f;
	float maxtimeToLive;
	cgmath::vec3 maxposition;
	cgmath::vec3 maxvelocity;
	cgmath::vec3 ac;


	cgmath::vec3 camara;
	cgmath::vec3 camaraMov;



};

