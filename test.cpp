#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

#include "Date.h"
#include"status.h"
#include"page.h"
#include"member.h"
#include"AllPages.h"





int main()
{
	AllPages Pages;
	char str[] = { "hello" };
	char str1[] = { "page1" };
	char str2[] = { "page2" };
	char* strptr = new char[strlen(str) + 1];
	char* strptr1 = new char[strlen(str1) + 1];
	char* strptr2 = new char[strlen(str2) + 1];
	strcpy(strptr, str);
	strcpy(strptr1, str1);
	strcpy(strptr2, str2);
	status myStatus(strptr);
	myStatus.printStatus();

	Member avi, yosi, dani;
	avi.setName("avi");
	yosi.setName("yosi");
	dani.setName("dani");
	page test(strptr);

	cout<<test.getName()<<endl;
	
	test.addFan(&avi);
	test.addFan(&yosi);
	test.addFan(&dani);
	test.printFans();
	test.removeFan(&avi);
	test.printFans();

	test.addStatus(strptr);
	test.printAllStatuses();

	test.addStatus(strptr);
	test.printAllStatuses();

	page page1(str1);
	page page2(str2);

	Pages.addPage(page1);

	Pages.addPage(page2);

	Pages.printAllPages();


}



