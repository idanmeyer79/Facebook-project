#include "Member.h"
#include <cmath>
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

Member::Member(char* name, Date date) : dateOfBirth(date)
{
	memberName = new char[strlen(name) + 1];
	strcpy(memberName, name);
	memberFriends = new MembersArray;
	memberFanPages = new PagesArray;
	//שיש שדות לא מאותחלים פה
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

void Member :: addFriend(Member* member)
{
	memberFriends->addMember(member);
	member->memberFriends->addMember(this);
}

//Member** Member :: membersRealloc (Member** arrOfPFriends, int numOfNewFriends)
//{
//	Member** newFriends = new Member*[numOfNewFriends];
//	for (int i = 0; i < numOfNewFriends - 1; i++)
//	{
//		newFriends[i] = arrOfPFriends[i];
//		delete arrOfPFriends[i];
//	}
//	delete[] arrOfPFriends;
//	return newFriends;
//}
//
//void Member :: removeFriend(Member* member1, Member* member2)
//{
//	for (int i = 0; i < member1->numOfFriendsOfMember; i++)
//	{
//		if (member1->memberFriends[i] == member2)
//		{
//			member1->memberFriends[i] = member1->memberFriends[member1->numOfFriendsOfMember];
//			member1->memberFriends[member1->numOfFriendsOfMember] = nullptr;
//			member1->numOfFriendsOfMember--;
//			member1->memberFriends = membersRealloc(member1->memberFriends, member1->numOfFriendsOfMember);
//			return;
//		}
//	}
//
//	for (int i = 0; i < member2->numOfFriendsOfMember; i++)
//	{
//		if (member2->memberFriends[i] == member1)
//		{
//			member2->memberFriends[i] = member2->memberFriends[member2->numOfFriendsOfMember];
//			member2->memberFriends[member2->numOfFriendsOfMember] = nullptr;
//			member2->numOfFriendsOfMember--;
//			member2->memberFriends = membersRealloc(member2->memberFriends, member2->numOfFriendsOfMember);
//			return;
//		}
//	}
//}
//
void Member::showFriends() 
{
	memberFriends->printAllMembers();
}

void Member :: addStatus()
{
	char text[100];
	cout << "Please enter new status: " << endl;
	cin.getline(text,100);
	Status* status = new Status(text);
	memberStatuses.addStatusToArray(*status);
}

void Member:: addStatus(Status& status)
{
	memberStatuses.addStatusToArray(status);
}

//לא צקיך יש כבר ריאלוק בסטטוסאריי
// Status** Member::statusRealloc(Status** arrOfPStatuses, int numOfStatusesOfMember)
//{
//	Status** newStatuses = new Status * [numOfStatusesOfMember];
//	for (int i = 0; i < numOfStatusesOfMember-1; i++)
//	{
//		newStatuses[i] = arrOfPStatuses[i];
//		delete arrOfPStatuses[i];
//	}
//	delete[] arrOfPStatuses;
//	return newStatuses;
//}

/*oid Member::showFanPage()
{
	for (int i = 0; i < numOfFanPagesOfMember; i++)
	{
		cout << memberFanPages[i]->getName() << endl;
	}
}*/

void Member::showMyStatuses()
{
	memberStatuses.printAllStatuses();
}
 
bool Member::checkFriendship(char* name)
{
	return memberFriends->getMember(name);
}
//void Member::addFanPage(FanPage* fanPage, Member* member1)
//{
//	member1->numOfFanPagesOfMember++;
//	member1->memberFanPages = fanPageRealloc(member1->memberFanPages, member1->numOfFanPagesOfMember);
//	member1->memberFanPages[member1->numOfFanPagesOfMember] = fanPage;
//}
//
//FanPage** Member::fanPageRealloc(FanPage** arrOfPFanPages, int numOfFanPagesOfMember)
//{
//	FanPage** newFanPages = new FanPage * [numOfFanPagesOfMember];
//	for (int i = 0; i < numOfFanPagesOfMember - 1; i++)
//	{
//		newFanPages[i] = arrOfPFanPages[i];
//		delete arrOfPFanPages[i];
//	}
//	delete[] arrOfPFanPages;
//	return newFanPages;
//}
//
//void Member::Show10LastStatuses(Member* member)
//{
//	for (int i = 0; i < member->numOfFriendsOfMember; i++)
//	{
//		int friendNumOfStatuses = min(member->memberFriends[i]->numOfStatusesOfMember, 10);
//		for (int k = member->memberFriends[i]->numOfStatusesOfMember; k < friendNumOfStatuses; k--)
//		{
//			member->memberFriends[i]->memberStatuses[k]->printStatus();
//		}
//	}
//}