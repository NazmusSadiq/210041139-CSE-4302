#pragma once
#include <iostream>

using namespace std;

class ZooAnimal
{
private:
	int birthYear;
	int cageNumber;
	float weightData;
	int height;
	string nameOfAnimal;
public:
	ZooAnimal(int by, int cn, float wd, int ht, string name)
	{
		birthYear = by;
		cageNumber = cn;
		weightData = wd;
		height = ht;
		nameOfAnimal = name;
	}

	bool operator>(const ZooAnimal& Z) const;
	bool operator<(const ZooAnimal& Z) const;
	bool operator>=(const ZooAnimal& Z) const;
	bool operator<=(const ZooAnimal& Z) const;
	bool operator==(const ZooAnimal& Z) const;
	bool operator!=(const ZooAnimal& Z) const;
	ZooAnimal operator+=(const int wd);
	void display();

};

