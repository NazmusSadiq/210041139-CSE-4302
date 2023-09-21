#pragma once
#include <iostream>
using namespace std;

class StudentCollection
{
    private:
        string names[10];
        double grades[10];
        int count;

    public:
        StudentCollection();

        double& operator[](const string& name);

        void operator()(const string& name,const double &grade);

        void addStudent(const string& name,const double &grade);

        void print();

};

