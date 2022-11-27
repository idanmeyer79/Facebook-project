#ifndef __AllPages_H__
#define __AllPages_H__
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;
#include"page.h"

class AllPages
{
private:
	FanPage** allPages;
	int numOfPages = 0;
	int numOfMaxPages = 1;

public:
	void addPage(FanPage* p);
	//~AllPages();
	AllPages();
	void printAllPages();
	bool checkIfNameExist(char* name);
};


#endif // !__AllPages_H__



