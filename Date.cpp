#include "Date.h"
using namespace std;

Date::Date(int d , int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Date::show() const
{
	cout << day << "/" << month << "/" << year << " ";
}

///ма рлеп
bool Date::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;

    return true;
}

bool Date:: checkdate()
{ 
    if (!(1900 <= year))
    {
        cout << "Invalid date"<<endl;
        return false;
    }
       
    if (!(1 <= month && month <= 12))
    {
        cout << "Invalid date"<<endl;
        return false;
    }
    if (!(1 <= day && day <= 31))
    {
        cout << "Invalid date"<<endl;
        return false;
    }
    if ((day == 31) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
    {
        cout << "Invalid date"<<endl;
        return false;
    }  
    if ((day == 30) && (month == 2))
        {
        cout << "Invalid date"<<endl;
        return false;
    }  
    if ((month == 2) && (day == 29) && (year % 4 != 0))
    {
        cout << "Invalid date"<<endl;
        return false;
    }   

    return true;
}