#include "Coordinate.h"
#include <cmath>
#include <iostream>
using namespace std;

Coordinate::Coordinate(const float abs, const float ord)
{
	abscissa = abs;
	ordinate = ord;
}

float Coordinate::getDistance(Coordinate c)
{
	float dis = sqrt(pow((abscissa - c.abscissa),2)+
		pow((ordinate - c.ordinate),2));
	return dis;
}

float Coordinate::getDistance()
{
	float dis = sqrt(pow((abscissa - 0), 2) +
		pow((ordinate - 0), 2));
	return dis;
}

void Coordinate::move_x(float val)
{
	abscissa += val;
}

void Coordinate::move_y(float val)
{
	ordinate += val;
}

void Coordinate::move(float val)
{
	move_x(val);
	move_y(val);
}

bool Coordinate::operator>( Coordinate& C) 
{
	double d1 = getDistance();
	double d2 = C.getDistance();
	return d1 > d2;
}
bool Coordinate::operator<(Coordinate& C)
{
	double d1 = getDistance();
	double d2 = C.getDistance();
	return d1 < d2;
}
bool Coordinate::operator>=(Coordinate& C)
{
	double d1 = getDistance();
	double d2 = C.getDistance();
	return d1 >= d2;
}
bool Coordinate::operator<=(Coordinate& C)
{
	double d1 = getDistance();
	double d2 = C.getDistance();
	return d1 <= d2;
}
bool Coordinate::operator==(Coordinate& C)
{
	double d1 = getDistance();
	double d2 = C.getDistance();
	return d1 == d2;
}
bool Coordinate::operator!=(Coordinate& C)
{
	double d1 = getDistance();
	double d2 = C.getDistance();
	return d1 != d2;
}

Coordinate Coordinate::operator++()
{
	return Coordinate(abscissa,ordinate);
	move(1);
}

Coordinate Coordinate::operator++(int)
{
	move(1);
	return Coordinate(abscissa, ordinate);
}
Coordinate Coordinate::operator--()
{
	move(-1);
	return Coordinate(abscissa, ordinate);
}
Coordinate Coordinate::operator--(int)
{
	move(-1);
	return Coordinate(abscissa, ordinate);
}

void Coordinate::display()
{
	std::cout << "Abscissa: " << abscissa << " Ordinate: " << ordinate << std::endl;
}
