#pragma once
class CurrencyDollar
{
private:
	int Dollars;
	double Cents;
public:
	CurrencyDollar();
	CurrencyDollar(int dollar, double cent);
	void print();
};

