#pragma once
#ifndef VECTOR
#define VECTOR

#include <iostream>
#include "Complex.h"

template <typename T, int M> class Vector {
private:
    T values[M] {};
public:
    Vector() {} 
    template<std::convertible_to<T>... Ts> requires (sizeof...(Ts) <= M)
        Vector(Ts &&... ts) : values{ static_cast<T>(ts)...} {};

    void print() const {
        std::cout << std::fixed << this << ":{\n";
        for (int i = 0; i < M; i++) {
            if (i != 0) std::cout << ", \n";
            std::cout << values[i];
        }
        std::cout << "\n}" << std::endl;
    }

    Vector<T, 3> crossProduct(const Vector<T, 3>& vector) const requires (M == 3 && (T == float || T == double)) {
        return Vector<T, 3>{values[1] * vector[2] - values[2] * vector[1],
                        values[2] * vector[0] - values[0] * vector[2],
                        values[0] * vector[1] - values[1] * vector[0]};
        //TODO: Not correct for complex numbers
    }

    T dotProduct(const Vector<T, M>& vector) const {
        T sum = 0;
        for (int i = 0; i < M; i++) {
            if (T == Complex) {
                sum += values[i] * vector[i].getConjugate();
            } else {
                sum += values[i] * vector[i];
            }
        }
        return sum;
    }

    Vector<M>& normalize() {
        float length = this->length();
        for (int i = 0; i < length; i++)
        {
            values[i] /= length;
        }
        return *this;
    }

    Vector<M> getNormalized() const {
        Vector<M> vec{ *this };
        float length = this->length();
        for (int i = 0; i < length; i++)
        {
            vec[i] /= length;
        }
        return vec;
    }

    float length() const {
        return std::sqrt(squareLength());
    }

    float squareLength() const {
        float sum{};
        for (int i = 0; i < M; i++) {
            sum += values[i].absoluteSquared();
        }
        return sum;
    }

    Vector<M> operator+(const float value) const {
        return Vector<M>{ *this } += value;
    }
    Vector<M>& operator+=(const float value) {
        for (int i = 0; i < M; i++) {
            values[i] += value;
        }
        return *this;
    }
    Vector<M> operator+(const Vector<M>& vector) const {
        return Vector<M>{ *this } += vector;
    }
    Vector<M>& operator+=(const Vector<M>& vector) {
        for (int i = 0; i < M; i++) {
            values[i] += vector[i];
        }
        return *this;
    }

    Vector<M> operator-(const float value) const {
        return Vector<M>{ *this } -= value;
    }
    Vector<M>& operator-=(const float value) {
        for (int i = 0; i < M; i++) {
            values[i] -= value;
        }
        return *this;
    }
    Vector<M> operator-(const Vector<M>& vector) const {
        return Vector<M>{ *this } -= vector;
    }
    Vector<M>& operator-=(const Vector<M>& vector) {
        for (int i = 0; i < M; i++) {
            values[i] -= vector[i];
        }
        return *this;
    }

    Vector<M> operator*(const float value) const {
        return Vector<M>{ *this } *= value;
    }
    Vector<M>& operator*=(const float value) {
        for (int i = 0; i < M; i++) {
            values[i] *= value;
        }
        return *this;
    }
    Vector<M> operator*(const Vector<M>& vector) const {
        return Vector<M>{ *this } *= vector;
    }
    Vector<M>& operator*=(const Vector<M>& vector) {
        for (int i = 0; i < M; i++) {
            values[i] *= vector[i];
        }
        return *this;
    }

    Vector<M> operator/(const float value) const {
        return Vector<M>{ *this } /= value;
    }
    Vector<M>& operator/=(const float value) {
        for (int i = 0; i < M; i++) {
            values[i] /= value;
        }
        return *this;
    }
    Vector<M> operator/(const Vector<M>& vector) const {
        return Vector<M>{ *this } /= vector;
    }
    Vector<M>& operator/=(const Vector<M>& vector) {
        for (int i = 0; i < M; i++) {
            values[i] /= vector[i];
        }
        return *this;
    }

    Complex& operator[](const int index) {
        return values[index];
    }

    Complex operator[](const int index) const {
        return values[index];
    }
};

#endif // !VECTOR
