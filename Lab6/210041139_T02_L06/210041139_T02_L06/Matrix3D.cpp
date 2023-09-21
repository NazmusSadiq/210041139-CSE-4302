#include "Matrix3D.h"

Matrix3D::Matrix3D(const double i1, const double i2, const double i3, const double i4, const double i5, const double i6, const double i7, const double i8, const double i9)
{
	matrix[0][0] = i1;
	matrix[0][1] = i2;
	matrix[0][2] = i3;
	matrix[1][0] = i4;
	matrix[1][1] = i5;
	matrix[1][2] = i6;
	matrix[2][0] = i7;
	matrix[2][1] = i8;
	matrix[2][2] = i9;
}

double Matrix3D::det() const
{
	double a1 = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]));
	double a2= matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]));
	double a3 = matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]));

	return a1 - a2 + a3;
}

Matrix3D Matrix3D::inverse()
{
	double adj[3][3];
	adj[0][0] = (matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]);
	adj[0][1] = -((matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]));
	adj[0][2] = (matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]);
	adj[1][0] = -((matrix[0][1] * matrix[2][2]) - (matrix[0][2] * matrix[2][1]));
	adj[1][1] = (matrix[0][0] * matrix[2][2]) - (matrix[0][2] * matrix[2][0]);
	adj[1][2] = -((matrix[0][0] * matrix[2][1]) - (matrix[0][1] * matrix[2][0]));
	adj[2][0] = (matrix[0][1] * matrix[1][2]) - (matrix[0][2] * matrix[1][1]);
	adj[2][1] = -((matrix[0][0] * matrix[1][2]) - (matrix[0][2] * matrix[1][0]));
	adj[2][2] = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

	double determinant = det();
	return Matrix3D(adj[0][0]/determinant, adj[0][1] / determinant, adj[0][2] / determinant, adj[1][0] / determinant,
		adj[1][1] / determinant, adj[1][2] / determinant, adj[2][0] / determinant, adj[2][1] / determinant, adj[2][2] / determinant);
}

void Matrix3D::show_matrix()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << '\n';
	}
}

Matrix3D Matrix3D::operator+(const Matrix3D& m) const
{
	double ans[3][3];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			ans[i][j] = 0;
		}
	}	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ans[i][j] = matrix[i][j] + m.matrix[i][j];
		}
	}
	return Matrix3D(ans[0][0], ans[0][1], ans[0][2], ans[1][0], 
		ans[1][1], ans[1][2], ans[2][0], ans[2][1], 
		ans[2][2] );
}
Matrix3D Matrix3D::operator-(const Matrix3D& m) const
{
	double ans[3][3];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			ans[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ans[i][j] = matrix[i][j] - m.matrix[i][j];
		}
	}
	return Matrix3D(ans[0][0], ans[0][1], ans[0][2], ans[1][0],
		ans[1][1], ans[1][2], ans[2][0], ans[2][1],
		ans[2][2]);
}
Matrix3D Matrix3D::operator*(const Matrix3D& m) const
{
	double ans[3][3];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			ans[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
			{
				ans[i][j] += matrix[i][k] * m.matrix[k][j];
			}
	return Matrix3D(ans[0][0], ans[0][1], ans[0][2], ans[1][0],
		ans[1][1], ans[1][2], ans[2][0], ans[2][1],
		ans[2][2]);
}

Matrix3D::~Matrix3D()
{
	std::cout << "Object destroyed" << std:: endl;
}
