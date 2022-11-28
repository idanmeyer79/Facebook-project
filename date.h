#ifndef __DATE_H__
#define __DATE_H__
#include <iostream>
#pragma warning(disable: 4996)

bool checkdate(int m, int d, int y);

class Date
{
private: 
	int day, month, year;

public:
	Date(int d, int, int y);
	bool setDate(int d, int m, int y);
	void show() const;
	bool checkdate();
};

#endif __DATE_H__