#include <iostream>
#include "Admin.h"
#include "FacebookIO.h"
#include <crtdbg.h>

#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

using namespace std;

constexpr int MEMBER = 1;
constexpr int ADD_MEMBER = 1;
constexpr int FAN_PAGE = 2;
constexpr int ADD_FAN_PAGE = 2;
constexpr int ADD_STATUS = 3;
constexpr int SHOW_STATUSES = 4;
constexpr int SHOW_FEED = 5;
constexpr int MAKE_FRIENDSHIP = 6;
constexpr int DELETE_FRIENSHIP = 7;
constexpr int FOLLOW_PAGE = 8;
constexpr int UNFOLLOW_PAGE = 9;
constexpr int SHOW_ACCOUNTS = 10;
constexpr int SHOW_FRIENDS = 11;
constexpr int EXIT = 12;

void pickAction(FacebookIO& io, Admin& admin);
void addStatusToFanPagesOrMember(Admin& admin, FacebookIO& io);
void ShowAllFanPageOrMemberStatuses(Admin& admin, FacebookIO& io);
void Show10LatestStatuses(Admin& admin, FacebookIO& io);
void createFriendship(Admin& admin, FacebookIO& io);
void deleteFriendship(Admin& admin, FacebookIO& io);
void addFanToFanPage(Admin& admin, FacebookIO& io);
void removeFanFromFanPage(Admin& admin, FacebookIO& io);
void showAllFriendsOfMemberOrFansOfFanPage(Admin& admin, FacebookIO& io);

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		Admin admin;
		//hardcoded data//
		FanPage fanPage1("mondial");
		FanPage fanPage2("re'evim beravcha");
		FanPage fanPage3("keren kalif fans");
		Member member1("Boaz", Date(1, 1, 2020));
		Member member2("Romina", Date(2, 2, 2000));
		Member member3("Arie", Date(3, 3, 1997));
		member1 += member2;
		member1 += member3;
		member1 += fanPage1;
		fanPage2 += member1;
		member2 += fanPage1;
		fanPage1.addStatus("welcome to Mondial 2022");
		fanPage1.addStatus("Mondial 2022");
		fanPage2.addStatus("welcome to re'evim beravcha");
		fanPage2.addStatus("re'evim beravcha 2");
		fanPage3.addStatus("welcome to keren kalif fans");
		fanPage3.addStatus("keren kalif fans 2");
		member1.addStatus("Hey its Boaz");
		member1.addStatus("Boaz 2");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Romina 2");
		member3.addStatus("Hey its Arie");
		member3.addStatus("Arie 2");
		admin.addUserToFacebook(member1);
		admin.addUserToFacebook(member2);
		admin.addUserToFacebook(member3);
		admin.addPageToFacebook(fanPage1);
		admin.addPageToFacebook(fanPage2);
		admin.addPageToFacebook(fanPage3);
		//end of hard codeed data//

		FacebookIO io(&admin);
		io.wellcome();
		pickAction(io, admin);
	}
	_CrtDumpMemoryLeaks();
}

void pickAction(FacebookIO& io, Admin& admin)
{
	int action;
	do
	{
		io.printMenu();
		std::cin.sync();
		cin >> action;
		switch (action) {
		case ADD_MEMBER:
			admin.addUserToFacebook(io.getDetailsForMember());
			io.success();
			break;
		case ADD_FAN_PAGE:
			admin.addPageToFacebook(io.getDetailsForPage());
			io.success();
			break;
		case ADD_STATUS:
		{
			addStatusToFanPagesOrMember(admin,io);
			break;
		}
		case SHOW_STATUSES:
		{
			ShowAllFanPageOrMemberStatuses(admin, io);
			break;
		}
		case SHOW_FEED:
		{
			Show10LatestStatuses(admin, io);
			break;
		}
		case MAKE_FRIENDSHIP:
		{
			createFriendship(admin, io);
			break;
		}
		case DELETE_FRIENSHIP:
		{
			deleteFriendship(admin, io);
			break;
		}
		case FOLLOW_PAGE:
		{
			addFanToFanPage(admin, io);
			break;
		}
		case UNFOLLOW_PAGE:
		{
			removeFanFromFanPage(admin, io);
			break;
		}
		case SHOW_ACCOUNTS:
			admin.printAccounts();
			break;
		case SHOW_FRIENDS:
		{
			showAllFriendsOfMemberOrFansOfFanPage(admin, io);
			break;
		}
		case EXIT:
			break;
		default:
			io.InvalidAction();
			break;
		cout << endl;
	}
		}while (action != EXIT);
		io.displayMessage("\033[32mBye Bye :)\033[0m");
}

