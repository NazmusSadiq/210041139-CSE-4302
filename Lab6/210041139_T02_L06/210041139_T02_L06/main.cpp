
#include <iostream>
#include "Matrix3D.h"

using namespace std;

int main()
{
    Matrix3D mat1(1, 4, 3, 3, 7, 5, 7, 6, 5);
    cout <<"Determinant is: "<< mat1.det() << endl;
    Matrix3D mat2 = mat1.inverse();
    mat2.show_matrix();
    Matrix3D mat3 = mat1 + mat2;
    cout << "After addition: " << endl;
    mat3.show_matrix();
    Matrix3D mat4 = mat1 - mat2;
    cout << "After subtraction: " << endl;
    mat4.show_matrix();
    Matrix3D mat5 = mat1 * mat1;
    cout << "After multiplication: " << endl;
    mat5.show_matrix();
}

