#include <iostream>
using namespace std;

#ifndef __DATE_H__
#define __DATE_H__

class Date
{
private: 
	int day, month, year;

public:
	Date(int d, int m, int y);

	void show() const;
};



#endif __DATE_H__