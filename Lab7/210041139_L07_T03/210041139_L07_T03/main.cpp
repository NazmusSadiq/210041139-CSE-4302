
#include <iostream>
#include "CurrencyEuro.h"
#include "CurrencyDollar.h"
#include "CurrencyBDT.h"

int main()
{
	CurrencyBDT bdt(4567,59.64);
	//CurrencyDollar usd;
	//CurrencyEuro euro;

	++bdt;
	--bdt;

}

