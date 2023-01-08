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

/**
 * Allows the user to pick an action to perform.
 * @param io A reference to a FacebookIO object that handles input/output operations.
 * @param admin A reference to an Admin object that represents the administrator of the Facebook-like social network.
 */
void pickAction(FacebookIO& io, Admin& admin);

/**
 * Allows the user to add a status to a Member object or a FanPage object.
 * @param admin A reference to an Admin object that represents the administrator of the Facebook-like social network.
 * @param io A reference to a FacebookIO object that handles input/output operations.
 * @throws std::invalid_argument If the selected Member or FanPage does not exist.
 */
void addStatusToFanPagesOrMember(Admin& admin, FacebookIO& io) noexcept(false);

/**
 * Shows all statuses of a Member object or a FanPage object.
 * @param admin A reference to an Admin object that represents the administrator of the Facebook-like social network.
 * @param io A reference to a FacebookIO object that handles input/output operations.
 * @throws std::invalid_argument If the selected Member or FanPage does not exist.
 */
void ShowAllFanPageOrMemberStatuses(Admin& admin, FacebookIO& io) noexcept(false);

/**
 * Shows the 10 latest statuses of a Member object or a FanPage object.
 * @param admin A reference to an Admin object that represents the administrator of the Facebook-like social network.
 * @param io A reference to a FacebookIO object that handles input/output operations.
 */
void Show10LatestStatuses(Admin& admin, FacebookIO& io);

/**
 * Allows the user to create a friendship between two Member objects.
 * @param admin A reference to an Admin object that represents the administrator of the Facebook-like social network.
 * @param io A reference to a FacebookIO object that handles input/output operations.
 * @throws std::invalid_argument If one or both of the selected Member objects do not exist.
 */
void createFriendship(Admin& admin, FacebookIO& io) noexcept(false);

/**
 * Allows the user to delete a friendship between two Member objects.
 * @param admin A reference to an Admin object that represents the administrator of the Facebook-like social network.
 * @param io A reference to a FacebookIO object that handles input/output operations.
 * @throws std::invalid_argument If one or both of the selected Member objects do not exist, or if they are not friends.
 */
void deleteFriendship(Admin& admin, FacebookIO& io) noexcept(false);

/**
 * Allows the user to add a Member object as a fan of a FanPage object.
 * @param admin A reference to an Admin object that represents the administrator of the Facebook-like social network.
 * @param io A reference to a FacebookIO object that handles input/output operations.
 * @throws std::invalid_argument If the selected Member object or FanPage object do not exist, or if the Member is already a fan of the FanPage.
 */
void addFanToFanPage(Admin& admin, FacebookIO& io) noexcept(false);

/**
 * Allows the user to remove a Member object as a fan of a FanPage object.
 * @param admin A reference to an Admin object that represents the administrator of the Facebook-like social network.
 * @param io A reference to a FacebookIO object that handles input/output operations.
 * @throws std::invalid_argument If the selected Member object or FanPage object do not exist, or if the Member is not a fan of the FanPage.
 */
void removeFanFromFanPage(Admin& admin, FacebookIO& io) noexcept(false);

/**
 * Shows all friends of a Member object or all fans of a FanPage object.
 * @param admin A reference to an Admin object that represents the administrator of the Facebook-like social network.
 * @param io A reference to a FacebookIO object that handles input/output operations.
 * @throws std::invalid_argument If the selected Member or FanPage does not exist.
 */
void showAllFriendsOfMemberOrFansOfFanPage(Admin& admin, FacebookIO& io) noexcept(false);


int main()
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
			try
			{
				addStatusToFanPagesOrMember(admin, io);
				break;
			}
			catch (const int& e) { cout << "Error: " << e << " " << "\033[1;31mis invalid!\033[0m" << endl; }
			break;
		}
		case SHOW_STATUSES:
		{
			try
			{
				ShowAllFanPageOrMemberStatuses(admin, io);
				break;
			}
			catch (const int& e) { cout << "Error: " << e << " " << "\033[1;31mis invalid!\033[0m" << endl; }
			break;
		}
		case SHOW_FEED:
		{
			Show10LatestStatuses(admin, io);
			break;
		}
		case MAKE_FRIENDSHIP:
		{
			try
			{
				createFriendship(admin, io);
				break;
			}
			catch (const invalid_argument& e) { cout << "Error: " << e.what() << endl; }
			break;

		}
		case DELETE_FRIENSHIP:
		{
			try
			{
				deleteFriendship(admin, io);
				break;
			}
			catch (const invalid_argument& e) { cout << "Error: " << e.what() << endl; }
			break;
		}
		case FOLLOW_PAGE:
		{
			try
			{
				addFanToFanPage(admin, io);
				break;
			}
			catch (const invalid_argument& e) { cout << "Error: " << e.what() << endl; }
			catch (const string& e) { cout << "Error: " << e << " " << "\033[1;31mdoesn't exist in the system!\033[0m" << endl; }
			break;
		}
		case UNFOLLOW_PAGE:
		{
			try
			{
				removeFanFromFanPage(admin, io);
				break;
			}
			catch (const invalid_argument& e) { cout << "Error: " << e.what() << endl; }
			catch (const string& e) { cout << "Error: " << e << " "<< "\033[1;31mdoesn't exist in the system!\033[0m" << endl; }
			break;

		}
		case SHOW_ACCOUNTS:
			admin.printAccounts();
			break;
		case SHOW_FRIENDS:
		{
			try
			{
				showAllFriendsOfMemberOrFansOfFanPage(admin, io);
				break;
			}
			catch (const int& e) { cout << "Error: " << e << " " << "\033[1;31mis invalid!\033[0m" << endl; }
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
		Member* member = io.getMemberException();
		Status* status = io.getStatusFromUser();
		admin.addStatusToMember(member, status);
	}
	else if (selector == FAN_PAGE)
	{
		FanPage* page = io.getPageException();
		Status *status = io.getStatusFromUser();
		admin.addStatusToPage(page, status);
	}
	else
		throw selector;

	io.success();
}

