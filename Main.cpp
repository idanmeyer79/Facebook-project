#include <iostream>
#include "Admin.h"
#include <crtdbg.h>

#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

using namespace std;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    {
        Admin admin;
        admin.hardCodedData();
        admin.menu();
    }


    _CrtDumpMemoryLeaks();
}
