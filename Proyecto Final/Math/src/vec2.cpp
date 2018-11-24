#include "vec2.h"

cgmath::vec2::vec2() : x(0.0f), y(0.0f)
{
}

cgmath::vec2::vec2(float x, float y) : x(x), y(y)
{
}

float& cgmath::vec2::operator[](int i)
{
	return (&x)[i];
}

const float& cgmath::vec2::operator[](int i) const
{
	return (&x)[i];
}

cgmath::vec2& cgmath::vec2::operator*=(float s)
{
	x *= s;
	y *= s;
	return *this;
}

cgmath::vec2& cgmath::vec2::operator/=(float s)
{
	s = 1.0f / s;
	x *= s;
	y *= s;
	return *this;
}

cgmath::vec2& cgmath::vec2::operator+=(const cgmath::vec2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

cgmath::vec2& cgmath::vec2::operator-=(const cgmath::vec2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

bool cgmath::vec2::operator==(const cgmath::vec2& v) const
{
	return x == v.x && y == v.y;
}

float cgmath::vec2::magnitude() const
{
	return sqrt(x * x + y * y);
}

void cgmath::vec2::normalize()
{
	float m = magnitude();
	x /= m;
	y /= m;
}

float cgmath::vec2::magnitude(const cgmath::vec2& v)
{
	return v.magnitude();
}

cgmath::vec2 cgmath::vec2::normalize(const cgmath::vec2& v)
{
	return v / v.magnitude();
}

float cgmath::vec2::dot(const cgmath::vec2& a, const cgmath::vec2& b)
{
	return a.x * b.x + a.y * b.y;
}