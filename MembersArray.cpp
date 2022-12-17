#include "MembersArray.h"
using namespace std;

//MembersArray:: MembersArray()
//{
//	membersArray = new Member * [numOfMaxMembers];
//}

//MembersArray::~MembersArray()
//{
//	for(int i =0;i<numOfMembers;i++)
//	{
//		delete membersArray[i];
//	}
//	delete[]membersArray;
//}

bool MembersArray::checkIfNameExist(const string name) const
{
	vector<Member*>::const_iterator itr = membersArray.begin();
	vector<Member*>::const_iterator itrEnd = membersArray.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName()==name)//!strcmp(name, membersArray[i]->getName()))
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

void MembersArray::addMember(Member& m)
{
	//if (numOfMaxMembers == numOfMembers) {
	//	numOfMaxMembers = numOfMaxMembers * 2;
	//	Member** tmp = new Member * [numOfMaxMembers];
	//	for (int i = 0; i < numOfMembers; i++)
	//		tmp[i] = membersArray[i];
	//	membersArray = tmp;
	//	tmp = nullptr;
	//	delete[] tmp;
	//}
	membersArray.push_back(&m);
	//membersArray[numOfMembers] = &m;
	//numOfMembers++;
}

Member* MembersArray::addMember(const string name, const Date& dateOfBirth)
{
	Member* member = new Member(name, dateOfBirth);

	//if (numOfMaxMembers == numOfMembers) {
	//	numOfMaxMembers = numOfMaxMembers * 2;
	//	Member** tmp = new Member * [numOfMaxMembers];
	//	for (int i = 0; i < numOfMembers; i++)
	//		tmp[i] = membersArray[i];
	//	membersArray = tmp;
	//	tmp = nullptr;
	//	delete[] tmp;
	//}
	membersArray.push_back(member);
	return member;
	/*membersArray[numOfMembers] = member1;
	numOfMembers++;
	return member1;*/
}

void MembersArray:: deleteMember(Member& member)
{
	vector<Member*>::iterator itr = membersArray.begin();
	vector<Member*>::iterator itrEnd = membersArray.end();

	for (; itr!=itrEnd; ++itr)
	{
		if ((*itr)->getName()== member.getName())
		{
			membersArray.erase(itr);
			return;
		}
	}
}

void MembersArray::printAllMembers() const
{

	vector<Member*>::const_iterator itr = membersArray.begin();
	vector<Member*>::const_iterator itrEnd = membersArray.end();
	int numOfMembers = membersArray.size();
	int i = 0;
	cout << "All the members:" << endl;

	if (numOfMembers == 0)
	{
		cout << "None"<<endl;
		return;
	}

	for (; itr != itrEnd; ++itr)
	{
		cout << "#" << ++i  << " " << (*itr)->getName() << endl;
	}
}


Member* MembersArray::getMember(const string name) const
{
	vector<Member*>::const_iterator itr = membersArray.begin();
	vector<Member*>::const_iterator itrEnd = membersArray.end();

	Member* theFoundMember = nullptr;

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == name)
		{
			theFoundMember = (*itr);
			return theFoundMember;
		}
	}
	return theFoundMember;
}

void MembersArray::showLast10StatusesOfEach() const
{
	vector<Member*>::const_iterator itr = membersArray.begin();
	vector<Member*>::const_iterator itrEnd = membersArray.end();

	for (; itr != itrEnd; ++itr)
	{
		(*itr)->printMyLast10Statuses();
	}
}


