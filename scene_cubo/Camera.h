#pragma once

#include <glm/glm.hpp>
#include "Transform.h"

using namespace glm;
using namespace std;

class Camera {
public:
	Camera();
	mat4 GetViewProjection();
	mat4 GetViewMatrix();
	mat4 GetProjectionMatrix();
	vec3 GetPosition();

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);

	void MoveForward(float delta, bool worl = false);
	void MoveUp(float delta, bool worl = false);
	void MoveRight(float delta, bool worl = false);


	void Yaw(float degrees);
	void Roll(float degrees);
	void Pitch(float degrees);
	void Rotate(float x, float y, float z, bool worl = false);

	void SetPerspective(float nearPlane, float farPlane, float fieldOfView, float aspectRatio);
	void SetOrthographic(float sixe, float aspectRatio);

private:
	Transform _transform;

	mat4 _viewMatrix;
	mat4 _projectionMatrix;

};