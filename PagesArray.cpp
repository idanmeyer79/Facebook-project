#include "PagesArray.h"
using namespace std;

//PagesArray::PagesArray()
//{
//	pagesArray = new FanPage * [numOfMaxPages];
//}

//PagesArray::~PagesArray()
//{
//	for(int i=0;i<numOfPages;i++)
//	{
//		delete pagesArray[i];
//	}
//	delete[]pagesArray;
//}
	
void PagesArray::deletePage(FanPage& page)
{
	vector<FanPage*>::iterator itr = pagesArray.begin();
	vector<FanPage*>::iterator itrEnd = pagesArray.end();

	for (; itr!=itrEnd; ++itr)
	{
		if (*itr!=nullptr&&(*itr)->getName()==page.getName())// !strcmp(pagesArray[i]->getName(), page.getName()))
		{
			pagesArray.erase(itr);
			return;
			/*pagesArray[i] = pagesArray[numOfPages - 1];
			pagesArray[numOfPages - 1] = nullptr;
			numOfPages--;*/
		}
	}
}

void PagesArray::addPage(FanPage& p)
{
	//if (numOfMaxPages == numOfPages) {
	//	numOfMaxPages = numOfMaxPages * 2;
	//	FanPage** tmp = new FanPage * [numOfMaxPages];
	//	for (int i = 0; i < numOfPages; i++)
	// 
	//		tmp[i] = pagesArray[i];
	//	pagesArray = tmp;
	//	tmp = nullptr;
	//	delete[] tmp;
	//}
	pagesArray.push_back(&p);

	//pagesArray[numOfPages] = &p;
	//numOfPages++;
}

FanPage* PagesArray::addPage(const string name)
{
	FanPage* fanPage = new FanPage(name);

	//if (numOfMaxPages == numOfPages) {
	//	numOfMaxPages = numOfMaxPages * 2;
	//	FanPage** tmp = new FanPage * [numOfMaxPages];
	//	for (int i = 0; i < numOfPages; i++)
	//		tmp[i] = pagesArray[i];
	//	pagesArray = tmp;
	//	tmp = nullptr;
	//	delete[] tmp;
	//}

	pagesArray.push_back(fanPage);
	/*pagesArray[numOfPages] = fanPage1;
	numOfPages++;*/
	return fanPage;
}


bool PagesArray::checkIfNameExist(const string name)
{
	vector<FanPage*>::iterator itr = pagesArray.begin();
	vector<FanPage*>::iterator itrEnd = pagesArray.end();

	for (; itr != itrEnd; ++itr)
	{
		if (*itr != nullptr && (*itr)->getName() == name)//!strcmp(pagesArray[i]->getName(), name))
		{
			cout << "Name already taken, please enter another name." << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	//for (int i = 0; i < numOfPages; i++)
	//{
	//	if (!strcmp(name, pagesArray[i]->getName()))
	//	{
	//		cout << "Name already taken, please enter another name." << endl;
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
}

void PagesArray::printAllPages()
{
	vector<FanPage*>::iterator itr = pagesArray.begin();
	vector<FanPage*>::iterator itrEnd = pagesArray.end();
	int i = 0;
	int numOfPages = pagesArray.size();

	cout << "All the pages:" << endl;

	if (numOfPages == 0)
	{
		cout << "None"<<endl;
		return;
	}

	for (; itr!=itrEnd; ++itr)
	{
		cout << "#" << ++i << " " << (*itr)->getName() << endl;
	}
}

FanPage* PagesArray::findPage(string name)
{
	FanPage* theFoundPage = nullptr;
	vector<FanPage*>::iterator itr = pagesArray.begin();
	vector<FanPage*>::iterator itrEnd = pagesArray.end();

	for (; itr!=itrEnd; ++itr)
	{
		if (*itr!=nullptr&&(*itr)->getName()==name)//!strcmp(pagesArray[i]->getName(), name))
		{
			theFoundPage = (*itr);
			return theFoundPage;
		}
	}
	return theFoundPage;
}