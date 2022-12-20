#ifndef __AllPages_H__
#define __AllPages_H__
#include <iostream>
#include"FanPage.h"
#include<vector>
#pragma warning(disable: 4996)
#define new MYDEBUG_NEW
#ifdef _DEBUG 
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif // _DEBUG 
class FanPage;

class PagesArray
{
private:
	std::vector<FanPage*> pagesArray;

public:
	~PagesArray();
	int getNumOfPages() { return pagesArray.size(); }
	void addPage(FanPage& p);
	FanPage* addPage(const std::string name);
	void printAllPages() const;
	FanPage* findPage(std::string name);
	bool checkIfNameExist(const std::string name) const;
	void deletePage(FanPage& page);
};

#endif // !__AllPages_H__



