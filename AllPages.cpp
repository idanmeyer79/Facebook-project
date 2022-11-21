#include "AllPages.h"

void AllPages::addPage(FanPage& p)
{
	FanPage** tmp = new FanPage * [numOfPages + 1];

	for (int i = 0; i < numOfPages; i++)
		tmp[i] = allPages[i];

	tmp[numOfPages] = &p;
	
	allPages = tmp;
	tmp = nullptr;
	delete[]tmp;
	numOfPages++;

}


void AllPages::printAllPages()
{
	for (int i = 0; i < numOfPages; i++)
	{
		cout << allPages[i]->getName()<<endl;
	}
}