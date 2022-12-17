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

public:
	std::vector<Status*> getStatusArray() {return statusArray; 	}
	void addStatusToArray(Status& s);
	void printAllStatuses();
	void print10();
};

#endif // !__StatusesArray__

