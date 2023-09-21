#pragma once
#include <iostream>
class Matrix3D
{
private:
	double matrix[3][3];
public:
	Matrix3D(const double i1=0, const double i2=0, const double i3=0,
		const double i4=0, const double i5=0, const double i6=0, 
		const double i7=0,const double i8=0, const double i9=0);

	double det() const;

	Matrix3D inverse();
	void show_matrix();
	Matrix3D operator +(const Matrix3D& m) const;
	Matrix3D operator -(const Matrix3D& m) const;
	Matrix3D operator *(const Matrix3D& m) const;

	~Matrix3D();
};

