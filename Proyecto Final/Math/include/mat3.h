#pragma once

#include "vec3.h"

#include "mat4.h"

namespace cgmath
{
	class mat3
	{
	private:
		float n[3][3];
	public:
		mat3();
		mat3(float diagonal);
		mat3(const cgmath::vec3& a, const cgmath::vec3& b, const cgmath::vec3& c);
		mat3(const cgmath::mat4& m);

		cgmath::vec3& operator[](int column);
		const cgmath::vec3& operator[](int column) const;

		bool operator==(const mat3& m) const;

		static float determinant(const mat3& m);
		static mat3 inverse(const mat3& m);
		static mat3 transpose(const mat3& m);

		friend std::ostream& operator<<(std::ostream& os, const mat3& m)
		{
			os << m[0][0] << " " << m[1][0] << " " << m[2][0] << std::endl;
			os << m[0][1] << " " << m[1][1] << " " << m[2][1] << std::endl;
			os << m[0][2] << " " << m[1][2] << " " << m[2][2];
			return os;
		}
	};

	inline cgmath::vec3 operator*(const mat3& m, const cgmath::vec3& v)
	{
		return m[0] * v.x + m[1] * v.y + m[2] * v.z;
	}

	inline mat3 operator*(const mat3& m1, const mat3& m2)
	{
		cgmath::vec3 c1(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2]);
		cgmath::vec3 c2(m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2]);
		cgmath::vec3 c3(m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2]);

		return mat3(c1, c2, c3);
	}
}