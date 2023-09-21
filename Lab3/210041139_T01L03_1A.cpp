#include <iostream>

using namespace std;

class Counter
{
    private:
        int Count=0;
        int Step_Val=0;

    public:
        int getCount()
        {
            return Count;
        }
        void setIncrementStep(int step_val)
        {
            Step_Val=step_val;
        }
        void increment()
        {
            Count+=Step_Val;
        }
        void resetCount()
        {
            Count=0;
        }
};

int main()
{
    Counter Ctr1;
}