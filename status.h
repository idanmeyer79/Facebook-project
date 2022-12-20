#ifndef __STATUS_H__
#define __STATUS_H__
#include <ctime>
#include<iostream>
#pragma warning(disable: 4996)
#define new MYDEBUG_NEW
#ifdef _DEBUG 
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif // _DEBUG 
class Status
{
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
	void printStatus()const;

	bool operator==(Status& other);
	bool operator!=(Status& other);
};

#endif // !__STATUS_H__



