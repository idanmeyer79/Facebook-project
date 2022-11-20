#include "member.h"
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

Member::Member(char* name, Date dateOfBirth)
{
	name = strdup(name);
}