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

void MembersArray::printAllMembers()
{
	cout << "All the members:" << endl;
	for (int i = 0; i < numOfMembers; i++)
	{
		cout << "#" << i+1  << " " << membersArray[i]->getName() << endl;
	}
}

//Member* MembersArray::getMember(char* name)
//{
//	Member* theFoundMember = nullptr;
//
//	while (theFoundMember == nullptr) {
//		for (int i = 0; i < numOfMembers; i++)
//		{
//			if (!strcmp(membersArray[i]->getName(), name))
//				{
//					theFoundMember = membersArray[i];
//					return theFoundMember;
//				}
//		}
//		cout << "The member not found Please enter another name" << endl;
//		char* newname = new char[20];
//		cin >> newname;
//		strcpy(name, newname);
//		delete[] newname;
//	}
//}

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


//AllMembers :: ~AllMembers()
//{
//	for(int i=0;i<numOfMembers;i++)
//	{
//		delete allMembers[i];
//	}
//	delete[]allMembers;
//}

