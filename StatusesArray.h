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
	StatusesArray(const StatusesArray& other) = delete;
	StatusesArray();
	~StatusesArray();
	int getNumOfStatuses() const   { return numOfStatuses;    }
	int getMaxNumOfStatuses() const { return numOfMaxStatuses; }
	Status** getStatusArray() {return statusArray; 	     }
	void addStatusToArray(Status& s);
	void printAllStatuses() const ;
	void print10() const ;
};

#endif // !__StatusesArray__