void addStatusToFanPagesOrMember(Admin& admin,FacebookIO& io)
{
	int selector = io.selectMemberOrPage();
	if (selector == MEMBER)
	{
		getchar();
		io.displayMessage("All the members : ");
		io.printAllMembers();
		io.displayMessage("Please enter the member's name from the list: ");
		string name = io.getUserInput();
		Member* member = io.getMember(name);
		if (!member)
		{
			io.noSuchName();
			return;
		}
		Status status = io.getStatusFromUser();
		admin.addStatusToMember(member, status);
	}
	else if (selector == FAN_PAGE)
	{
		getchar();
		io.printAllPages();
		io.displayMessage("Please enter the page's name: ");
		string name = io.getUserInput();
		FanPage* page = io.getPage(name);
		if (!page)
		{
			io.noSuchName();
			return;
		}
		Status status = io.getStatusFromUser();
		admin.addStatusToPage(page, status);
	}
	else
		io.InvalidAction();

	io.success();
}

void ShowAllFanPageOrMemberStatuses(Admin& admin, FacebookIO& io)
{
	int selector = io.selectMemberOrPage();
	if (selector == MEMBER)
	{
		getchar();
		io.displayMessage("All the members : ");
		io.printAllMembers();
		io.displayMessage("Please enter the member's name from the list: ");
		string name = io.getUserInput();
		Member* member = io.getMember(name);
		if (!member)
		{
			io.noSuchName();
			return;
		}
		io.printAllMemberStatuses(*member);
	}
	else if (selector == FAN_PAGE)
	{
		getchar();
		io.printAllPages();
		io.displayMessage("Please enter the page's name: ");
		string name = io.getUserInput();
		FanPage* page = io.getPage(name);
		if (!page)
		{
			io.noSuchName();
			return;
		}
		io.printAllPageStatuses(*page);
	}
	else
		io.InvalidAction();
}

void Show10LatestStatuses(Admin& admin, FacebookIO& io)
{
	getchar();
	io.displayMessage("All the members : ");
	io.printAllMembers();
	io.displayMessage("Please enter the member's name from the list: ");
	string name = io.getUserInput();
	Member* member = io.getMember(name);
	if (!member)
	{
		io.noSuchName();
		return;
	}
	if (member->getNumOfFriends() == 0)
		io.displayMessage("\033[1;31mThe member doesnt have any friends.\033[0m");
	else
		member->showLast10StatusesOfEach();
}

void createFriendship(Admin& admin, FacebookIO& io)
{
	getchar();
	io.displayMessage("All the members : ");
	io.printAllMembers();
	io.displayMessage("Please enter the member's name from the list: ");
	string name1 = io.getUserInput();
	Member* member1 = io.getMember(name1);
	if (!member1)
	{
		io.noSuchName();
		return;
	}
	io.displayMessage("Please Choose the second member from the list: ");
	string name2 = io.getUserInput();
	if (name1 == name2)
	{
		io.displayMessage("\033[1;31mIts the same member as the first one.\033[0m");
		return;
	}
	Member* member2 = io.getMember(name2);
	if (!member2)
	{
		io.noSuchName();
		return;
	}
	if ((!member1->checkFriendship(name2)))
	{
		admin.makeFriendship(*member1, *member2);
		io.success();
	}
	else
	{
		io.displayMessage("\033[1;31mThey are already friends.\033[0m");
		return;
	}
}

