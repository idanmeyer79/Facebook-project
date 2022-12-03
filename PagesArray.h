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
	PagesArray(const PagesArray& other) = delete;
	PagesArray();
	~PagesArray();
	const int getNumOfPages() const    { return numOfPages;    }
	const int getMaxNumOfPages() const { return numOfMaxPages; }
	void addPage(FanPage& p);
	FanPage* addPage(const char* name);
	void printAllPages() const;
	FanPage* findPage(const char* name) const ;
	bool checkIfNameExist(const char* name) const;
	void deletePage(FanPage& page);
};

#endif // !__AllPages_H__



