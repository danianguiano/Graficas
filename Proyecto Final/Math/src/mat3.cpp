#include "mat3.h"

cgmath::mat3::mat3()
{
	n[0][0] = 0.0f;	n[1][0] = 0.0f; n[2][0] = 0.0f;
	n[0][1] = 0.0f; n[1][1] = 0.0f; n[2][1] = 0.0f;
	n[0][2] = 0.0f; n[1][2] = 0.0f; n[2][2] = 0.0f;
}

cgmath::mat3::mat3(float diagonal)
{
	n[0][0] = diagonal;	n[1][0] = 0.0f;		n[2][0] = 0.0f;
	n[0][1] = 0.0f;		n[1][1] = diagonal;	n[2][1] = 0.0f;
	n[0][2] = 0.0f;		n[1][2] = 0.0f;		n[2][2] = diagonal;
}

cgmath::mat3::mat3(const cgmath::vec3& a, const cgmath::vec3& b, const cgmath::vec3& c)
{
	n[0][0] = a.x; n[1][0] = b.x; n[2][0] = c.x;
	n[0][1] = a.y; n[1][1] = b.y; n[2][1] = c.y;
	n[0][2] = a.z; n[1][2] = b.z; n[2][2] = c.z;
}

cgmath::mat3::mat3(const cgmath::mat4& m)
{
	n[0][0] = m[0][0]; n[1][0] = m[1][0]; n[2][0] = m[2][0];
	n[0][1] = m[0][1]; n[1][1] = m[1][1]; n[2][1] = m[2][1];
	n[0][2] = m[0][2]; n[1][2] = m[1][2]; n[2][2] = m[2][2];
}

cgmath::vec3& cgmath::mat3::operator[](int column)
{
	return *reinterpret_cast<cgmath::vec3*>(n[column]);
}

const cgmath::vec3& cgmath::mat3::operator[](int column) const
{
	return *reinterpret_cast<const cgmath::vec3*>(n[column]);
}

bool cgmath::mat3::operator==(const cgmath::mat3& m) const
{
	return n[0][0] == m[0][0] && n[0][1] == m[0][1] && n[0][2] == m[0][2] &&
		n[1][0] == m[1][0] && n[1][1] == m[1][1] && n[1][2] == m[1][2] &&
		n[2][0] == m[2][0] && n[2][1] == m[2][1] && n[2][2] == m[2][2];
}

float cgmath::mat3::determinant(const cgmath::mat3& m)
{
	return m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
		- m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
		+ m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
}

cgmath::mat3 cgmath::mat3::inverse(const cgmath::mat3& m)
{
	const cgmath::vec3& a = m[0];
	const cgmath::vec3& b = m[1];
	const cgmath::vec3& c = m[2];

	cgmath::vec3 r0 = cgmath::vec3::cross(b, c);
	cgmath::vec3 r1 = cgmath::vec3::cross(c, a);
	cgmath::vec3 r2 = cgmath::vec3::cross(a, b);

	float invDet = 1.0f / cgmath::vec3::dot(a, r0);

	r0 *= invDet;
	r1 *= invDet;
	r2 *= invDet;

	mat3 inv;
	inv[0][0] = r0.x; inv[1][0] = r0.y; inv[2][0] = r0.z;
	inv[0][1] = r1.x; inv[1][1] = r1.y; inv[2][1] = r1.z;
	inv[0][2] = r2.x; inv[1][2] = r2.y; inv[2][2] = r2.z;

	return inv;
}

cgmath::mat3 cgmath::mat3::transpose(const cgmath::mat3& m)
{
	const cgmath::vec3& a = m[0];
	const cgmath::vec3& b = m[1];
	const cgmath::vec3& c = m[2];

	return mat3(cgmath::vec3(a.x, b.x, c.x), cgmath::vec3(a.y, b.y, c.y), cgmath::vec3(a.z, b.z, c.z));
}