#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

#include "Date.h"
#include"status.h"
#include"page.h"
#include"member.h"

int main()
{
	char str[] = { "hello" };
	char* strptr = new char[strlen(str) + 1];
	strcpy(strptr, str);
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

}

