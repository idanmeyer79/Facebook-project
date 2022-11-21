#ifndef __AllPages_H__
#define __AllPages_H__

#include"page.h"

class AllPages
{
private:
	FanPage** allPages;
	int numOfPages=0;

public:
	void addPage(page& p);
	void printAllPages();

};


#endif // !__AllPages_H__



