﻿#include "MathLib.h"
#include "Vector/Vector.h"

using namespace std;

int main()
{
	float test[] { 2, 4, 8 };
	Vector<3> v1 = Vector<3>(1.f, 2.f, 3.f);
	v1.print();
	v1[0] = 2;
	v1.print();
	//(v1 / 2).print();
	//std::cout << v1.length() << std::endl;
}
