#ifndef __StatusesArray__
#define __StatusesArray__
#include <iostream>
#include<vector>
#include"Status.h"
#pragma warning(disable: 4996)

class StatusesArray
{
private:
	std::vector<Status*> statusArray;
	//Status** statusArray;
	//int numOfStatuses = 0;
	//int numOfMaxStatuses = 1;

public:
	/*StatusesArray(StatusesArray& other) = delete;*/
	/*StatusesArray();*/
	//~StatusesArray();
	//int getNumOfStatuses() { return numOfStatuses; }
	//int getMaxNumOfStatuses() { return numOfMaxStatuses; }
	std::vector<Status*> getStatusArray() {return statusArray; 	}
	void addStatusToArray(Status& s);
	void printAllStatuses();
	void print10();
};

#endif // !__StatusesArray__

