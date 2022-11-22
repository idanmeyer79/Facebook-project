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

Member* AllMembers::findMember(char* name)
{
	Member* theFoundMember = nullptr;

	while (theFoundMember == nullptr) {
		for (int i = 0; i < numOfMembers; i++)
		{
			if (!strcmp(allMembers[i]->getName(), name))
				{
					theFoundMember = allMembers[i];
					return theFoundMember;
				}
		}
		cout << "The member not found Please enter anothe name" << endl;
		char* newname = new char[20];
		cin >> newname;
		strcpy(name, newname);
		delete[] newname;
	}
}
