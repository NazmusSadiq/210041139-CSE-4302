#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Student
{
    long long ID, Age, Semester;
    float GPA;
    string Name, Grade;
};

Student Tokenization(string &Line)
{
    Student Temp;
    string tempstr;
    long long id = 0, semester = 0;
    float gpa = 0;
    try
    {
        size_t CommaLocation = Line.find(';');
        tempstr = Line.substr(0, CommaLocation);
        id = stoll(tempstr);
        Line = Line.substr(CommaLocation + 1);
        CommaLocation = Line.find(';');
        tempstr = Line.substr(0, CommaLocation);
        gpa = stof(tempstr);
        Line = Line.substr(CommaLocation + 1);
        semester = stoll(Line);
    }
    catch (const std::invalid_argument &e)
    {
        // Handle the error or continue with a default value
    }

    Temp.ID = id;
    Temp.GPA = gpa;
    Temp.Semester = semester;

    return Temp;
}

int main()
{
    string temp;
    vector<Student> Students;
    float total = 0, avg;

    ifstream Input;
    Input.open("grades.txt");
    if (!Input.is_open())
    {
        cout << "Failed to open file for reading\n";
        return 1;
    }

    while (!Input.eof())
    {
        getline(Input, temp);
        Students.push_back(Tokenization(temp));
    }

    for (auto Element : Students)
    {
        total += Element.GPA;
    }
    avg = total / Students.size();

    cout << "Average GPA of the Students: " << avg << endl;
}