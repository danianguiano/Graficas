#pragma once

#include <iostream>
#include <cmath>

namespace cgmath
{
	class vec4
	{
	public:

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		float w = 0.0f;

		// Constructor por default.
		vec4();
		// Constructor con 2 parámetros.
		vec4(float x, float y, float z, float w);

		// Escritura de las variables
		float& operator[](int i);

		//Multiplica cada una de las variables de instancia por el valor escalar s.
		vec4& operator*=(float s);


		//Divide cada una de las variables de instancia por el valor escalar s.
		vec4& operator/=(float s);


		//Suma cada una de las variables de instanciacon la componente correspondiente de v.
		vec4& operator+=(const vec4& v);

		//Resta cada una de las variables de instancia con la componente correspondiente de v.
		vec4& operator-=(const vec4& v);

		//Realiza una comparación de la instancia actual de vec4 con el vecto v.
		const bool operator==(const vec4 v);

		//Crea un string con la representación en texto de la instancia sobre la cual se manda a llamar.
		friend std::ostream& operator<<(std::ostream& os, vec4& const v)
		{
			os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
			return os;
		}

		//Permite realizar una multiplicación entre un vector y un escalar.
		inline vec4 operator*(const vec4& v, float s)
		{
			v.x = v.x * s;
			v.y = v.y * s;
			v.z = v.z * s;
			v.w = v.w * s;
			return v;
		}


		//Habilita la propiedad conmutativa de la multiplicación entre un vector y un escalar.
		inline vec4 operator*(float s, const vec4& v)
		{
			v.x = v.x * s;
			v.y = v.y * s;
			v.z = v.z * s;
			v.w = v.w * s;
			return v;
		}

		//Permite realizar una división enrre un vector y un escalar
		inline vec4 operator/(const vec4& v, float s)
		{
			v.x = v.x / s;
			v.y = v.y / s;
			v.z = v.z / s;
			v.w = v.w / s;
			return v;
		}

		//Permite realizar una suma entre dos vectore
		inline vec4 operator+(const vec4& a, const vec4& b)
		{
			return(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
		}

		//Permite realizar una resta entre dos vectores
		inline vec4 operator-(const vec4& a, const vec4& b)
		{
			return(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
		}

		//Permite negar las componentes del vector v.
		inline vec4 operator-(const vec4& v)
		{
			vec4 nuevo;
			nuevo.x = v.x*-1;
			nuevo.y = v.y*-1;
			nuevo.z = v.z*-1;
			nuevo.w = v.w * -1;
			return nuevo;
		}

	};


}