#include "MembersArray.h"
using namespace std;

MembersArray:: MembersArray()
{
	membersArray = new Member * [numOfMaxMembers];
}

bool MembersArray::checkIfNameExist(char* name)
{
	for (int i = 0; i < numOfMembers; i++)
	{
		if (!strcmp(name, membersArray[i]->getName()))
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

void MembersArray::addMember(Member* m)
{
	if (numOfMaxMembers == numOfMembers) {
		numOfMaxMembers = numOfMaxMembers * 2;
		Member** tmp = new Member * [numOfMaxMembers];
		for (int i = 0; i < numOfMembers; i++)
			tmp[i] = membersArray[i];
		membersArray = tmp;
		tmp = nullptr;
		delete[] tmp;
	}

	membersArray[numOfMembers] = m;
	numOfMembers++;
}

void MembersArray:: deleteMember(Member* member)
{
	for (int i = 0; i < numOfMembers; i++)
	{
		if (!strcmp(membersArray[i]->getName(), member->getName()))
		{
			membersArray[i] = membersArray[numOfMembers-1];
			membersArray[numOfMembers - 1] = nullptr;
			numOfMembers--;
		}
	}
}


void MembersArray::printAllMembers()
{
	cout << "All the members:" << endl;

	if (numOfMembers == 0)
	{
		cout << "None"<<endl;
		return;
	}

	for (int i = 0; i < numOfMembers; i++)
	{
		cout << "#" << i+1  << " " << membersArray[i]->getName() << endl;
	}
}

Member* MembersArray::getMember(char* name)
{
	Member* theFoundMember = nullptr;

	for (int i = 0; i < numOfMembers; i++)
	{
		if (!strcmp(membersArray[i]->getName(), name))
		{
			theFoundMember = membersArray[i];
			return theFoundMember;
		}
	}
	return theFoundMember;
}

void MembersArray::showLast10StatusesOfEach()
{
	for (int i = 0; i < numOfMembers; i++)
	{
		membersArray[i]->printMyLast10Statuses();
	}
}

