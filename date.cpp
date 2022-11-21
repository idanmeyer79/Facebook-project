#include "date.h"


Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Date::show() const
{
	cout << day << "/" << month << "/" << year << " ";
}
