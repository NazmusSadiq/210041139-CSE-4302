#include "CurrencyBDT.h"
#include "CurrencyDollar.h"
#include "CurrencyEuro.h"

CurrencyBDT::CurrencyBDT()
{
	Tk = 0;
	Poisha = 0;
}

CurrencyBDT::CurrencyBDT(int tk, double poisha)
{
	Tk = tk;
	Poisha = poisha;
}

void CurrencyBDT::operator++() 
{
	int dollar = Tk * 0.0091;
	double d_dollar = Tk * 0.0091 - dollar;
	double cent = Poisha * 0.0091+d_dollar;
	CurrencyDollar d(dollar,cent);
	d.print();
}

void CurrencyBDT::operator--() 
{
	int euro = Tk * 0.0085;
	double d_euro = Tk * 0.0085 - euro;
	double cent = Poisha * 0.0085 + d_euro;
	CurrencyEuro e(euro, cent);
	e.print();
}

