#pragma once
#ifndef COMPLEX
#define COMPLEX

#include <iostream>

class Complex {
private:
	float real;
	float imaginary;
public:
	Complex() : real{}, imaginary{} {}
	Complex(float value) : real{value}, imaginary{} {}
	Complex(float real, float imaginary) : real{ real }, imaginary{ imaginary } {}

	void print() {
		std::cout << this << ":{real: " << real << ", imaginary: " << imaginary << "}" << std::endl;
	}

	float absolute() const {
		return sqrt(real * real + imaginary * imaginary);
	}

	float absoluteSquared() const {
		return real * real + imaginary * imaginary;
	}

	bool isReal() const {
		return imaginary == 0;
	}

	Complex getConjugate() const {
		return Complex{ real, -imaginary };
	}

	Complex operator+(const float number) const {
		return Complex{ *this } += number;
	}
	Complex& operator+=(const float number) {
		real += number;
		return *this;
	}
	Complex operator+(const Complex& complex) const {
		return Complex{ *this } += complex;
	}
	Complex& operator+=(const Complex& complex) {
		real += complex.real;
		imaginary += complex.imaginary;
		return *this;
	}

	Complex operator-(const float number) const {
		return Complex{ *this } -= number;
	}
	Complex& operator-=(const float number) {
		real -= number;
		return *this;
	}
	Complex operator-(const Complex& complex) const {
		return Complex{ *this } -= complex;
	}
	Complex& operator-=(const Complex& complex) {
		real -= complex.real;
		imaginary -= complex.imaginary;
		return *this;
	}

	Complex operator*(const float number) const {
		return Complex{ *this } *= number;
	}
	Complex& operator*=(const float number) {
		real *= number;
		imaginary *= number;
		return *this;
	}
	Complex operator*(const Complex& complex) const {
		return Complex{ *this } *= complex;
	}
	Complex& operator*=(const Complex& complex) {
		float temp = real;
		real *= complex.real;
		real -= imaginary * complex.imaginary;
		imaginary *= complex.real;
		imaginary += temp * complex.imaginary;
		return *this;
	}

	Complex operator/(const float number) const {
		return Complex{ *this } /= number;
	}
	Complex& operator/=(const float number) {
		real /= number;
		imaginary /= number;
		return *this;
	}
	Complex operator/(const Complex& complex) const {
		return Complex{ *this } /= complex;
	}
	Complex& operator/=(const Complex& complex) {
		float temp = real;
		float absSquare = complex.absoluteSquared();
		real *= complex.real;
		real += imaginary * complex.imaginary;
		real /= absSquare;
		imaginary *= complex.real;
		imaginary -= temp * complex.imaginary;
		imaginary /= absSquare;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
		return os << std::fixed << &complex << ":{real: " << complex.real << ", imaginary: " << complex.imaginary << "}";
	}
};

#endif // !COMPLEX