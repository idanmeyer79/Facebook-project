#include "page.h"


page::page(char* name) : name(name)
{
	numOfPages++;
}

void page::addFan(Member* fan)
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

void page::removeFan(Member* fan)
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

void page::printFans()
{
	for (int i = 0; i < numOfFans; i++)
	{
		cout <<i+1<<"#:"<< fans[i]->getName() << endl;
	}
}

void page::printAllStatuses()
{
	for (int i = 0; i < numOfStatuses; i++)
	{
		statuses[i]->printStatus();
	}
}