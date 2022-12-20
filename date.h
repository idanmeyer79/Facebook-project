#ifndef __DATE_H__
#define __DATE_H__
#include <iostream>
#pragma warning(disable: 4996)
#define new MYDEBUG_NEW
#ifdef _DEBUG 
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif // _DEBUG 
class Date
{
private:
	int day, month, year;

public:
	Date(int d, int, int y);
	bool setDate(int d, int m, int y);
	const int getDay() const  { return day;  }
	const int getMonth() const { return month;}
	const int getYear() const { return year; }
	void show() const;
	bool checkdate();
	bool checkdate(int day, int month, int year);
};

#endif //!__DATE_H__