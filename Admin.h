#ifndef __ADMIN_H__
#define __ADMIN_H__
#include"AllPages.h"
#include "AllMembers.h"
#include "Date.h"
#include"Status.h"
#include "Page.h"
#include "Member.h"
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

class Admin
{
private:
	AllPages fanPages;
	AllMembers users;

public:
	//צריך לבדוק
	//AllPages getFanPages()  {return fanPages ;}
	//AllMembers getusers() { return users; }
	void printMenu();
	void menu();
	void createFanPage();
	Member* getDetailsForMember();
	FanPage* getDetailsForPage();
	void createMember();
};

#endif // !__ADMIN_H__