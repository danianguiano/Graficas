#pragma once

#include <iostream>
#include <cmath>

namespace cgmath
{
	class vec3
	{
	public:

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		// Constructor por default.
		vec3();
		// Constructor con 2 parámetros.
		vec3(float x, float y, float z);

		// Escritura de las variables
		float& operator[](int i);

		//Multiplica cada una de las variables de instancia por el valor escalar s.
		vec3& operator*=(float s);


		//Divide cada una de las variables de instancia por el valor escalar s.
		vec3& operator/=(float s);


		//Suma cada una de las variables de instanciacon la componente correspondiente de v.
		vec3& operator+=(const vec3& v);

		//Resta cada una de las variables de instancia con la componente correspondiente de v.
		vec3& operator-=(const vec3& v);

		//Realiza una comparación de la instancia actual de vec3 con el vecto v.
		const bool operator==(const vec3 v);

		//Calcula y regresa la magnitud de la instancia sobre la cual se manda a llamar.
		const float magnitude();

		//Normaliza el vector de la instancia sobre la cual se manda a llamar.
		void normalize();

		//Calcula y regresa la magnitud del vector v
		float magnitude(const vec3& v);

		//Calcula y regresa la magnitud del vector v
		vec3 normalize(const vec3& v);

		//Calcula y regresa el producto punto entre los vectores a y b
		float dot(const vec3& a, const vec3& b);

		// Calcula y regresa el producto cruz entre los vectores a y b.
		float cross(const vec3& a, const vec3& b);

		//Crea un string con la representación en texto de la instancia sobre la cual se manda a llamar.
		friend std::ostream& operator<<(std::ostream& os, vec3& const v)
		{
			os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
			return os;
		}

		//Permite realizar una multiplicación entre un vector y un escalar.
		inline vec3 operator*(const vec3& v, float s)
		{
			v.x = v.x* s;
			v.y = v.y * s;
			v.z = v.z * s;
			return v;
		}


		//Habilita la propiedad conmutativa de la multiplicación entre un vector y un escalar.
		inline vec3 operator*(float s, const vec3& v)
		{
			v.x = v.x * s;
			v.y = v.y * s;
			v.z = v.z * s;
			return v;
		}

		//Permite realizar una división enrre un vector y un escalar
		inline vec3 operator/(const vec3& v, float s)
		{
			v.x = v.x / s;
			v.y = v.y / s;
			v.z = v.z / s;
			return v;
		}

		//Permite realizar una suma entre dos vectore
		inline vec3 operator+(const vec3& a, const vec3& b)
		{
			return(a.x + b.x, a.y + b.y, a.z + b.z);
		}

		//Permite realizar una resta entre dos vectores
		inline vec3 operator-(const vec3& a, const vec3& b)
		{
			return(a.x - b.x, a.y - b.y, a.z - b.z);
		}

		//Permite negar las componentes del vector v.
		inline vec3 operator-(const vec3& v)
		{
			vec3 nuevo;
			nuevo.x = v.x*-1;
			nuevo.y = v.y*-1;
			nuevo.z = v.z*-1;

			return nuevo;
		}

	};


}