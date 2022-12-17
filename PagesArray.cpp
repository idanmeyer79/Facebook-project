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
		if (*itr!=nullptr&&(*itr)->getName()==page.getName())
		{
			pagesArray.erase(itr);
			return;

		}
	}
}

void PagesArray::addPage(FanPage& p)
{
	pagesArray.push_back(&p);
}

FanPage* PagesArray::addPage(const string name)
{
	FanPage* fanPage = new FanPage(name);
	pagesArray.push_back(fanPage);
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

}

void PagesArray::printAllPages() const
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
		if (*itr!=nullptr&&(*itr)->getName()==name)
		{
			theFoundPage = (*itr);
			return theFoundPage;
		}
	}
	return theFoundPage;
}