#include <iostream>
#include <cmath>
using namespace std;

class Rectangle
{
private:
    float length;
    float width;

public:
    Rectangle()
    {
        length = 1;
        width = 1;
    }
    Rectangle(float len, float wid)
    {
        if (len > 0 && wid > 0)
        {
            length = 1;
            width = 1;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    void set_len(float len)
    {
        if (len > 0 && len < 20)
            length = len;
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    float get_len()
    {
        return length;
    }
    void set_width(float wid)
    {
        if (wid > 1 && wid < 20)
            width = wid;
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    float get_wid()
    {
        return width;
    }
    float Perimeter()
    {
        return 2 * (length + width);
    }
    float Area()
    {
        return length * width;
    }
    float Diagonal()
    {
        return sqrt((length * length) + (width * width));
    }
    float Angle()
    {
        return atan(width / length) * 180 / 3.1416;
    }
};

int main()
{
    Rectangle Rec1;
    Rec1.set_len(-5);
    Rec1.set_width(23);
    cout << "Perimeter is: " << Rec1.Perimeter() << endl;
    cout << "Diagonal Length is: " << Rec1.Diagonal() << endl;
    cout << "Area is: " << Rec1.Area() << endl;
    cout << "Angle(Degree) Between Length and Diagonal is: " << Rec1.Angle() << endl;
    // Rectangle Rec2(1.9, 1.5);
    // cout << "Perimeter is: " << Rec2.Perimeter() << endl;
    // cout << "Diagonal Length is: " << Rec2.Diagonal() << endl;
    // cout << "Area is: " << Rec2.Area() << endl;
    // cout << "Angle(Degree) Between Length and Diagonal is: " << Rec2.Angle() << endl;
}