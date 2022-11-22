#include "AllMembers.h"

void AllMembers::addMember(Member& m)
{
	Member** tmp = new Member * [numOfMembers + 1];

	for (int i = 0; i < numOfMembers; i++)
		tmp[i] = allMembers[i];

	tmp[numOfMembers] = &m;

	allMembers = tmp;
	tmp = nullptr;
	delete[]tmp;
	numOfMembers++;

}


void AllMembers::printAllMembers()
{
	for (int i = 0; i < numOfMembers; i++)
	{
		cout << allMembers[i]->getName() << endl;
	}
}