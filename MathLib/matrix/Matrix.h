#pragma once
#ifndef MATRIX
#define MATRIX

template <int M, int N> class Matrix
{
private:
	float values[M][N] {};
public:
	Matrix();
	~Matrix();
};

#endif // !MATRIX