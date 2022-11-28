#include "FanPage.h"
using namespace std;

FanPage::FanPage(char* name) 
{
	pageName = new char[strlen(name) + 1];
	strcpy(pageName, name);
	fans = new MembersArray;
}

char* FanPage::getName()
{ 
	return pageName; 
}


bool FanPage::setName(char* name) 
{
	this->pageName = name;
	return true;
}

//void FanPage::addFan(Member* fan)
//{
//	Member** res = new Member * [numOfFans + 1];
//
//	for (int i = 0; i < numOfFans; i++)
//	{
//		res[i] = fans[i];
//	}
//
//	res[numOfFans] = fan;
//	fans = res;
//	numOfFans++;
//	res = nullptr;
//	delete[]res;
//}

//void FanPage::removeFan(Member* fan)
//{
//	Member** res = new Member * [numOfFans-1];
//	for (int i = 0; i < numOfFans; i++)
//	{
//		if (strcmp(fan->getName(), fans[i]->getName()) == 0)
//		{
//			fans[i] = fans[numOfFans - 1];
//		}
//
//		if (i<numOfFans-1)
//		{
//			res[i] = fans[i];
//		}
//	}
//	fans = res;
//	res = nullptr;
//	delete[]res;
//	numOfFans--;
//}

void FanPage::printFans()
{
	fans->printAllMembers();
}

void FanPage::showMyStatuses()
{
	statuses.printAllStatuses();
}

//void FanPage::addStatus(char* text)
//{
//	Status** res = new Status * [numOfStatuses + 1];
//	Status* newStatus = new Status(text);
//
//	for (int i = 0; i < numOfStatuses; i++)
//	{
//		res[i] = statuses[i];
//	}
//
//	res[numOfStatuses] = newStatus;
//	statuses = res;
//	numOfStatuses++;
//	res = nullptr;
//	delete[]res;
//}

void FanPage::addStatus()
{
	char text[100];
	cout << "Please enter new status: " << endl;
	cin.getline(text, 100);
	Status* status = new Status(text);
	statuses.addStatusToArray(*status);
}

void FanPage::addStatus(Status& s)
{
	statuses.addStatusToArray(s);
}