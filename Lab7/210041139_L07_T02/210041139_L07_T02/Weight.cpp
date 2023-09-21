#include "Weight.h"
#include <iostream>

Weight::Weight()
{
	kgToPound = 2.205;
}

Weight::Weight(double kg)
{
	kgToPound = 2.205;
	pound = kg * kgToPound;
	ounce = (kg * kgToPound)-pound;
	
}

Weight::Weight(int pound, double ounce)
{
	kgToPound = 2.205;
	int new_pound = ounce / 16;
	this->pound = pound + new_pound;
	this->ounce = ounce-new_pound*16;
}

void Weight::showWeight()
{
	std::cout << "Pound: " << pound << " Ounce: " << ounce<<std::endl;
}

Weight::operator double() const
{
	double total_pound = pound+ ounce/16;
	double kg = total_pound / kgToPound;
	return kg;
}
