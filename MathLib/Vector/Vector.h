#pragma once
#ifndef VECTOR
#define VECTOR

#include <iostream>

template <int M> class Vector
{
private:
    float values[M] {};
public:
    Vector() {};
    template<std::convertible_to<float>... Ts> requires (sizeof...(Ts) == M)
        Vector(Ts &&... ts) : values{ ts... } {}

    /*Vector(const float* values) {
        for (int i = 0; i < M; i++)
        {
            this->values[i] = values[i];
        }
        
    };*/

    void print() const {
        std::cout << std::fixed << this << ":{";
        for (int i = 0; i < M; i++)
        {
            if (i != 0) std::cout << ", ";
            std::cout << values[i];
        }
        std::cout << "}" << std::endl;
    }

    /*Vector crossProduct(Vector<3>& vector) requires (M == 3) {
        return Vector<3> vec{};
    }*/

    float length() const {
        return std::sqrt(squareLength());
    }

    float squareLength() const {
        float sum {};
        for (int i = 0; i < M; i++)
        {
            sum += values[i] * values[i];
        }
        return sum;
    }

    Vector<M> operator+(float vector) const {
        Vector<M> vec{ *this };
        vec += vector;
        return vec;
    }
    Vector<M> operator+=(float vector) {
        for (int i = 0; i < M; i++)
        {
            values[i] += vector;
        }
        return *this;
    }
    Vector<M> operator+(const Vector<M>& vector) const {
        Vector<M> vec{ *this };
        vec += vector;
        return vec;
    }
    Vector<M>& operator+=(const Vector<M>& vector) {
        for (int i = 0; i < M; i++) {
            values[i] += vector[i];
        }
        return *this;
    }

    Vector<M> operator-(float vector) const {
        Vector<M> vec{ *this };
        vec -= vector;
        return vec;
    }
    Vector<M> operator-=(float vector) {
        for (int i = 0; i < M; i++)
        {
            values[i] -= vector;
        }
        return *this;
    }
    Vector<M> operator-(const Vector<M>& vector) const {
        Vector<M> vec{ *this };
        vec -= vector;
        return vec;
    }
    Vector<M>& operator-=(const Vector<M>& vector) {
        for (int i = 0; i < M; i++) {
            values[i] -= vector[i];
        }
        return *this;
    }

    Vector<M> operator*(float vector) const {
        Vector<M> vec{ *this };
        vec *= vector;
        return vec;
    }
    Vector<M> operator*=(float vector) {
        for (int i = 0; i < M; i++)
        {
            values[i] *= vector;
        }
        return *this;
    }
    Vector<M> operator*(const Vector<M>& vector) const {
        Vector<M> vec{ *this };
        vec *= vector;
        return vec;
    }
    Vector<M>& operator*=(const Vector<M>& vector) {
        for (int i = 0; i < M; i++) {
            values[i] *= vector[i];
        }
        return *this;
    }

    Vector<M> operator/(float vector) const {
        Vector<M> vec{ *this };
        vec /= vector;
        return vec;
    }
    Vector<M> operator/=(float vector) {
        for (int i = 0; i < M; i++)
        {
            values[i] /= vector;
        }
        return *this;
    }
    Vector<M> operator/(const Vector<M>& vector) const {
        Vector<M> vec{ *this };
        vec /= vector;
        return vec;
    }
    Vector<M>& operator/=(const Vector<M>& vector) {
        for (int i = 0; i < M; i++) {
            values[i] /= vector[i];
        }
        return *this;
    }

    float operator[](int index) const {
        return values[index];
    }
};
#endif // !VECTOR
