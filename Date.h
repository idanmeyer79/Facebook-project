#ifndef __DATE_H
#define __DATE_H

class Date
{
private: 
	int day, month, year;

public:
	Date(int d, int m, int y);

	void show() const;
};

Date::Date(int d, int m, int y) {
	day = d;

}

#endif __DATE_H