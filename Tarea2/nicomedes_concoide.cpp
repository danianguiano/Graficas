#include "nicomedes_concoide.h"
#include "vec2.h"
#include <vector>
#include "scene_primitives.h"
#include "scene.h"

void nicomedes_concoide::init()
{
	std::vector<cgmath::vec2> x;
	x.push_back(cgmath::vec2(1.0f, 0.0f));
	x.push_back(cgmath::vec2(-1.0f, 0.0f));

	std::vector<cgmath::vec2> y;
	y.push_back(cgmath::vec2(0.0f, 1.0f));
	y.push_back(cgmath::vec2(0.0f, -1.0f));

	std::vector<cgmath::vec2> curva_l;
	curva_l.push_back(cgmath::vec2(-1.491f / 10.0f, 1.0f));
	curva_l.push_back(cgmath::vec2(-1.727f / 10.0f, 0.5f));
	curva_l.push_back(cgmath::vec2(-1.844f / 10.0f, 0.4f));
	curva_l.push_back(cgmath::vec2(-2.145f / 10.0f, 0.25f));
	curva_l.push_back(cgmath::vec2(-2.5f / 10.0f, 0.1f));
	curva_l.push_back(cgmath::vec2(-2.6f / 10.0f, 0.0f));
	curva_l.push_back(cgmath::vec2(-2.5f / 10.0f, -0.1f));
	curva_l.push_back(cgmath::vec2(-2.145f / 10.0f, -0.25f));
	curva_l.push_back(cgmath::vec2(-1.844f / 10.0f, -0.4f));
	curva_l.push_back(cgmath::vec2(-1.727f / 10.0f, -0.5f));
	curva_l.push_back(cgmath::vec2(-1.491f / 10.0f, -1.0f));

	std::vector<cgmath::vec2> curva_r;
	curva_r.push_back(cgmath::vec2(-1.151f / 10.0f, 1.0f));
	curva_r.push_back(cgmath::vec2(-1.036f / 10.0f, 0.5f));
	curva_r.push_back(cgmath::vec2(-0.989f / 10.0f, 0.4f));
	curva_r.push_back(cgmath::vec2(-0.876f / 10.0f, 0.25f));
	curva_r.push_back(cgmath::vec2(-0.82f / 10.0f, 0.2f));
	curva_r.push_back(cgmath::vec2(-0.62 / 10.0f, 0.1f));
	curva_r.push_back(cgmath::vec2(-0.44 / 10.0f, 0.05f));
	curva_r.push_back(cgmath::vec2(-0.18 / 10.0f, 0.01f));
	curva_r.push_back(cgmath::vec2(0.0f, 0.0f));
	curva_r.push_back(cgmath::vec2(-0.18 / 10.0f, -0.01f));
	curva_r.push_back(cgmath::vec2(-0.44f / 10.0f, -0.05f));
	curva_r.push_back(cgmath::vec2(-0.62f / 10.0f, -0.1f));
	curva_r.push_back(cgmath::vec2(-0.82f / 10.0f, -0.2f));
	curva_r.push_back(cgmath::vec2(-0.876f / 10.0f, -0.25f));
	curva_r.push_back(cgmath::vec2(-0.989f / 10.0f, -0.4f));
	curva_r.push_back(cgmath::vec2(-1.036f / 10.0f, -0.5f));
	curva_r.push_back(cgmath::vec2(-1.151f / 10.0f, -1.0f));


	std::vector<cgmath::vec2> vector_ = x;
	vector_.insert(vector_.end(), y.begin(), y.end());
	vector_.insert(vector_.end(), curva_l.begin(), curva_l.end());
	vector_.insert(vector_.end(), curva_r.begin(), curva_r.end());


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(cgmath::vec2) * vector_.size(),
		vector_.data(),
		GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);


	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

void nicomedes_concoide::awake()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glPointSize(20.0f);

}

void nicomedes_concoide::sleep()
{
	glPointSize(1.0f);
}

void nicomedes_concoide::mainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindVertexArray(vao);

	glDrawArrays(GL_LINES, 0, 4);
	glDrawArrays(GL_LINES, 4, 2);

	glDrawArrays(GL_LINES, 5, 2);
	glDrawArrays(GL_LINES, 6, 2);
	glDrawArrays(GL_LINES, 7, 2);
	glDrawArrays(GL_LINES, 8, 2);
	glDrawArrays(GL_LINES, 9, 2);
	glDrawArrays(GL_LINES, 10, 2);
	glDrawArrays(GL_LINES, 11, 2);
	glDrawArrays(GL_LINES, 12, 2);
	glDrawArrays(GL_LINES, 13, 2);

	glDrawArrays(GL_LINES, 15, 2);
	glDrawArrays(GL_LINES, 16, 2);
	glDrawArrays(GL_LINES, 17, 2);
	glDrawArrays(GL_LINES, 18, 2);
	glDrawArrays(GL_LINES, 19, 2);
	glDrawArrays(GL_LINES, 20, 2);
	glDrawArrays(GL_LINES, 21, 2);
	glDrawArrays(GL_LINES, 22, 2);
	glDrawArrays(GL_LINES, 23, 2);
	glDrawArrays(GL_LINES, 24, 2);
	glDrawArrays(GL_LINES, 25, 2);
	glDrawArrays(GL_LINES, 26, 2);
	glDrawArrays(GL_LINES, 27, 2);
	glDrawArrays(GL_LINES, 28, 2);
	glDrawArrays(GL_LINES, 29, 2);
	glDrawArrays(GL_LINES, 30, 2);
	glBindVertexArray(0);

}