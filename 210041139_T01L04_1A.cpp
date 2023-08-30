#include <iostream>

using namespace std;

class Calculator
{
private:
    int Current_Value;

public:
    Calculator()
    {
        Current_Value = 0;
    }
    Calculator(int val)
    {
        Current_Value = val;
    }
    int getValue()
    {
        return Current_Value;
    }
    void setValue(int val)
    {
        Current_Value = val;
        //display();
    }
    void add(int Value)
    {
        Current_Value += Value;
        display();
    }
    void subtract(int Value)
    {
        Current_Value -= Value;
        display();
    }
    void multiply(int Value)
    {
        Current_Value *= Value;
        display();
    }
    void divideBy(int Value)
    {
        if (Value != 0)
            Current_Value /= Value;
        else
        {
            cout << "Error : divide by 0 is undefined." << endl;
        }
        display();
    }
    void clear()
    {
        Current_Value = 0;
        display();
    }
    void display()
    {
        cout << "Calculator display: " << Current_Value << endl;
    }
    ~Calculator()
    {
        cout<<"Calculator object is destroyed"<<endl;
    }
};

int main()
{
    Calculator Cal1(5);
    Cal1.add(10);
    Cal1.add(7);
    Cal1.multiply(31);
    Cal1.subtract(42);
    Cal1.divideBy(7);
    Cal1.divideBy(0);
    Cal1.add(3);
    Cal1.subtract(1);
    Cal1.clear();
}