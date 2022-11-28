#include <iostream>
#pragma warning(disable: 4996)

#ifndef __TIME_H__
#define __TIME_H__

class Time
{
public:
	Time(int h = 0, int m = 0);

	void show() const;

private:
	int hours, minutes;
};

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

//void Time::show() const
//{
//	cout << hours << ":" << minutes << " ";
//}

#endif __TIME_H__