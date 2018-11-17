#include "complex.h"

cgmath::complex::complex() : real(0.0f), imag(0.0f)
{
}

cgmath::complex::complex(float real, float imag) : real(real), imag(imag)
{
}

void cgmath::complex::print() const
{
	std::cout << real << " + " << imag << "i" << std::endl;
}

void cgmath::complex::add(const cgmath::complex& other)
{
	real += other.real;
	imag += other.imag;
}

cgmath::complex& cgmath::complex::operator+=(const cgmath::complex& other)
{
	real += other.real;
	imag += other.imag;

	return *this;
}

cgmath::complex cgmath::complex::add(const cgmath::complex& a, const cgmath::complex& b)
{
	return cgmath::complex(a.real + b.real, a.imag + b.imag);
}