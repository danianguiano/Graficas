#include "vec2.h"
#include "vec3.h"
#include <cmath>


cgmath::vec2::vec2(): x(0.0f), y(0.0f)
{
}

cgmath::vec2::vec2(float x, float y): x(x), y(y)
{
}

float & cgmath::vec2::operator[](int i)
{
	switch(i) {
		case 0:
			return x;
		case 1:
			return y;
	}	
}


cgmath::vec2& cgmath::vec2::operator*=(float s)
{
	x = x * s;
	y = y * s;

}

cgmath::vec2& cgmath::vec2::operator/=(float s)
{
	x = x / s;
	y = y / s;

}

cgmath::vec2& cgmath::vec2::operator+=(const vec2& v)
{
	x = x + v.x;
	y = y + v.y;

}

cgmath::vec2& cgmath::vec2::operator-=(const vec2& v)
{
	x = x - v.x;
	y = y - v.y;

}

const bool cgmath::vec2::operator==(const vec2 v)
{
	if (x == v.x && y == v.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float cgmath::vec2::dot(const vec2 & a, const vec2 & b)
{
	return (a.x * b.x + a.y *b.y);
}

const float cgmath::vec2::magnitude()
{
	return sqrt(x * x + y * y);
}

void cgmath::vec2::normalize()
{
	x = x / magnitude();
	y = y / magnitude();
}

float cgmath::vec2::magnitude(const vec2 & v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

cgmath::vec2& cgmath::vec2::normalize(const vec2& v)
{
	vec2 norm;
	norm.x = v.x / magnitude(v);
	norm.y = v.y / magnitude(v);
	return norm;
}



