#include <iostream>
#include <string>
//#include <bits/stdc++.h>
const int MAX_COURSES = 5; // Maximum number of courses per student
using namespace std;
class Student
{
private:
    string firstName;
    string lastName;
    string studentId;
    int birthYear;
    string courses[MAX_COURSES];
    float obtainedMarks[MAX_COURSES];
    int numCourses;
    static int totalStudents;

public:
    Student(const string &firstName, const string &lastName, const string &studentId)
        : firstName(firstName), lastName(lastName), studentId(studentId), birthYear(0), numCourses(0)
    {
        totalStudents++;
    }

    void enrollInCourses(const string &courseName)
    {
        if (numCourses < MAX_COURSES)
        {
            courses[numCourses] = courseName;
            obtainedMarks[numCourses] = 0.0;
            numCourses++;
        }
        else
        {
            cout << "Maximum number of courses reached for student " << firstName << " " << lastName << endl;
        }
    }

    void setObtainedMarks(const string &courseName, float marks)
    {
        for (int i = 0; i < numCourses; ++i)
        {
            if (courses[i] == courseName)
            {
                obtainedMarks[i] = marks;
                break;
            }
        }
    }

    float setGPAForEachCourse()
    {
        if (numCourses == 0)
        {
            return 0.0;
        }

        float totalGPA = 0.0;
        for (int i = 0; i < numCourses; ++i)
        {
            totalGPA += obtainedMarks[i];
        }

        return totalGPA / (numCourses);
    }

    float displayCGPA()
    {
        return setGPAForEachCourse();
    }

    void willGraduate()
    {
        if (setGPAForEachCourse() >= 2.0)
        {
            cout << "Student " << firstName << " " << lastName << " will graduate." << endl;
        }
        else
        {
            cout << "Student " << firstName << " " << lastName << " will not graduate." << endl;
        }
    }

    void applyForScholarship()
    {
        if (setGPAForEachCourse() >3.8)
        {
            cout << "Student " << firstName << " " << lastName << " can apply for a scholarship." << endl;
        } else
        {
            cout << "Student " << firstName << " " << lastName << " is not eligible for a scholarship." << endl;
        }
    }

    void participateInInternship(const string &company)
    {
        bool hasCourseX = false;
        for (int i = 0; i < numCourses; ++i)
        {
            if (courses[i] == "X")
            {
                hasCourseX = true;
                break;
            }
        }

        if (setGPAForEachCourse() > 3.0 && hasCourseX)
        {
            cout << "Student " << firstName << " " << lastName << " can do an internship at " << company << "." << endl;
        }
        else
        {
            cout << "Student " << firstName << " " << lastName << " is not eligible for an internship at " << company << "." << endl;
        }
    }

    static int getTotalStudents()
    {
        return totalStudents;
    }

    ~Student()
    {
        cout << "Student Name: " << firstName << " " << lastName << endl;
        cout << "Student ID: " << studentId << endl;
        cout << "Courses Enrolled: ";
        for (int i = 0; i < numCourses; ++i)
        {
            cout << courses[i] << ", ";
        }
        cout << endl;
        cout << "CGPA: " << displayCGPA() << endl;
        cout << "Graduation Status: ";
        willGraduate();
        cout << "Scholarship Status: ";
        applyForScholarship();
    }
};

int Student::totalStudents = 0;

int main()
{
    Student student1("Nazmus", "Sadiq", "S001");
    student1.enrollInCourses("Math");
    student1.enrollInCourses("Science");
    student1.enrollInCourses("History");
    student1.setObtainedMarks("Math", 90.0);
    student1.setObtainedMarks("Science", 85.5);
    student1.setObtainedMarks("History", 75.0);

    Student student2("Ankon", "Ahamed", "S002");
    student2.enrollInCourses("Physics");
    student2.enrollInCourses("Chemistry");
    student2.enrollInCourses("Biology");
    student2.setObtainedMarks("Physics", 88.0);
    student2.setObtainedMarks("Chemistry", 92.5);
    student2.setObtainedMarks("Biology", 78.0);

    Student student3("Mohammad", "Rafee", "S003");
    student3.enrollInCourses("English");
    student3.enrollInCourses("Spanish");
    student3.enrollInCourses("French");
    student3.setObtainedMarks("English", 78.5);
    student3.setObtainedMarks("Spanish", 85.0);
    student3.setObtainedMarks("French", 90.0);

    cout << "Total Students: " << Student::getTotalStudents() << endl;

    student1.willGraduate();
    student2.willGraduate();
    student3.willGraduate();

    student1.applyForScholarship();
    student2.applyForScholarship();
    student3.applyForScholarship();

    student1.participateInInternship("Company A");
    student2.participateInInternship("Company B");
    student3.participateInInternship("Company C");

    return 0;
}