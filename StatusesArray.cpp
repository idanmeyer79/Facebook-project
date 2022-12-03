#include "StatusesArray.h"
#include <cmath>
using namespace std;

StatusesArray::StatusesArray()
{
	statusArray = new Status * [numOfMaxStatuses];
}

StatusesArray::~StatusesArray()
{
	for(int i=0;i< numOfStatuses;i++)
	{
		delete statusArray[i];
	}
	delete[]statusArray;
}

void StatusesArray::addStatusToArray(Status& s)
{
	if (numOfMaxStatuses == numOfStatuses) {
		numOfMaxStatuses = numOfMaxStatuses * 2;
		Status** tmp = new Status * [numOfMaxStatuses];
		for (int i = 0; i < numOfStatuses; i++)
			tmp[i] = statusArray[i];
		delete[] statusArray;
		statusArray = tmp;
	}

	statusArray[numOfStatuses] = &s;
	numOfStatuses++;
}

void StatusesArray::printAllStatuses() const
{
	cout << "statuses are:" << endl;
	for (int i = 0; i < numOfStatuses; i++)
	{
		cout << "#" << i + 1 << " ";
		statusArray[i]->printStatus();
	}
}

void StatusesArray::print10() const
{
	int currMemberNumOfStatuses = min(numOfStatuses, 10);
	for (int k = 1; k < currMemberNumOfStatuses+1; k++)
	{
		cout << "#" << numOfStatuses-k+1 << " ";
		statusArray[numOfStatuses-k]->printStatus();
	}
	cout << endl;
}