void ShowAllFanPageOrMemberStatuses(Admin& admin, FacebookIO& io)
{
	int selector = io.selectMemberOrPage();

	if (selector == MEMBER)
	{
		Member* member = io.getMemberException();
		io.printAllMemberStatuses(*member);
	}
	else if (selector == FAN_PAGE)
	{
		FanPage* page = io.getPageException();
		io.printAllPageStatuses(*page);
	}
	else
		throw selector;
}

void Show10LatestStatuses(Admin& admin, FacebookIO& io)
{
	Member* member = io.getMemberException();
	if (member->getNumOfFriends() == 0)
		io.displayMessage("\033[1;31mThe member doesnt have any friends.\033[0m");
	else
		member->showLast10StatusesOfEach();
}

void createFriendship(Admin& admin, FacebookIO& io)
{
	Member* member1 = io.getMemberException();
	io.displayMessage("Please Choose the second member from the list: ");

	string name2 = io.getUserInput();
	if (member1->getName() == name2)
		throw invalid_argument("\033[1;31mIts the same member as the first one.\033[0m");
	Member* member2 = io.getMember(name2);

	if (!member2)
		throw invalid_argument("\033[1;31mThis name is not in the system!\033[0m");

	if ((!member1->checkFriendship(member2->getName())))
	{
		admin.makeFriendship(*member1, *member2);
		io.success();
	}

	else
		throw invalid_argument("\033[1;31mThey are already friends.\033[0m");
}

void deleteFriendship(Admin& admin, FacebookIO& io)
{
	Member* member1 = io.getMemberException();

	if (member1->getNumOfFriends() == 0)
		throw invalid_argument("\033[1;31mThis member doesn't have any friends yet.\033[0m");

	member1->showFriends();
	io.displayMessage("Please Choose the member you want to unfriend");

	string name2 = io.getUserInput();
	Member* member2 = io.getMember(name2);

	if (!member2)
		throw invalid_argument("\033[1;31mThis name is not in the system!\033[0m");

	if ((!member1->checkFriendship(name2)))
		throw invalid_argument("\033[1;31mThey are already not friends.\033[0m");

	admin.unFriendship(*member1, *member2);
	io.success();
}

void addFanToFanPage(Admin& admin, FacebookIO& io)
{
	Member* member = io.getMemberException();
	io.printAllPages();
	io.displayMessage("Please enter the page's name from the list:  ");
	string name = io.getUserInput();
	FanPage* page = io.getPage(name);

	if (!page)
		throw name;

	if (member->checkIfAlreadyFolowing(page->getName()))
		throw invalid_argument("\033[1;31mThey are already connected.\033[0m");

	admin.ConnectFanToPage(*member, *page);
	io.success();
}

void removeFanFromFanPage(Admin& admin, FacebookIO& io)
{
	Member* member = io.getMemberException();

	if (member->getNumOfPages() == 0)
		throw invalid_argument("\033[1;31mThis member doesn't follow any pages yet.\033[0m");

	member->printAllPages();
	io.displayMessage("Please enter the page's name from the list:  ");
	string name = io.getUserInput();
	FanPage* page = io.getPage(name);

	if (!page)
		throw name;

	if (!(member->checkIfAlreadyFolowing(page->getName())))
		throw invalid_argument("\033[1;31mThis member doesn't follow this page yet.\033[0m");

	admin.disConnectFanAndPage(*member, *page);
	io.success();
}

void showAllFriendsOfMemberOrFansOfFanPage(Admin& admin, FacebookIO& io)
{
	int selector = io.selectMemberOrPage();
	if (selector == MEMBER)
	{
		Member* member = io.getMemberException();
		member->showFriends();
		member->showFanPages();
	}
	else if (selector == FAN_PAGE)
	{
		FanPage* page = io.getPageException();
		cout << page->getName() << "'s fans are:" << endl;
		page->printFans();
		return;
	}
	else
		throw selector;
}