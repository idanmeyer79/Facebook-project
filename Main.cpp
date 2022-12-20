#include <iostream>
#include"Admin.h"
#include<crtdbg.h>
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
using namespace std;

#define new MYDEBUG_NEW
#ifdef _DEBUG 
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif // _DEBUG 


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		Admin admin;
		admin.hardCodedData();
		admin.menu();
	}
	//_CrtDumpMemoryLeaks();
}