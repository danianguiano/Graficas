#pragma once
#include "scene.h"
#include "particula.h"

class sistema
{
public:
	sistema();
	~sistema();
	void init();
	void update();
	void draw(GLuint shader_program);
	particula part;
	static std::vector<std::unique_ptr<scene>> sceneList;
};

