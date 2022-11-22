#include "Page.h"

FanPage::FanPage(char* name) : pageName(name)
{
	
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

void FanPage::addFan(Member* fan)
{
	Member** res = new Member * [numOfFans + 1];

	for (int i = 0; i < numOfFans; i++)
	{
		res[i] = fans[i];
	}

	res[numOfFans] = fan;
	fans = res;
	numOfFans++;
	res = nullptr;
	delete[]res;
}

void FanPage::removeFan(Member* fan)
{
	Member** res = new Member * [numOfFans-1];
	for (int i = 0; i < numOfFans; i++)
	{
		if (strcmp(fan->getName(), fans[i]->getName()) == 0)
		{
			fans[i] = fans[numOfFans - 1];
		}

		if (i<numOfFans-1)
		{
			res[i] = fans[i];
		}
	}
	fans = res;
	res = nullptr;
	delete[]res;
	numOfFans--;
}

void FanPage::printFans()
{
	for (int i = 0; i < numOfFans; i++)
	{
		cout <<i+1<<"#:"<< fans[i]->getName() << endl;
	}
}

void FanPage::printAllStatuses()
{
	for (int i = 0; i < numOfStatuses; i++)
	{
		statuses[i]->printStatus();
	}
}

void FanPage::addStatus(char* text)
{
	Status** res = new Status * [numOfStatuses + 1];
	Status* newStatus = new Status(text);

	for (int i = 0; i < numOfStatuses; i++)
	{
		res[i] = statuses[i];
	}

	res[numOfStatuses] = newStatus;
	statuses = res;
	numOfStatuses++;
	res = nullptr;
	delete[]res;
}