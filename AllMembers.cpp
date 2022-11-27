#include "AllMembers.h"

AllMembers:: AllMembers()
{
	allMembers = new Member * [numOfMaxMembers];
}

bool AllMembers::checkIfNameExist(char* name)
{
	for (int i = 0; i < numOfMembers; i++)
	{
		if (!strcmp(name, allMembers[i]->getName()))
		{
			cout << "Name already taken, please enter another name." << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
}

void AllMembers::addMember(Member* m)
{
	if (numOfMaxMembers == numOfMembers) {
		numOfMaxMembers = numOfMaxMembers * 2;
		Member** tmp = new Member * [numOfMaxMembers];
		for (int i = 0; i < numOfMembers; i++)
			tmp[i] = allMembers[i];
		allMembers = tmp;
		tmp = nullptr;
		delete[] tmp;
	}

	allMembers[numOfMembers] = m;
	numOfMembers++;
}

void AllMembers::printAllMembers()
{
	cout << "All the members:" << endl;
	for (int i = 0; i < numOfMembers; i++)
	{
		cout << "#" << i+1  << " " << allMembers[i]->getName() << endl;
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
		cout << "The member not found Please enter another name" << endl;
		char* newname = new char[20];
		cin >> newname;
		strcpy(name, newname);
		delete[] newname;
	}
}

//AllMembers :: ~AllMembers()
//{
//	for(int i=0;i<numOfMembers;i++)
//	{
//		delete allMembers[i];
//	}
//	delete[]allMembers;
//}

