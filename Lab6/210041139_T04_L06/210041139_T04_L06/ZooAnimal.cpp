#include "ZooAnimal.h"

bool ZooAnimal::operator>(const ZooAnimal& Z) const
{
    return weightData > Z.weightData;
}
bool ZooAnimal::operator<(const ZooAnimal& Z) const
{
    return weightData < Z.weightData;
}
bool ZooAnimal::operator>=(const ZooAnimal& Z) const
{
    return weightData >= Z.weightData;
}
bool ZooAnimal::operator<=(const ZooAnimal& Z) const
{
    return weightData <= Z.weightData;
}
bool ZooAnimal::operator==(const ZooAnimal& Z) const
{
    return weightData == Z.weightData;
}
bool ZooAnimal::operator!=(const ZooAnimal& Z) const
{
    return weightData != Z.weightData;
}

ZooAnimal ZooAnimal::operator+=(const int wd)
{
    this->weightData += wd;
    return *this;
}

void ZooAnimal::display()
{
    cout << "Name: " << nameOfAnimal << endl;
    cout << "Birth Year: " << birthYear << endl;
    cout << "Cage Number: " << cageNumber << endl;
    cout <<"Weight: "<< weightData << endl;
    cout << "Height: " << height << endl;

}
