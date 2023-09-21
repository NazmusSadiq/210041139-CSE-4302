
#include <iostream>
#include "Weight.h"

using namespace std;

int main()
{
    Weight w1(5.2);
    Weight w2(2, 3.5);
    w1.showWeight();
    double kg = double(w2);
    cout << "In kg: "<<kg << endl;

}
