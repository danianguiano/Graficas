#include "vec3.h"
#include <cmath>

cgmath::vec3::vec3()
{
}

cgmath::vec3::vec3(float x, float y, float z) : x(x), y(y), z(z)
{
}

float & cgmath::vec3::operator[](int i)
{
	switch (i) {
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	}
}


cgmath::vec3& cgmath::vec3::operator*=(float s)
{
	vec3 nuevo;
	nuevo.x = x * s;
	nuevo.y = y * s;
	nuevo.z = z * s;
	return nuevo;
}

cgmath::vec3& cgmath::vec3::operator/=(float s)
{
	vec3 n;
	n.x = x / s;
	n.y = y / s;
	n.z = z / s;
	return n;
}

cgmath::vec3& cgmath::vec3::operator+=(const vec3 & v)
{
	vec3 nuevo;
	nuevo.x = x + v.x;
	nuevo.y = y + v.y;
	nuevo.z = z + v.z;
	return nuevo;
}

cgmath::vec3& cgmath::vec3::operator-=(const vec3 & v)
{
	vec3 nuevo;
	nuevo.x = x - v.x;
	nuevo.y = y - v.y;
	nuevo.z = z - v.z;
	return nuevo;
}

const bool cgmath::vec3::operator==(const vec3 v)
{
	if (x == v.x && y == v.y && z == v.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float cgmath::vec3::dot(const vec3 & a, const vec3 & b)
{
	return (((a.y*b.z) - (a.z*b.y)) - ((a.x*b.z) - (a.z*b.x)) + ((a.x*b.y) - (a.y*b.x)));
}

float cgmath::vec3::cross(const vec3 & a, const vec3 & b)
{

	return (a.y*b.z - a.z*b.y, a.z * b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

const float cgmath::vec3::magnitude()
{
	return sqrt(x * x + y * y + z * z);
}

void cgmath::vec3::normalize()
{
	x = x / magnitude();
	y = y / magnitude();
	z = z / magnitude();
}

float cgmath::vec3::magnitude(const vec3 & v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z* v.z);
}

cgmath::vec3& cgmath::vec3::normalize(const vec3& v)
{
	vec3 nuevo;
	nuevo.x = v.x / magnitude(v);
	nuevo.y = v.y / magnitude(v);
	nuevo.z = v.z / magnitude(v);
	return nuevo;
}

