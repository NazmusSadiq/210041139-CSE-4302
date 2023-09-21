#include <iostream>

using namespace std;

class Time
{
    private:
        int hour=0;
        int minute=0;
        int second=0;
        
    public:
        int hours()
        {
            return hour;
        }
        int minutes()
        {
            return minute;
        }
        int seconds()
        {
            return second;
        }
        void reset(int h,int m,int s)
        {
            second=s;
            if(second>=60)
            {
                minute+=second/60;
                second=second%60;
            }
            minute=m;
            if(minute>=60)
            {
                    hour+=minute/60;
                    minute=minute%60;
            }
            hour=h;
        }
        void advance(int h,int m,int s)
        {
            second+=s;
            if(second>=60)
            {

                minute+=second/60;
                second=second%60;

                if(minute>=60)
                {
                    hour+=minute/60;
                    minute=minute%60;
                }
            }
            minute+=m;

            if(minute>=60)
            {
                hour+=minute/60;
                minute=minute%60;
            }

            hour+=h;
            hour=hour%24;
        }

        void print()
        {
            cout<<"Current time is: "<<hour <<" hour "<<minute<<" minute "<<second<<" second"<<endl;
        }
};

int main()
{
    Time time1;
}