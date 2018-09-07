#pragma once

#include <iostream>
#include "vec3.h"
#include <cmath>


namespace cgmath
{
	class vec2
	{
	public:

		float x = 0.0f;
		float y = 0.0f;

		// Constructor por default.
		vec2();
		// Constructor con 2 parámetros.
		vec2(float x, float y);

		// Escritura de las variables
		float& operator[](int i);

		//Multiplica cada una de las variables de instancia por el valor escalar s.
		vec2& operator*=(float s);


		//Divide cada una de las variables de instancia por el valor escalar s.
		vec2& operator/=(float s);


		//Suma cada una de las variables de instanciacon la componente correspondiente de v.
		vec2& operator+=(const vec2& v);

		//Resta cada una de las variables de instancia con la componente correspondiente de v.
		vec2& operator-=(const vec2& v);

		//Realiza una comparación de la instancia actual de vec2 con el vecto v.
		const bool operator==(const vec2 v);

		//Calcula y regresa la magnitud de la instancia sobre la cual se manda a llamar.
		const float magnitude();

		//Normaliza el vector de la instancia sobre la cual se manda a llamar.
		void normalize();

		//Calcula y regresa la magnitud del vector v
		float magnitude(const vec2& v);

		//Calcula y regresa la magnitud del vector v
		vec2 normalize(const vec2& v);

		//Calcula y regresa el producto punto entre los vectores a y b
		float dot(const vec2& a, const vec2& b);

		//Crea un string con la representación en texto de la instancia sobre la cual se manda a llamar.
		friend std::ostream& operator<<(std::ostream& os, vec2& const v)
		{
			os << "(" << v.x << ", " << v.y << ")";
			return os;
		}

		//Permite realizar una multiplicación entre un vector y un escalar.
		inline vec2 operator*(const vec2& v, float s)
		{
			v.x = v.x* s;
			v.y = v.y * s;
			return v;
		}


		//Habilita la propiedad conmutativa de la multiplicación entre un vector y un escalar.
		inline vec3 operator*(float s, const vec3& v)
		{
			v.x = v.x * s;
			v.y = v.y * s;
			return v;
		}

		//Permite realizar una división enrre un vector y un escalar
		inline vec2 operator/(const vec2& v, float s)
		{
			vec2 nuevo;
			nuevo.x = v.x / s;
			nuevo.y = v.y / s;
			return nuevo;
		}

		//Permite realizar una suma entre dos vectore
		inline vec2 operator+(const vec2& a, const vec2& b)
		{
			return(a.x + b.x, a.y + b.y);
		}

		//Permite realizar una resta entre dos vectores
		inline vec2 operator-(const vec2& a, const vec2& b)
		{
			return(a.x - b.x, a.y - b.y);
		}

		//Permite negar las componentes del vector v.
		inline vec2 operator-(const vec2& v)
		{
			vec2 nuevo;
			nuevo.x = v.x*-1;
			nuevo.y = v.y*-1;
			return nuevo;
		}

	};


}

