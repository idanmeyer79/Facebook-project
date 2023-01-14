#ifndef __DATE_H__
#define __DATE_H__
#include <iostream>
#include<fstream>
#pragma warning(disable: 4996)

class Date 
{
public:
    Date(std::ifstream& file);

    friend std::ostream& operator<< (std::ostream& out, const Date& date);
    /**
     * Constructs a new `Date` object with the given day, month, and year.
     *
     * @param d The day (1-31).
     * @param m The month (1-12).
     * @param y The year.
     * @throws std::invalid_argument If the given day, month, or year is invalid.
     */
    Date(int d, int m, int y) noexcept(false);

    /**
     * Sets the day, month, and year of the `Date` object to the given values.
     *
     * @param d The new day (1-31).
     * @param m The new month (1-12).
     * @param y The new year.
     * @return `true` if the date was successfully set, `false` otherwise.
     */
    void setDate(int d, int m, int y) noexcept(false);

    /**
     * Returns the day of the `Date` object.
     *
     * @return The day (1-31).
     */
    const int getDay() const { return day; }

    /**
     * Returns the month of the `Date` object.
     *
     * @return The month (1-12).
     */
    const int getMonth() const { return month; }

    /**
     * Returns the year of the `Date` object.
     *
     * @return The year.
     */
    const int getYear() const { return year; }

    /**
     * Prints the date in the format "day/month/year".
     */
    void show() const;

    /**
    * Returns whether the given day, month, and year form a valid date.
    *
    * @param day The day (1-31).
    * @param month The month (1-12).
    * @param year The year.
    * @return `true` if the date is valid, `false` otherwise.
    */
    bool checkdate(int day, int month, int year);
private:
    int day;
    int month;
    int year;
};

#endif //!__DATE_H__