void deleteFriendship(Admin& admin, FacebookIO& io)
{
	getchar();
	io.displayMessage("All the members : ");
	io.printAllMembers();
	io.displayMessage("Please enter the member's name from the list: ");
	string name1 = io.getUserInput();
	Member* member1 = io.getMember(name1);
	if (!member1)
	{
		io.noSuchName();
		return;
	}
	if (member1->getNumOfFriends() == 0)
	{
		io.displayMessage("\033[1;31mThis member doesn't have any friends yet.\033[0m");
		return;
	}
	else
	{
		member1->showFriends();
	}
	io.displayMessage("Please Choose the member you want to unfriend");
	string name2 = io.getUserInput();
	Member* member2 = io.getMember(name2);
	if ((!member1->checkFriendship(name2)))
	{
		io.displayMessage("\033[1;31mThey are not friends.\033[0m");
		return;
	}
	else
	{
		admin.unFriendship(*member1, *member2);
		io.success();
		return;
	}
}

void addFanToFanPage(Admin& admin, FacebookIO& io)
{
	getchar();
	io.displayMessage("All the members : ");
	io.printAllMembers();
	io.displayMessage("Please enter the member's name from the list: ");
	string name = io.getUserInput();
	Member* member = io.getMember(name);
	if (!member)
	{
		io.noSuchName();
		return;
	}
	io.printAllPages();
	io.displayMessage("Please enter the page's name from the list:  ");
	name = io.getUserInput();
	FanPage* page = io.getPage(name);
	if (!page)
	{
		io.noSuchName();
		return;
	}
	if (member->checkIfAlreadyFolowing(page->getName()))
	{
		io.displayMessage("\033[1;31mThey are already connected.\033[0m");
		return;
	}
	admin.ConnectFanToPage(*member, *page);
	io.success();
}

void removeFanFromFanPage(Admin& admin, FacebookIO& io)
{
	getchar();
	io.displayMessage("All the members : ");
	io.printAllMembers();
	io.displayMessage("Please enter the member's name from the list: ");
	string name = io.getUserInput();
	Member* member = io.getMember(name);
	if (!member)
	{
		io.noSuchName();
		return;
	}
	if (member->getNumOfPages() == 0)
	{
		io.displayMessage("\033[1;31mThis member doesn't follow any pages yet.\033[0m");
		return;
	}
	member->printAllPages();
	io.displayMessage("Please enter the page's name from the list:  ");
	name = io.getUserInput();
	FanPage* page = io.getPage(name);
	if (!page)
	{
		io.noSuchName();
		return;
	}
	if (member->checkIfAlreadyFolowing(page->getName()))
	{
		admin.disConnectFanAndPage(*member, *page);
		io.success();
		return;
	}
	admin.ConnectFanToPage(*member, *page);
}

void showAllFriendsOfMemberOrFansOfFanPage(Admin& admin, FacebookIO& io)
{
	int selector = io.selectMemberOrPage();
	if (selector == MEMBER)
	{
		getchar();
		io.displayMessage("All the members : ");
		io.printAllMembers();
		io.displayMessage("Please enter the member's name from the list: ");
		string name = io.getUserInput();
		Member* member = io.getMember(name);
		if (!member)
		{
			io.noSuchName();
			return;
		}
		member->showFriends();
		member->showFanPages();
	}
	else if (selector == FAN_PAGE)
	{
		getchar();
		io.printAllPages();
		io.displayMessage("Please enter the page's name: ");
		string name = io.getUserInput();
		FanPage* page = io.getPage(name);
		if (!page)
		{
			io.noSuchName();
			return;
		}
		cout << page->getName() << "'s fans are:" << endl;
		page->printFans();
		return;
	}
	else
		io.InvalidAction();
}