#pragma once


#include <iostream>
#include "vec3.h"
#include <cmath>

namespace cgmath
{
	class mat3

	{
	private: float n[3][3] = { 0 };
	public:


		// Constructor que inicializa las viariables de instancia a sus valores por default.
		mat3();

		// Constructor que inicializa las variables de instancia utilizando el parametro diagonal
		mat3(float diagonal);

		//Constructor que inicializa las variables de instancia utilizando los parametros a,b y c
		mat3(const vec3& a, const vec3& b, const vec3& c);

		//Permite tener acceso de escritura a los vectores columna almacenados en esta matriz utilizando un índice
		vec3& operator[](int column);

		//Realiza una comparación de la instancia actual de mat3 con la matriz m.
		const bool operator==(const mat3& m);

		//Calcula y regresa el determinante de la matriz 3x3
		float determinant(const mat3& m);

		//Calcula la matriz inversa de la matriz 3x3 m y la regresa como un nuevo objeto mat3
		mat3 inverse(const mat3& m);

		//Transpuesta
		mat3 transpose(const mat3& m);

		//Adjunta
		mat3 adjunta(const mat3& m);

		// Crea un string en representación en texto de la instancia sobre la cual se manda a llamar.

		friend std::ostream& operator<<(std::ostream& os, const mat3&  m)
		{

		}

		//Permite realizar una multiplicación entre una matriz 3x3 y un vector columna de 3 componentes
		inline vec3 operator*(const mat3& m, const vec3& v)
		{
			int a = (m[0][0] * v[0]) + (m[0][1] * v[1]) + (m[0][2] * v[2]);
			int b = (m[1][0] * v[0]) + (m[1][1] * v[1]) + (m[1][2] * v[2]);
			int c = (m[2][0] * v[0]) + (m[2][1] * v[1]) + (m[2][2] * v[2]);

			return(a, b, c);
		}

		//Permite realizar una multiplicación entre una matriz 3x3 y una matriz 3x3
		inline mat3 operator*(const mat3& m1, const mat3& m2)
		{
			mat3 multiplicacion;
			multiplicacion[0][0] = (m1[0][0] * m2[0][0]) + (m1[0][1] * m2[1][0]) + (m1[0][2] * m2[2][0]);
			multiplicacion[0][1] = (m1[0][0] * m2[0][1]) + (m1[0][1] * m2[1][1]) + (m1[0][2] * m2[2][1]);
			multiplicacion[0][2] = (m1[0][0] * m2[0][2]) + (m1[0][1] * m2[1][2]) + (m1[0][2] * m2[2][2]);
			multiplicacion[1][0] = (m1[1][0] * m2[0][0]) + (m1[1][1] * m2[1][0]) + (m1[1][2] * m2[2][0]);
			multiplicacion[1][1] = (m1[1][0] * m2[0][1]) + (m1[1][1] * m2[1][1]) + (m1[1][2] * m2[2][1]);
			multiplicacion[1][2] = (m1[1][0] * m2[0][2]) + (m1[1][1] * m2[1][2]) + (m1[1][2] * m2[2][2]);
			multiplicacion[2][0] = (m1[2][0] * m2[0][1]) + (m1[2][1] * m2[1][0]) + (m1[2][2] * m2[2][0]);
			multiplicacion[2][1] = (m1[2][0] * m2[0][2]) + (m1[2][1] * m2[1][1]) + (m1[2][2] * m2[2][1]);
			multiplicacion[2][2] = (m1[2][0] * m2[0][3]) + (m1[2][1] * m2[1][2]) + (m1[2][2] * m2[2][2]);

			return multiplicacion;
		}

	};


}