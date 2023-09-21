#pragma once
class Coordinate
{
private:
	float abscissa,ordinate;
public:
	Coordinate(const float abs = 0, const float ord = 0);
	float getDistance(Coordinate c);
	float getDistance();
	void move_x(float val);
	void move_y(float val);
	void move(float val);
	bool operator >( Coordinate& C);
	bool operator <(Coordinate& C);
	bool operator >=(Coordinate& C);
	bool operator <=(Coordinate& C);
	bool operator ==(Coordinate& C);
	bool operator !=(Coordinate& C);
	Coordinate operator ++();
	Coordinate operator ++(int);
	Coordinate operator --();
	Coordinate operator --(int);
	void display();
};

