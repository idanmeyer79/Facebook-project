#include "Admin.h"
using namespace std;

void Admin:: printMenu() 
{
	cout << "\n";
	cout << "Please choose an action:" << endl;
	cout << "1 - create a memeber" << endl;
	cout << "2 - create a fan page" << endl;
	cout << "3 - add status to a fan page/member" << endl;
	cout << "4 - show all fan page/member statuses" << endl;
	cout << "5 - show 10 new statuses" << endl;
	cout << "6 - add a friend" << endl;
	cout << "7 - delete friendship" << endl;
	cout << "8 - add fan page" << endl;
	cout << "9 - delete fan page" << endl;
	cout << "10 - show all acounts and fan pages" << endl;
	cout << "11 - show all friends/fans of member" << endl;
	cout << "12 - exit" << endl;
	cout << "_______________________" << endl;
	cout << "\n";
}

void Admin:: menu()
{
	int action;
	cout << "Wellcome to facebook!" << endl;
	do
	{
		printMenu();
		cin >> action;

		switch (action) {
		case 1:
			createMember();
			break;
		case 2:
			createFanPage();
			break;
		case 3:
			addStatusToFanPageOrMember();
			break;
		case 4:
			showAllStatusesOfMemberOrFanPage();
			break;
		case 5:

			break;
		case 6:
			makeFriendship();
			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:
			users.printAllMembers();
			fanPages.printAllPages();
			break;
		case 11:
			printAllFriends();
			break;
		}

	} while (action != 12);
}

void Admin:: createMember()
{
	Member* member = getDetailsForMember();
	users.addMember(member);
}

Member* Admin::getDetailsForMember()
{
	int day =0 , month =0, year=0;
	char slash_dummy;
	char name[20];
	getchar(); //clear the buffer 

	do {
		cout << "Please enter a name - max 20 letters" << endl;
		//cin.ignore();
		cin.getline(name, 20);
	} while (users.checkIfNameExist(name));

	Date date(day, month, year);
	do {
		cout << "Please enter date of birth - format dd/mm/yyyy" << endl;
		cin >> day >> slash_dummy >> month >> slash_dummy >> year;
		date.setDate(day, month, year);
	} while (!date.checkdate());

	Member* member = new Member (name, date);
	return member;
}

void Admin::createFanPage()
{
	FanPage* fanPage = getDetailsForPage();
	fanPages.addPage(fanPage);
}

FanPage* Admin::getDetailsForPage()
{
	char name[20];
	getchar(); //clear the buffer 

	do {
		cout << "Please enter the name  of the page- max 20 letters" << endl;
		//cin.ignore();
		cin.getline(name, 20);
	} while (fanPages.checkIfNameExist(name));

	FanPage* fanPage = new FanPage(name);
	return fanPage;
}

void Admin::addStatusToFanPageOrMember() {
	int choice;
	char name[20];

	Member* tmpMember= nullptr;
	getchar(); //clear the buffer 

	do {
		cout << "If you want to add status to member enter 1, if you want to add status to a fan page enter 2" << endl;
		cin >> choice;

		if (choice == 1) //to member
		{
			users.printAllMembers();
			do
			{
				cout << "Please enter the name of the member from the list" << endl;
				cin.getline(name, 20);
				tmpMember = users.getMember(name);
				if (tmpMember == nullptr)
				{
					cout << "The member not found Please enter another name" << endl;
				}
			} while (tmpMember == nullptr);

			tmpMember->addStatus();
			return;
		}
		else //to fan page
		{
			cout << "Please enter the name of the page you want" << endl;
			//cin.ignore();
			cin.getline(name, 20);
			FanPage* tmpPage = fanPages.findPage(name);
			tmpPage->addStatus();
			return;
		}
	} while ((choice != 1) || (choice != 2));
}

void Admin::showAllStatusesOfMemberOrFanPage()
{
	int choice;
	char name[20];
	Member* tmpMember= nullptr;

	do {
		cout << "Enter 1 to choose a member, 2 to choose a fan page or 3 to go back to main menu" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) //to member
		{
			users.printAllMembers();
			do
			{
				cout << "Please enter the name of the member from the list" << endl;
				cin.getline(name, 20);
				tmpMember = users.getMember(name);
				if (tmpMember == nullptr)
				{
					cout << "The member not found Please enter another name" << endl;
				}
			} while (tmpMember == nullptr);
			tmpMember->showMyStatuses();
			return;
		}
		else  //to fan page
		{
			cout << "Please enter the name of the member you want" << endl;
			//cin.ignore();
			cin.getline(name, 20);
			FanPage* tmpPage = fanPages.findPage(name);
			tmpPage->showMyStatuses();
			return;
		}
	} while ((choice != 1) || (choice != 2));

}

