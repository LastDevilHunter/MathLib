#include "MathLib.h"
#include "LinearAlgebra/Vector.h"
#include "LinearAlgebra/Matrix.h"
#include "LinearAlgebra/Complex.h"
#include <Windows.h>

using namespace std;

int main()
{
	/*Complex c1{ 1, 2 };
	Complex c2{ 3, 4 };
	(c1 + c2).print();
	c1.print();
	c2.print();*/

	/*Complex c{1, 2};
	Complex c1 = c.getConjugate();
	c.print();
	c1.print();
	(c * c1).print();
	float magnitude = c.absolute();
	printf("|c| = %f", magnitude);*/

	/*Matrix<2, 2> mat;
	mat[0][0] = 1;
	mat[0][1] = -2;
	mat[1][0] = 2;
	mat[1][1] = 4;
	array arr = mat.computeEigenvalues2x2();
	arr.at(0).print();
	arr.at(1).print();*/

	Vector<3> v1 {1.f, 2.f, 3.f};
	Vector<3> v2 {4.f, 5.f, 6.f};
	cout << "Vector 1:" << endl;
	v1.print();
	cout << "Vector 2:" << endl;
	v2.print();
	cout << "Addition:" << endl;
	(v1 + v2).print();
	cout << "Subtraction:" << endl;
	(v1 - v2).print();
	cout << "Multiplication:" << endl;
	(v1 * v2).print();
	cout << "Division:" << endl;
	(v1 / v2).print();

	/*INPUT input[2]{};
	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = VK_LWIN;
	input[1].type = INPUT_KEYBOARD;
	input[1].ki.wVk = VK_LWIN;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;
	UINT uSent = SendInput(2, input, sizeof(INPUT));
	cout << uSent << endl;*/
}
