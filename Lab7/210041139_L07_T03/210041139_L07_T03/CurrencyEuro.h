#pragma once
class CurrencyEuro
{
private:
	int Euros;
	double Cents;
public:
	CurrencyEuro();
	CurrencyEuro(int euro, double cent);
	void print();

};

