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
	char* text;
	char* date_and_time;

public:
	Status(Status& other) = delete;
	Status(const char* text);
	Status(char* text);
	~Status();
	bool setText(const char* text);
	char* getText() { return text; }
	char* getDateAndTime() { return date_and_time; }
	void printStatus();
};

#endif // !__STATUS_H__



