#include "vec3.h"
#include "vec4.h"
#include <cmath>

cgmath::vec4::vec4()
{
}

cgmath::vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

float & cgmath::vec4::operator[](int i)
{
	switch (i) {
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	case 3:
		return w;
	}
}

cgmath::vec4& cgmath::vec4::operator*=(float s)
{
	x = x * s;
	y = y * s;
	z = z * s;
	w = w * s;

}

cgmath::vec4& cgmath::vec4::operator/=(float s)
{
	x = x / s;
	y = y / s;
	z = z / s;
	w = w / s;

}


cgmath::vec4& cgmath::vec4::operator+=(const vec4 & v)
{
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;
	w = w + v.w;

}

cgmath::vec4& cgmath::vec4::operator-=(const vec4 & v)
{
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;
	w = w - v.w;

}

const bool cgmath::vec4::operator==(const vec4 v)
{
	if (x == v.x && y == v.y && z == v.z && w == v.w)
	{
		return true;
	}
	else
	{
		return false;
	}
}

