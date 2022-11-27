#include "AllPages.h"

AllPages::AllPages()
{
	allPages = new FanPage * [numOfMaxPages];
}

//AllPages::~AllPages()
//{
//	for(int i=0;i<numOfPages;i++)
//	{
//		delete allPages[i];
//	}
//	delete[]allPages;
//}
	
void AllPages::addPage(FanPage* p)
{
	if (numOfMaxPages == numOfPages) {
		numOfMaxPages = numOfMaxPages * 2;
		FanPage** tmp = new FanPage * [numOfMaxPages];
		for (int i = 0; i < numOfPages; i++)
			tmp[i] = allPages[i];
		allPages = tmp;
		tmp = nullptr;
		delete[] tmp;
	}

	allPages[numOfPages] = p;
	numOfPages++;
}

bool AllPages::checkIfNameExist(char* name)
{
	for (int i = 0; i < numOfPages; i++)
	{
		if (!strcmp(name, allPages[i]->getName()))
		{
			cout << "Name already taken, please enter another name." << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
}


void AllPages::printAllPages()
{
	cout << "All the pages:" << endl;
	for (int i = 0; i < numOfPages; i++)
	{
		cout << "#" << i + 1 << " " << allPages[i]->getName() << endl;
	}
}