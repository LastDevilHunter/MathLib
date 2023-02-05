#pragma once
#ifndef MATRIX
#define MATRIX

#include <tuple>
#include <array>
#include "Complex.h"

template <int M, int N> class Matrix {
private:
	float values[M][N] {};
public:
	Matrix() {}

	std::tuple<Complex, Complex> computeEigenvalues2x2() const requires (M == 2 && N == 2) {
		float b = -values[0][0] - values[1][1];
		float discriminant = b * b - 4 * determinant2x2();
		printf("b: %f\n", b);
		printf("discriminant: %f\n", discriminant);
		if (discriminant < 0) {
			return { Complex {-b, sqrt(-discriminant)} /= 2, Complex {-b, -sqrt(-discriminant)} /= 2 };
		} else if (discriminant == 0) {
			return { Complex {-b / 2, 0}, Complex {0, 0} };
		} else {
			float root = sqrt(discriminant);
			return { Complex {(-b + root) / 2, 0}, Complex {(-b - root) / 2, 0} };
		}
	}

	float determinant2x2() const requires (M == 2 && N == 2) {
		return values[0][0] * values[1][1] - values[0][1] * values[1][0];
	}

	float determinant3x3() const requires (M == 3 && N == 3) {
		return values[0][0] * values[1][1] * values[2][2]
			+ values[0][1] * values[1][2] * values[2][0]
			+ values[0][2] * values[1][0] * values[2][1]
			- (values[2][0] * values[1][1] * values[0][2]
				+ values[2][1] * values[1][2] * values[0][0]
				+ values[2][2] * values[1][0] * values[0][1]);
	}

	bool& isSymmetric() const requires (M == N) {
		bool symmetric = true;
		for (int n = 1; n < M; n++) {
			for (int m = 0; m < n; m++) {
				if (values[m][n] != values[n][m]) symmetric = false;
				printf("%f == %f\n", values[m][n], values[n][m]);
			}
		}
		return symmetric;
	}

	float trace() const requires (M == N) {
		float sum{};
		for (int i = 0; i < N; i++) {
			sum += values[i][i];
		}
		return sum;
	}

	//Matrix<N, M>& transpose() {
	//	...
	//}

	Matrix<M, N> operator+(Matrix<M, N>& matrix) const {
		return Matrix<M, N> { *this } += matrix;
	}
	Matrix<M, N>& operator+=(Matrix<M, N>& matrix) {
		for (int m = 0; m < M; m++) {
			for (int n = 0; n < N; n++) {
				values[m][n] += matrix[m][n];
			}
		}
		return *this;
	}

	Matrix<M, N> operator-(Matrix<M, N>& matrix) const {
		return Matrix<M, N> { *this } -= matrix;
	}
	Matrix<M, N>& operator-=(Matrix<M, N>& matrix) {
		for (int m = 0; m < M; m++) {
			for (int n = 0; n < N; n++) {
				values[m][n] -= matrix[m][n];
			}
		}
		return *this;
	}

	float* operator[](int index) {
		return values[index];
	}
};

#endif // !MATRIX