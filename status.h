#ifndef __STATUS_H__
#define __STATUS_H__
#include <ctime>
#include<iostream>
#pragma warning(disable: 4996)

class Status
{
private:
	char* text;
	char* date_and_time;

public:
	Status(char* text);
	Status();
	~Status();

	void printStatus();

};

#endif // !__STATUS_H__



