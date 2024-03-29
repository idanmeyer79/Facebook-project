#include "Date.h"
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

Date::Date(ifstream& file)
{
    char delimiter;
    string dateString;
    getline(file, dateString);
    stringstream ss(dateString);
    ss >> day >> delimiter >> month >> delimiter >> year;
}

Date::Date(int d , int m, int y)
{
    if (!checkdate(d, m, y))
        throw invalid_argument("\033[1;31mInvalid date\033[0m");

	day = d;
	month = m;
	year = y;
}

void Date::show() const
{
	cout << day << "/" << month << "/" << year << " ";
}

void Date::setDate(int d, int m, int y) 
{
    if (!checkdate(d, m, y))
        throw invalid_argument("\033[1;31mInvalid date\033[0m");

    day = d;
    month = m;
    year = y;
}

bool Date:: checkdate(int day, int month , int year)
{ 
    if (!(1900 <= year))
        return false;
        
    if (!(1 <= month && month <= 12))
        return false;

    if (!(1 <= day && day <= 31))
        return false;
    
    if ((day == 31) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
        return false;
    
    if ((day == 30) && (month == 2))
        return false;
    
    if ((month == 2) && (day == 29) && (year % 4 != 0))
        return false;

    return true;
}

std::ostream& operator<< (std::ostream& out, const Date& date) 
{
    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}