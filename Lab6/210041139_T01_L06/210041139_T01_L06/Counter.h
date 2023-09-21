#pragma once
class Counter
{
private:
    int Count ;
    int Step_Val ;

public:
    Counter(const int count=0,const int step_val=1);
    int getCount() const;
    void setIncrementStep(int step_val);
    void increment();
    void resetCount();
    Counter operator +(const Counter &C) const;
    Counter operator ++(int);
    Counter operator ++();
    Counter operator +=(const Counter& C);
    bool operator >(const Counter& C) const;
    bool operator <(const Counter& C) const;
    bool operator >=(const Counter& C) const;
    bool operator <=(const Counter& C) const;
    bool operator ==(const Counter& C) const;
    bool operator !=(const Counter& C) const;

};

