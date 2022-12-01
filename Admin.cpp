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
	cout << "5 - show 10 new statuses of friends of member" << endl;
	cout << "6 - create friendship" << endl;
	cout << "7 - delete friendship" << endl;
	cout << "8 - add fan to fan page" << endl;
	cout << "9 - delete fan from fan page" << endl;
	cout << "10 - show all acounts and fan pages" << endl;
	cout << "11 - show all friends of member/fans of fan page" << endl;
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
			showLast10StatusesOfFriendsOfMember();
			break;
		case 6:
			makeFriendship();
			break;
		case 7:
			unFriendship();
			break;
		case 8:
			ConnectFanToPage();
			break;
		case 9:
			disConnectFanAndPage();
			break;
		case 10:
			users.printAllMembers();
			fanPages.printAllPages();
			break;
		case 11:
			printAllFriendsOfMemberOrFanPage();
			break;
		}

	} while (action != 12);
}

void Admin::createMember()
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

	do {
		cout << "If you want to add status to member enter 1, if you want to add status to a fan page enter 2" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) //to member
		{
			Member* tmpMember = nullptr;
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
			FanPage* tmpPage = nullptr;
			fanPages.printAllPages();
			do
			{
				cout << "Please enter the name of the paeg from the list" << endl;
				cin.getline(name, 20);
				tmpPage = fanPages.findPage(name);
				if (tmpPage == nullptr)
				{
					cout << "The member not found Please enter another name" << endl;
				}
			} while (tmpPage == nullptr);

			tmpPage->addStatus();
			return;
		}
	} while ((choice != 1) || (choice != 2));
}

void Admin::showAllStatusesOfMemberOrFanPage()
{
	int choice;
	char name[20];

	do {
		cout << "Enter 1 to choose a member, 2 to choose a fan page or 3 to go back to main menu" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) //to member
		{
			Member* tmpMember = nullptr;
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
			FanPage* tmpPage = nullptr;
			fanPages.printAllPages();
			do
			{
				cout << "Please enter the name of the fan page you want" << endl;
				//cin.ignore();
				cin.getline(name, 20);
				tmpPage = fanPages.findPage(name);
				if (tmpPage == nullptr)
				{
					cout << "The member not found Please enter another name" << endl;
				}
			} while (tmpPage == nullptr);			
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

void Admin::makeFriendship(Member member1, Member member2)
{
	member1.addFriend(&member2);
}

void Admin::unFriendship()
{
	char name1[20];
	char name2[20];
	Member* member1;
	Member* member2 = nullptr;

	users.printAllMembers();
	getchar(); //clear the buffer 

	do {
		cout << "Please Choose the first member" << endl;
		//cin.ignore();
		cin.getline(name1, 20);
		member1 = users.getMember(name1);
		if (member1 == nullptr)
			cout << "No such user please try again" << endl;

	} while (member1 == nullptr);

	if (member1->getNumOfFriends() == 0)
	{
		cout << "This member doesn't have any friends yet" << endl;
		return;
	}
	else
	{
		member1->showFriends();
	}

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
			if (!member1->checkFriendship(name2))
				cout << "They are not friends, please choose another friend" << endl;
		}
	} while ((member2 == nullptr) || !member1->checkFriendship(name2));

	member1->unFriend(member2);
}

void Admin::disConnectFanAndPage()
{
	char nameOfMember[20];
	char nameOfPage[20];
	Member* member = nullptr;
	FanPage* page = nullptr;

	getchar(); //clear the buffer 

	do
	{
		fanPages.printAllPages();
		do {
			cout << "Please Choose the fan page" << endl;
			cin.getline(nameOfPage, 20);
			page = fanPages.findPage(nameOfPage);
			if (page == nullptr)
				cout << "No such page please try again" << endl;
		} while ((page == nullptr));

		if (page->getNumOfFans() == 0)
		{
			cout << "This fanPage doesn't have any fans yet" << endl;
			return;
		}
		else
		{
			page->printFans();
		}

		do {
			cout << "Please Choose the member" << endl;
			cin.getline(nameOfMember, 20);
			member = users.getMember(nameOfMember);
			if (member == nullptr)
				cout << "No such user please try again" << endl;
		} while (member == nullptr);

		if (!(member->checkIfAlreadyFolowing(nameOfPage)))
		{
			cout << "This member doesn't follow this page " << endl;
		}

	} while (!member->checkIfAlreadyFolowing(nameOfPage));

	member->disConnectPage(page);
}

void Admin::ConnectFanToPage(Member member, FanPage page) 
{
	member.followPage(&page);
}

void Admin::ConnectFanToPage() //להודפיס את כל הדפים שהחבר הנחבר עוקב אחריהם
{
	char nameOfMember[20];
	char nameOfPage[20];
	Member* member1 = nullptr;
	FanPage* page1 = nullptr;

	users.printAllMembers();

	do
	{
		getchar(); //clear the buffer 
		do {
			cout << "Please Choose the member" << endl;
			cin.getline(nameOfMember, 20);
			member1 = users.getMember(nameOfMember);
			if (member1 == nullptr)
				cout << "No such user please try again" << endl;
		} while (member1 == nullptr);

		do {
			fanPages.printAllPages();
			cout << "Please Choose the fan page" << endl;
			cin.getline(nameOfPage, 20);
			page1 = fanPages.findPage(nameOfPage);
			if (page1 == nullptr)
				cout << "No such page please try again" << endl;
		} while ((page1 == nullptr));

		if ((!member1->checkIfAlreadyFolowing(nameOfPage)))
		{
			member1->followPage(page1);
		}
		else
		{
			cout << "They are already connected";
		}
	} while (!member1->checkIfAlreadyFolowing(nameOfPage));
	
}

void Admin::printAllFriendsOfMemberOrFanPage()
{
	int choice;
	char name[20];

	do {
		cout << "Enter 1 to choose a member, 2 to choose a fan page or 3 to go back to main menu" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) 
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

		else if (choice == 2) 
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

		else if (choice == 3)
			break;

		else
			cout << "Ivalid input"<<endl;
	

	} while ((choice != 1) || (choice != 2));
}

void Admin::showLast10StatusesOfFriendsOfMember()
{
	char name1[20];
	Member* member1 = nullptr;

	users.printAllMembers();
	getchar(); //clear the buffer 

	do {
		cout << "Please Choose the first member" << endl;
		cin.getline(name1, 20);
		member1 = users.getMember(name1);
		if (member1 == nullptr)
			cout << "No such user please try again" << endl;
	} while (member1 == nullptr);

	member1->Show10MyFriendsLastStatuses();
}
