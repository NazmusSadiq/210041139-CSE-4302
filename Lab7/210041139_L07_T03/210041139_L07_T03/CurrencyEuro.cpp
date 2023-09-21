#include "CurrencyEuro.h"
#include <iostream>
CurrencyEuro::CurrencyEuro()
{
	Euros = 0;
	Cents = 0;
}

CurrencyEuro::CurrencyEuro(int euro, double cent)
{
	Euros = euro;
	Cents = cent;
}

void CurrencyEuro::print()
{
	std::cout << "Euro: " << Euros << " Cents: " << Cents << std::endl;
}
