#pragma once

class CurrencyBDT
{
private:
	int Tk;
	double Poisha;

public:
	CurrencyBDT();
	CurrencyBDT(int tk, double poisha);
	void operator ++ () ;
	void operator -- () ;

};

