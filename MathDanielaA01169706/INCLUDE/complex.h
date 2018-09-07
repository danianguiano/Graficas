#pragma once

#include <iostream>

namespace cgmath
{
	class complex
	{
	public:
		// Estas dos variables se guardan en memoria de manera contigua.
		// Sólo las variables se almacenan, los métodos no.
		float real;
		float imag;

		// Constructor por default.
		complex();
		// Constructor con 2 parámetros.
		complex(float real, float imag);

		// Forma de imprimir esta clase; común en otros lenguajes.
		void print() const;
		// Forma preferida en C++ de imprimir esta clase.
		friend inline std::ostream& operator<<(std::ostream& os, const complex& c)
		{
			os << c.real << " + " << c.imag << "i";
			return os;
		}

		// Forma de sumar (+=) dos números complejos; común en otros lenguajes.
		void add(const complex& other);
		// Forma preferida en C++ de sumar (+=) dos números complejos.
		complex& operator+=(const complex& other);

		// Forma de sumar (+) dos números complejos; común en otros lenguajes.
		static complex add(const complex& a, const complex& b);
	};

	// Forma preferida en C++ de sumar (+) dos números complejos.
	inline complex operator+(const complex& a, const complex& b)
	{
		return complex(a.real + b.real, a.imag + b.imag);
	}
}