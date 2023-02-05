#pragma once
#ifndef COMPLEX
#define COMPLEX

#include <iostream>

class Complex {
private:
	float real;
	float imaginary;
public:
	Complex() {
		real = 0;
		imaginary = 0;
	}
	Complex(float real, float imaginary) : real{ real }, imaginary { imaginary } {}

	void print() {
		std::cout << this << ":{real: " << real << ", imaginary: " << imaginary << "}" << std::endl;
	}

	float magnitude() {
		return sqrt(real * real + imaginary * imaginary);
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
		real *= complex.real;
		real -= imaginary * complex.imaginary;
		imaginary *= complex.real;
		imaginary += real * complex.imaginary;
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
};

#endif // !COMPLEX