
#include <iostream>
#include "Coordinate.h"

using namespace std;

int main()
{
	Coordinate c1(5, 5);
	cout<<c1.getDistance()<<endl;
	Coordinate c2(7, 7);
	cout << c1.getDistance(c2) << endl;
	c1++;
	c1.display();
	cout << boolalpha << (c1 > c2) << endl;
}

