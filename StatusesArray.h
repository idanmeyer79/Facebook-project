#ifndef __StatusesArray__
#define __StatusesArray__
#include <iostream>
#pragma warning(disable: 4996)
#include"Status.h"

class StatusesArray
{
private:
	Status** statusArray;
	int numOfStatuses = 0;
	int numOfMaxStatuses = 1;

public:
	StatusesArray();
	//~StatusesArray();
	void addStatusToArray(Status& s);
	void printAllStatuses();
	void print10();
	int getNumOfStatuses() { return numOfStatuses; }
};


#endif // !__StatusesArray__

