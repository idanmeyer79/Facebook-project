#ifndef __StatusesArray__
#define __StatusesArray__
#include <iostream>
#include"Status.h"
#pragma warning(disable: 4996)

class StatusesArray
{
private:
	Status** statusArray;
	int numOfStatuses = 0;
	int numOfMaxStatuses = 1;

public:
	StatusesArray(StatusesArray& other) = delete;
	StatusesArray();
	~StatusesArray();
	int getNumOfStatuses() { return numOfStatuses; }
	void addStatusToArray(Status& s);
	void printAllStatuses();
	void print10();
};


#endif // !__StatusesArray__

