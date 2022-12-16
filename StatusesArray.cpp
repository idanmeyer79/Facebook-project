#include "StatusesArray.h"
#include <cmath>
using namespace std;

//StatusesArray::StatusesArray()
//{
//	statusArray = new Status * [numOfMaxStatuses];
//}

//StatusesArray::~StatusesArray()
//{
//	for(int i=0;i< numOfStatuses;i++)
//	{
//		delete statusArray[i];
//	}
//	delete[]statusArray;
//}

void StatusesArray::addStatusToArray(Status& s)
{
	//if (numOfMaxStatuses == numOfStatuses) {
	//	numOfMaxStatuses = numOfMaxStatuses * 2;
	//	Status** tmp = new Status * [numOfMaxStatuses];
	//	for (int i = 0; i < numOfStatuses; i++)
	//		tmp[i] = statusArray[i];
	//	delete[] statusArray;
	//	statusArray = tmp;
	//}
	statusArray.push_back(&s);
	//statusArray[numOfStatuses] = &s;
	//numOfStatuses++;
}

void StatusesArray::printAllStatuses()
{
	vector<Status*>::iterator itr = statusArray.begin();
	vector<Status*>::iterator itrEnd = statusArray.end();

	int i= 0;
	cout << "All the statuses:" << endl;
	for (; itr != itrEnd; ++itr)
	{
		cout << "# " << ++i << " ";
		(*itr)->printStatus();
	}
}

void StatusesArray::print10()
{
	vector<Status*>::reverse_iterator  rit = statusArray.rbegin();
	vector<Status*>::reverse_iterator ritrEnd = statusArray.rend();
	int size = statusArray.size();
	int currMemberNumOfStatuses = min(size, 10);
	for (; rit != ritrEnd; ++rit)
	{
		(*rit)->printStatus();
		//statusArray[size - k]->printStatus();
	}
	cout << endl;
	/*for (int k = 1; k < currMemberNumOfStatuses+1; k++)
	{
		statusArray[size-k]->printStatus();
	}
	cout << endl;*/
}

