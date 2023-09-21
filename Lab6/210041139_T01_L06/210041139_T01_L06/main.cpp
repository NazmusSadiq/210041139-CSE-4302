
#include <iostream>
#include "Counter.h"

using namespace std;

int main()
{
    Counter Ctr1;
    Ctr1.setIncrementStep(5);
    Ctr1.increment();
    cout << "Current Value: " << Ctr1.getCount() << endl;
    Counter Ctr2(2, 3);
    Counter Ctr3 = Ctr1 + Ctr2;
    cout << "Current value of new Counter 3 is: " << Ctr3.getCount() << endl;
    Counter Ctr4 = ++Ctr1;
    cout << "Current value of new Counter 4 is: " << Ctr4.getCount() << endl;

    if (Ctr3 > Ctr4)
        cout << "Counter 3 is greater than Counter 4" << endl;
    else
        cout<< "Counter 3 is smaller than Counter 4" << endl;
    if (Ctr3 < Ctr4)
        cout << "Counter 3 is less than Counter 4" << endl;
    else
        cout << "Counter 3 is greater than Counter 4" << endl;
    if (Ctr3 != Ctr4)
        cout << "Counter 3 is not equal to Counter 4" << endl;
    else
        cout << "Counter 3 is equal to Counter 4" << endl;
}

