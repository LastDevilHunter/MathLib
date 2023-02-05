#pragma once
#ifndef VECTOR
#define VECTOR

#include <iostream>

template <int M> class Vector {
private:
    float values[M] {};
public:
    Vector() {}
    template<std::convertible_to<float>... Ts> requires (sizeof...(Ts) <= M)
        Vector(Ts &&... ts) : values{ static_cast<float>(ts)...} {};

    void print() const {
        std::cout << std::fixed << this << ":{";
        for (int i = 0; i < M; i++) {
            if (i != 0) std::cout << ", ";
            std::cout << values[i];
        }
        std::cout << "}" << std::endl;
    }

    Vector<3> crossProduct(const Vector<3>& vector) const requires (M == 3) {
        return Vector<3>{values[1] * vector[2] - values[2] * vector[1],
                        values[2] * vector[0] - values[0] * vector[2],
                        values[0] * vector[1] - values[1] * vector[0]};
    }

    float dotProduct(const Vector<M> vector) const {
        float sum = 0;
        for (int i = 0; i < M; i++) {
            sum += values[i] * vector[i];
        }
        return sum;
    }

    Vector<M>& normalize() {
        float length = length();
        for (int i = 0; i < length; i++)
        {
            values[i] /= length;
        }
        return *this;
    }

    Vector<M> getNormalized() const {
        Vector<M> vec{ *this };
        float length = length();
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
            sum += values[i] * values[i];
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

    float& operator[](const int index) {
        return values[index];
    }

    float operator[](const int index) const {
        return values[index];
    }
};

#endif // !VECTOR