void Admin::makeFriendship()
{
	char name1[20];
	char name2[20];
	Member* member1;
	Member* member2 = nullptr;

	users.printAllMembers();
	getchar(); //clear the buffer 

	do
	{
		do {
			cout << "Please Choose the first member" << endl;
			//cin.ignore();
			cin.getline(name1, 20);
			member1 = users.getMember(name1);
			if (member1 == nullptr)
				cout << "No such user please try again"<<endl;
				
		} while (member1 == nullptr);

		do {
			cout << "Please Choose the second member" << endl;
			//cin.ignore();
			cin.getline(name2, 20);
			if (!(strcmp(name1, name2)))
			{
				cout << "Its the same member as the first one, please enter another one" << endl;
			}
			else
			{
				member2 = users.getMember(name2);
			}

			if (member2==nullptr)
				cout << "No such user please try again" << endl;

		} while ((member2 == nullptr) || !(strcmp(name1,name2)));

		if ((!member1->checkFriendship(name2)))
		{
			member1->addFriend(member2);
		}
		else
		{
			cout << "They are already friends";
		}

	} while (!member1->checkFriendship(name2));
}

void Admin:: makeFriendship(Member member1, Member member2)
{
	member1.addFriend(&member2);
}

void Admin::ConnectFanToPage(Member member, FanPage page) //new!
{
	member.followPage(&page);
}

//void Admin::ConnectFanToPage(Member member, FanPage page) //need to check this
//{
//	char name1[20];
//	char name2[20];
//	Member* member1 = nullptr;
//	FanPage* page1 = nullptr;
//
//	users.printAllMembers();
//	getchar(); //clear the buffer 
//
//	do
//	{
//		do {
//			cout << "Please Choose the member" << endl;
//			//cin.ignore();
//			cin.getline(name1, 20);
//			member1 = users.getMember(name1);
//			if (member1 == nullptr)
//				cout << "No such user please try again" << endl;
//
//		} while (member1 == nullptr);
//
//		do {
//			cout << "Please Choose the fan page" << endl;
//			//cin.ignore();
//			cin.getline(name2, 20);
//			if (!(strcmp(name1, name2)))
//			{
//				cout << "Its the same member as the first one, please enter another one" << endl;
//			}
//			else
//			{
//				page1 = fanPages.findPage(name2);
//			}
//
//			if (page1 == nullptr)
//				cout << "No such page please try again" << endl;
//
//		} while ((page1 == nullptr));
//
//		if ((!member1->checkFriendship(name2)))//need to write for pages
//		{
//			member1->followPage(page1);
//		}
//		else
//		{
//			cout << "They are already connected";
//		}
//
//	} while (!member1->checkFriendship(name2));
//}

void Admin::printAllFriends()
{
	int choice;
	char name[20];

	//למה צריך פה את הלולאה החיצונית בכלל?
	//do {
		cout << "Enter 1 to choose a member, 2 to choose a fan page or 3 to go back to main menu" << endl;
		//cout << "If you want to watch all friends of member enter 1, if you want to watch all fans of a fan page enter 2 or enter 3 to go back to main menu" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) //to member
		{
			Member* member;
			users.printAllMembers();
			do
			{
				cout << "Please enter the name of the member from the list" << endl;
				cin.getline(name, 20);
				member = users.getMember(name);
				if (member == nullptr)
				{
					cout << "The member not not found Please enter another name" << endl;
				}
			} while (member == nullptr);
			member->showFriends();
			member->showFanPages();
		}
		//חדש אני הוספתי
		else if (choice == 2) //to fan page
		{
			FanPage* fanPage;
			fanPages.printAllPages();
			do
			{
				cout << "Please enter the name of the page from the list" << endl;
				cin.getline(name, 20);
				fanPage = fanPages.findPage(name);
				if (fanPage == nullptr)
				{
					cout << "The page was not found Please enter another name" << endl;
				}
			} while (fanPage == nullptr);
			fanPage->printFans();
		}
	

	//} while ((choice != 1) || (choice != 2));
}
