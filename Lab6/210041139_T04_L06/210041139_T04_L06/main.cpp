#include <iostream>
#include "ZooAnimal.h"
int main()
{
	ZooAnimal A1( 2001, 1, 150, 5,"Lion");
	A1 += 5;
	A1.display();
}
