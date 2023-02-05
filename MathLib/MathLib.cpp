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
	Matrix<2, 2> mat;
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[1][0] = 3;
	mat[1][1] = 4;
	auto arr = mat.computeEigenvalues2x2();
	std::get<0>(arr).print();
	std::get<1>(arr).print();
	/*Vector<3> v1 {1, 2, 3};
	Vector<3> v2 {4, 5, 6};
	cout << "Vector 1:" << endl;
	v1.print();
	cout << "Vector 2:" << endl;
	v2.print();
	cout << "Addition:" << endl;
	Vector<3> v3 = v1 + 2;
	v3.print();
	cout << "Subtraction:" << endl;
	(v1 - 2).print();
	cout << "Multiplication:" << endl;
	(v1 * 2).print();
	cout << "Division:" << endl;
	(v1 / 2).print();*/

	/*INPUT input[2]{};
	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = VK_LWIN;
	input[1].type = INPUT_KEYBOARD;
	input[1].ki.wVk = VK_LWIN;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;
	UINT uSent = SendInput(2, input, sizeof(INPUT));
	cout << uSent << endl;*/
}
