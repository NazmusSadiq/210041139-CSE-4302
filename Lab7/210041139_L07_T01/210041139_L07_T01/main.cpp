#include <iostream>
#include <string>
#include "StudentCollection.h"


int main() 
{
    StudentCollection S1;
    S1.addStudent("X", 4);
    S1.addStudent("Y", 3);
    S1.addStudent("Z", 3.5);

    //S1("X", 5);
    S1["X"] = 5;
    S1.print();

    return 0;
}
