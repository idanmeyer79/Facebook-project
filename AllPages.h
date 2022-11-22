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
	int numOfPages=0;

public:
	void addPage(FanPage& p);
	void printAllPages();

};


#endif // !__AllPages_H__



