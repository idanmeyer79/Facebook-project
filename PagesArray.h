#ifndef __AllPages_H__
#define __AllPages_H__
#include <iostream>
#include"FanPage.h"
#pragma warning(disable: 4996)

class FanPage;

class PagesArray
{
private:
	FanPage** pagesArray;
	int numOfPages = 0;
	int numOfMaxPages = 1;

public:
	PagesArray(PagesArray& other) = delete;
	PagesArray();
	~PagesArray();
	int getNumOfPages() { return numOfPages; }
	int getMaxNumOfPages() { return numOfMaxPages; }
	void addPage(FanPage& p);
	FanPage* addPage(const char* name);
	void printAllPages();
	FanPage* findPage(const char* name);
	bool checkIfNameExist(const char* name);
	void deletePage(FanPage& page);
};

#endif // !__AllPages_H__



