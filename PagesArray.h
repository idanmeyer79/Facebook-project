#ifndef __AllPages_H__
#define __AllPages_H__
#include <iostream>
#pragma warning(disable: 4996)
#include"FanPage.h"

class FanPage;

class PagesArray
{
private:
	FanPage** pagesArray;
	int numOfPages = 0;
	int numOfMaxPages = 1;

public:
	void addPage(FanPage& p);
	int getnumOfPages() { return numOfPages; }
	//~AllPages();
	PagesArray();
	void printAllPages();
	FanPage* findPage(const char* name);
	bool checkIfNameExist(const char* name);
	void deletePage(FanPage& page);
	FanPage* addPage(const char* name);
};


#endif // !__AllPages_H__



