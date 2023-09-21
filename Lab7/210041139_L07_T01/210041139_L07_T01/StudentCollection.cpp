#include "StudentCollection.h"

StudentCollection::StudentCollection()
{
    count = 0;
}

double& StudentCollection::operator[](const string& name)
{
    for (int i = 0; i < count; ++i) 
    {
        if (names[i] == name) 
        {
            return grades[i];
        }
    }
}

void StudentCollection:: operator()(const string& name,const double &grade)
{
    for (int i = 0; i < count; ++i) 
    {
        if (names[i] == name) 
        {
            grades[i] = grade;
            return;
        }
    }
    cout << "Student not found" << endl;
}
void StudentCollection:: addStudent(const std::string& name,const double &grade)
{
    if (count >= 10) 
    {
        cout << "Maximum Student amount reached" << endl;
        return;
    }
    names[count] = name;
    grades[count] = grade;
    count++;
}

void StudentCollection::print()
{
    for (int i = 0; i < count; i++)
    {
        cout << "Name: " << names[i] << " Grade: " << grades[i] << endl;
    }
}
