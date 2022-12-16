#ifndef __AllPages_H__
#define __AllPages_H__
#include <iostream>
#include"FanPage.h"
#include<vector>
#pragma warning(disable: 4996)

class FanPage;

class PagesArray
{
private:
	std::vector<FanPage*> pagesArray;
	//FanPage** pagesArray;
	//int numOfPages = 0;
	//int numOfMaxPages = 1;

public:
	/*PagesArray(PagesArray& other) = delete;*/
	//PagesArray();
	//~PagesArray();
	int getNumOfPages() { return pagesArray.size(); }
	//int getMaxNumOfPages() { return numOfMaxPages; }
	void addPage(FanPage& p);
	FanPage* addPage(const std::string name);
	void printAllPages();
	FanPage* findPage(std::string name);
	bool checkIfNameExist(const std::string name);
	void deletePage(FanPage& page);
};

#endif // !__AllPages_H__



