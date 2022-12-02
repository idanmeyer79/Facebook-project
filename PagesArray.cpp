#include "PagesArray.h"
using namespace std;

PagesArray::PagesArray()
{
	pagesArray = new FanPage * [numOfMaxPages];
}
	
void PagesArray::deletePage(FanPage& page)
{
	for (int i = 0; i < numOfPages; i++)
	{
		if (!strcmp(pagesArray[i]->getName(), page.getName()))
		{
			pagesArray[i] = pagesArray[numOfPages - 1];
			pagesArray[numOfPages - 1] = nullptr;
			numOfPages--;
		}
	}
}

void PagesArray::addPage(FanPage& p)
{
	if (numOfMaxPages == numOfPages) {
		numOfMaxPages = numOfMaxPages * 2;
		FanPage** tmp = new FanPage * [numOfMaxPages];
		for (int i = 0; i < numOfPages; i++)
			tmp[i] = pagesArray[i];
		pagesArray = tmp;
		tmp = nullptr;
		delete[] tmp;
	}

	pagesArray[numOfPages] = &p;
	numOfPages++;
}

bool PagesArray::checkIfNameExist(const char* name)
{
	for (int i = 0; i < numOfPages; i++)
	{
		if (!strcmp(name, pagesArray[i]->getName()))
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

void PagesArray::printAllPages()
{
	cout << "All the pages:" << endl;

	if (numOfPages == 0)
	{
		cout << "None"<<endl;
		return;
	}

	for (int i = 0; i < numOfPages; i++)
	{
		cout << "#" << i + 1 << " " << pagesArray[i]->getName() << endl;
	}
}

FanPage* PagesArray::findPage(const char* name)
{
	FanPage* theFoundPage = nullptr;

	for (int i = 0; i < numOfPages; i++)
	{
		if (!strcmp(pagesArray[i]->getName(), name))
		{
			theFoundPage = pagesArray[i];
			return theFoundPage;
		}
	}
	return theFoundPage;
}