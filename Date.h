#ifndef __DATE_H__
#define __DATE_H__
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

bool checkdate(int m, int d, int y);

class Date
{
private: 
	int day, month, year;

public:
	Date(int d=1, int m=1, int y=1970);
	bool setDate(int d, int m, int y);
	void show() const;
};

#endif __DATE_H__