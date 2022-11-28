#include "StatusesArray.h"
using namespace std;

StatusesArray::StatusesArray()
{
	statusArray = new Status * [numOfMaxStatuses];
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

void StatusesArray::printAllStatuses()
{
	cout << "All the statuses:" << endl;
	for (int i = 0; i < numOfStatuses; i++)
	{
		cout << "# " << i + 1 << " ";
		statusArray[i]->printStatus();
	}
}


//צריך לממש דיסטרקטור
