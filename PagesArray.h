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

public:
	int getNumOfPages() { return pagesArray.size(); }
	void addPage(FanPage& p);
	FanPage* addPage(const std::string name);
	void printAllPages();
	FanPage* findPage(std::string name);
	bool checkIfNameExist(const std::string name);
	void deletePage(FanPage& page);
};

#endif // !__AllPages_H__



