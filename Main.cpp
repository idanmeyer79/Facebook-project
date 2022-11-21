#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

#include "Date.h"
#include"status.h"
int main()
{
	char str[] = { "hello" };

	status myStatus(str);
	myStatus.printStatus();
}

