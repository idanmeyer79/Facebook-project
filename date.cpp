#include "Date.h"
using namespace std;

Date::Date(int d , int m, int y)
{
    if (!checkdate(d, m, y))
        throw std::invalid_argument("\033[1;31mInvalid date\033[0m");

	day = d;
	month = m;
	year = y;
}

void Date::show() const
{
	cout << day << "/" << month << "/" << year << " ";
}

bool Date::setDate(int d, int m, int y) 
{
    if (!checkdate(d, m, y))
        return false;

    day = d;
    month = m;
    year = y;
    return true;
}

bool Date:: checkdate()
{ 
    if (!(1900 <= year))
    {
        return false;
    }
       
    if (!(1 <= month && month <= 12))
    {
        return false;
    }
    if (!(1 <= day && day <= 31))
    {
        return false;
    }
    if ((day == 31) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
    {
        return false;
    }  
    if ((day == 30) && (month == 2))
        {
        return false;
    }  
    if ((month == 2) && (day == 29) && (year % 4 != 0))
    {
        return false;
    }   

    return true;
}

bool Date:: checkdate(int day, int month , int year)
{ 
    if (!(1900 <= year))
    {
        return false;
    }
       
    if (!(1 <= month && month <= 12))
    {
        return false;
    }
    if (!(1 <= day && day <= 31))
    {
        return false;
    }
    if ((day == 31) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
    {
        return false;
    }  
    if ((day == 30) && (month == 2))
        {
        return false;
    }  
    if ((month == 2) && (day == 29) && (year % 4 != 0))
    {
        return false;
    }   

    return true;
}