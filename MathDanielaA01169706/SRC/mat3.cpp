#include "mat3.h"
#include "vec3.h"
#include <iostream>
#include <cmath>


cgmath::mat3::mat3()
{
}

cgmath::mat3::mat3(float diagonal)
{
	n[0][0] = diagonal;
	n[1][1] = diagonal;
	n[2][2] = diagonal; 
}


cgmath::mat3::mat3(const vec3& a, const vec3& b, const vec3& c )
{
	n[0][0] = a[0];
	n[0][1] = a[1];
	n[0][2] = a[2];
	n[1][0] = b[0];
	n[1][1] = b[1];
	n[1][2] = b[2];
	n[2][0] = c[0];
	n[2][1] = c[1];
	n[2][2] = c[2];
}

cgmath::vec3& cgmath::mat3::operator[](int column)
{
	if (column == 0) 
	{
		vec3 nuevo(n[0][0], n[0][1], n[0][2]);
		return nuevo;
	}
	else if (column == 1)
	{
		vec3 nuevo(n[1][0], n[1][1], n[1][2]);
		return nuevo;
	}
	else
	{
		vec3 nuevo(n[2][0], n[2][1], n[2][2]);
		return nuevo;
	}
}

const bool cgmath::mat3::operator==(const mat3& m)
{
	if (n[0] == m[0] && n[1] == m[1] && n[2] == m[2])
	{
		return true;
	}
	else
	{
		return false;
	}
}

float cgmath::mat3::determinant(const mat3& m)
{
	return ((m[0][0] * m[1][1] * m[2][2]) + (m[0][1] * m[1][2] * m[2][0]) + (m[1][0] * m[2][1] * m[0][2]) - (m[0][2] * m[1][1] * m[2][0]) - (m[0][1] * m[1][0] * m[2][2]) - (m[1][2] * m[2][1] * m[0][0]));
}

cgmath::mat3& cgmath::mat3::inverse(const mat3& m)
{
	mat3 inversa;
	inversa[0][0] = m.adjunta[0][0];
	inversa[1][0] = m.adjunta[1][0];
	inversa[2][0] = m.adjunta[2][0];
	inversa[0][1] = m.adjunta[0][1];
	inversa[1][1] = m.adjunta[1][1];
	inversa[2][1] = m.adjunta[2][1];
	inversa[0][2] = m.adjunta[0][2];
	inversa[1][2] = m.adjunta[1][2];
	inversa[2][2] = m.adjunta[2][2];

	return inversa;
}

cgmath::mat3& cgmath::mat3::transpose(const mat3& m)
{
	mat3 transpuesta;
	transpuesta[0][0] = m[0][0];
	transpuesta[0][1] = m[1][0];
	transpuesta[0][2] = m[2][0];
	transpuesta[1][0] = m[0][1];
	transpuesta[1][1] = m[1][1];
	transpuesta[1][2] = m[2][1];
	transpuesta[2][0] = m[0][2];
	transpuesta[2][1] = m[1][2];
	transpuesta[2][2] = m[2][2];

	return transpuesta;
}

cgmath::mat3& cgmath::mat3::adjunta(const mat3& m)
{
	mat3 adjuntam;
	adjuntam[0][0] = m[1][1] * m[2][2] - m[2][1] * m[1][2];
	adjuntam[1][0] = -(m[1][0] * m[2][2] - m[2][0] * m[1][2]);
	adjuntam[2][0] = m[1][0] * m[2][1] - m[2][0] * m[1][1];
	adjuntam[0][1] = -(m[0][1] * m[2][2] - m[2][1] * m[0][2]);
	adjuntam[1][1] = m[0][0] * m[2][2] - m[2][0] * m[0][2];
	adjuntam[2][1] = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]);
	adjuntam[0][2] = m[0][1] * m[1][2] - m[1][1] * m[0][2];
	adjuntam[1][2] = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]);
	adjuntam[2][2] = m[0][0] * m[1][1] - m[1][0] * m[0][1];

	return adjuntam;
}

