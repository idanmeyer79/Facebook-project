#include "Member.h"
#include <iostream>
#include <cmath>
#pragma warning(disable: 4996)
using namespace std;

Member::Member(char* Name, Date date)
{
	strcpy(memberName, Name);
	dateOfBirth = date;
}

void Member :: setName(char* Name)
{
	memberName = Name;
}

char* Member :: getName()
{
	return memberName;
}

void Member :: setDate(Date date)
{
	dateOfBirth = date;
}

Date Member :: getDate()
{ 
	return dateOfBirth; 
}

void Member :: addFriend(Member* member1, Member* member2)
{
	member1->numOfFriendsOfMember++;
	member2->numOfFriendsOfMember++;

	member1->memberFriends = membersRealloc(member1->memberFriends, member1->numOfFriendsOfMember);
	member1->memberFriends[member1->numOfFriendsOfMember] = member2;

	member2->memberFriends = membersRealloc(member2->memberFriends, member2->numOfFriendsOfMember);
	member2->memberFriends[member2->numOfFriendsOfMember] = member1;
}

Member** Member :: membersRealloc (Member** arrOfPFriends, int numOfNewFriends)
{
	Member** newFriends = new Member*[numOfNewFriends];
	for (int i = 0; i < numOfNewFriends - 1; i++)
	{
		newFriends[i] = arrOfPFriends[i];
		delete arrOfPFriends[i];
	}
	delete[] arrOfPFriends;
	return newFriends;
}

void Member :: removeFriend(Member* member1, Member* member2)
{
	for (int i = 0; i < member1->numOfFriendsOfMember; i++)
	{
		if (member1->memberFriends[i] == member2)
		{
			member1->memberFriends[i] = member1->memberFriends[member1->numOfFriendsOfMember];
			member1->memberFriends[member1->numOfFriendsOfMember] = nullptr;
			member1->numOfFriendsOfMember--;
			member1->memberFriends = membersRealloc(member1->memberFriends, member1->numOfFriendsOfMember);
			return;
		}
	}

	for (int i = 0; i < member2->numOfFriendsOfMember; i++)
	{
		if (member2->memberFriends[i] == member1)
		{
			member2->memberFriends[i] = member2->memberFriends[member2->numOfFriendsOfMember];
			member2->memberFriends[member2->numOfFriendsOfMember] = nullptr;
			member2->numOfFriendsOfMember--;
			member2->memberFriends = membersRealloc(member2->memberFriends, member2->numOfFriendsOfMember);
			return;
		}
	}
}

void Member::showFriends() 
{
	for (int i = 0; i < numOfFriendsOfMember; i++)
	{
		cout << memberFriends[i]->getName() << endl;
	}
}

void Member :: addStatus()
{
	numOfStatusesOfMember++;
	Status* newStatus;
	memberStatuses = statusRealloc(memberStatuses, numOfStatusesOfMember);
	memberStatuses[numOfStatusesOfMember] = newStatus;
}

Status** Member::statusRealloc(Status** arrOfPStatuses, int numOfStatusesOfMember)
{
	Status** newStatuses = new Status * [numOfStatusesOfMember];
	for (int i = 0; i < numOfStatusesOfMember-1; i++)
	{
		newStatuses[i] = arrOfPStatuses[i];
		delete arrOfPStatuses[i];
	}
	delete[] arrOfPStatuses;
	return newStatuses;
}

void Member::showFanPage()
{
	for (int i = 0; i < numOfFanPagesOfMember; i++)
	{
		cout << memberFanPages[i]->getName() << endl;
	}
}

void Member::showMyStatuses()
{
	for (int i = 0; i < numOfStatusesOfMember; i++)
	{
		memberStatuses[i]->printStatus();
	}
}
 
void Member::addFanPage(FanPage* fanPage, Member* member1)
{
	member1->numOfFanPagesOfMember++;
	member1->memberFanPages = fanPageRealloc(member1->memberFanPages, member1->numOfFanPagesOfMember);
	member1->memberFanPages[member1->numOfFanPagesOfMember] = fanPage;
}

FanPage** Member::fanPageRealloc(FanPage** arrOfPFanPages, int numOfFanPagesOfMember)
{
	FanPage** newFanPages = new FanPage * [numOfFanPagesOfMember];
	for (int i = 0; i < numOfFanPagesOfMember - 1; i++)
	{
		newFanPages[i] = arrOfPFanPages[i];
		delete arrOfPFanPages[i];
	}
	delete[] arrOfPFanPages;
	return newFanPages;
}

Member* Member::findMember(char* name)
{
	Member* theFoundMember = nullptr;

	while (theFoundMember == nullptr) {
		for (int i = 0; i < NumOfMembers; i++)
		{
			/*if (!strcmp(allmembers[i]->name, name))
				{
					theFoundMember = allmembers[i]->name;
					return theFoundMember;
				}*/
		}
		cout << "The member not found Please enter anothe name" << endl;
		char* newname = new char[20];
		cin >> newname;
		strcpy(name, newname);
		delete[] newname;
	}
}

void Member::Show10LastStatuses(Member* member)
{
	for (int i = 0; i < member->numOfFriendsOfMember; i++)
	{
		int friendNumOfStatuses = min(member->memberFriends[i]->numOfStatusesOfMember, 10);
		for (int k = member->memberFriends[i]->numOfStatusesOfMember; k < friendNumOfStatuses; k--)
		{
			member->memberFriends[i]->memberStatuses[k]->printStatus();
		}
	}
}