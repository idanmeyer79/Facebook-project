#include <iostream>
using namespace std;

#ifndef __DATE_H__
#define __DATE_H__

class Date
{
private: 
	int day, month, year;

public:
	Date(int d=1, int m=1, int y=1970);

	void show() const;
};



#endif __DATE_H__