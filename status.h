#ifndef __STATUS_H__
#define __STATUS_H__
#include <ctime>
#include<iostream>
#pragma warning(disable: 4996)

class Status
{
public:
	static constexpr int LEN_OF_STATUS = 100;
private:
	std::string text;
	std::string date_and_time;

public:
	Status(Status& other) = delete;
	//Status(const std::string text);
	Status(std::string text);
	//~Status();
	bool setText(const std::string text);
	std::string getText() { return text; }
	std::string getDateAndTime() { return date_and_time; }
	void printStatus();
};

#endif // !__STATUS_H__



