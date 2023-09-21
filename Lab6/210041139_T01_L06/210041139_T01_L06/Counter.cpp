#include "Counter.h"
#include <algorithm>

Counter::Counter(const int count,const int step_val)
{
	if (count >= 0)
		Count = count;
	if (step_val >= 0)
		Step_Val = step_val;
}

void Counter::resetCount()
{
	Count = 0;
}
Counter Counter::operator+(const Counter &C) const
{
	return Counter(Count+C.Count,std::max(Step_Val,C.Step_Val));
}

Counter Counter::operator ++(int) 
{
	return Counter(Count,Step_Val);
	increment();
}
Counter Counter::operator ++()
{
	increment();
	return Counter(Count, Step_Val);
}
Counter Counter::operator +=(const Counter& C)
{
	Count += C.Count;
	return Counter(Count, Step_Val);
}

bool Counter::operator>(const Counter& C) const
{
	return Count>C.Count;
}
bool Counter::operator<(const Counter& C) const
{
	return Count < C.Count;
}
bool Counter::operator<=(const Counter& C) const
{
	return Count <= C.Count;
}
bool Counter::operator>=(const Counter& C) const
{
	return Count >= C.Count;
}
bool Counter::operator==(const Counter& C) const
{
	return Count == C.Count;
}
bool Counter::operator!=(const Counter& C) const
{
	return Count != C.Count;
}
void Counter::increment()
{
	Count += Step_Val;
}
void Counter::setIncrementStep(int step_val)
{
	if(step_val>=0)
		Step_Val = step_val;
}
int Counter::getCount() const
{
	return Count;
}

