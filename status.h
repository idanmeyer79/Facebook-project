#ifndef __STATUS_H__
#define __STATUS_H__
#include <ctime>
#include<iostream>
#pragma warning(disable: 4996)

class Status
{
private:
	std::string text;
	std::string date_and_time;

public:
	//Status(const std::string text);
	Status(const std::string text);
	bool setText(const std::string text);
	std::string getText() { return text; }
	std::string getDateAndTime() { return date_and_time; }
	void printStatus()const;
	//operators overload
	bool operator==(Status& other);
	bool operator!=(Status& other);
};

#endif // !__STATUS_H__



