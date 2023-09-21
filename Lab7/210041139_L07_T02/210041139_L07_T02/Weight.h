#pragma once

class Weight
{
private:
	double kgToPound;
	int pound;
	double ounce;
public:
	Weight();
	Weight(double kg);
	Weight(int pound, double ounce);
	void showWeight();
	operator double() const;
};

