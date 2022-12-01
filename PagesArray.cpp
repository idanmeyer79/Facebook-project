#include "PagesArray.h"
using namespace std;

PagesArray::PagesArray()
{
	pagesArray = new FanPage * [numOfMaxPages];
}

//PagesArray::~PagesArray()
//{
//	for(int i=0;i<numOfPages;i++)
//	{
//		delete allPages[i];
//	}
//	delete[]allPages;
//}
	
void PagesArray::addPage(FanPage* p)
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

	pagesArray[numOfPages] = p;
	numOfPages++;
}

bool PagesArray::checkIfNameExist(char* name)
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
		cout << "None";
		return;
	}

	for (int i = 0; i < numOfPages; i++)
	{
		cout << "#" << i + 1 << " " << pagesArray[i]->getName() << endl;
	}
}

FanPage* PagesArray::findPage(char* name)
{
	//זה כמו של ממבר אמור לעבוד
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

	//זה הישן
	/*FanPage* theFoundPage = nullptr;

	while (theFoundPage == nullptr) {
		for (int i = 0; i < numOfPages; i++)
		{
			if (!strcmp(pagesArray[i]->getName(), name))
			{
				theFoundPage = pagesArray[i];
				return theFoundPage;
			}
		}
		cout << "The page not found Please enter another name" << endl;
		char* newname = new char[20];
		cin >> newname;
		strcpy(name, newname);
		delete[] newname;
	}*/
}