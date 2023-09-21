#include "CurrencyDollar.h"
#include <iostream>

CurrencyDollar::CurrencyDollar()
{
	Dollars = 0;
	Cents = 0;
}

CurrencyDollar::CurrencyDollar(int dollar, double cent)
{
	Dollars = dollar;
	Cents = cent;
}

void CurrencyDollar::print()
{
	std::cout << "Dollar: " << Dollars << " Cents: " << Cents << std::endl;

}
