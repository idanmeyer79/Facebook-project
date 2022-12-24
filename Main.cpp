#include <iostream>
#include "Admin.h"
#include "FacebookIO.h"
#include <crtdbg.h>

#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

using namespace std;

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

		admin.addUserToFacebook(member1);
		admin.addUserToFacebook(member2);
		admin.addUserToFacebook(member3);


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
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member2.addStatus("Hey its Romina");
		member3.addStatus("Hey its Arie");
		member3.addStatus("Arie 2");
		admin.addPageToFacebook(fanPage1);
		admin.addPageToFacebook(fanPage2);
		admin.addPageToFacebook(fanPage3);
		//end of hard codeed data//

		FacebookIO io(&admin);
		io.wellcome();
		int action;
		bool validName = false;

		do
		{
			io.printMenu();
			std::cin.sync();
			cin >> action;
			switch (action) {
			case 1:
				admin.addUserToFacebook(io.getDetailsForMember());
				break;
			case 2:
				admin.addPageToFacebook(io.getDetailsForPage());
				break;
			case 3:
			{
				int selector = io.selectMemberOrPage();
				if (selector == 1)
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
						break;
					}
					Status status = io.getStatusFromUser();
					admin.addStatusToMember(member, status);
				}
				else if (selector == 2)
				{
					getchar();
					io.printAllPages();
					io.displayMessage("Please enter the page's name: ");
					string name = io.getUserInput();
					FanPage* page = io.getPage(name);
					if (!page)
					{
						io.noSuchName();
						break;
					}
					Status status = io.getStatusFromUser();
					admin.addStatusToPage(page, status);
				}
				else
					io.InvalidAction();
				break;
			}
			case 4:
			{
				int selector = io.selectMemberOrPage();
				if (selector == 1)
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
						break;
					}
					io.printAllMemberStatuses(*member);
				}
				else if (selector == 2)
				{
					getchar();
					io.printAllPages();
					io.displayMessage("Please enter the page's name: ");
					string name = io.getUserInput();
					FanPage* page = io.getPage(name);
					if (!page)
					{
						io.noSuchName();
						break;
					}
					io.printAllPageStatuses(*page);
				}
				else
					io.InvalidAction();
			}
				break;
			case 5:
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
					break;
				}
				if (member->getNumOfFriends() == 0)
					io.displayMessage("\033[1;31mThe member doesnt have any friends.\033[0m");
				else
					member->showLast10StatusesOfEach();
				break;
			}
			case 6:
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
					break;
				}
				io.displayMessage("Please Choose the second member from the list: " );
				string name2 = io.getUserInput();
				if (name1==name2)
				{
					io.displayMessage("\033[1;31mIts the same member as the first one.\033[0m");
					break;
				}
				Member* member2 = io.getMember(name2);
				if (!member2)
				{
					io.noSuchName();
					break;
				}
				if ((!member1->checkFriendship(name2)))
				{
					admin.makeFriendship(*member1,*member2);
					cout << name1 << "\033[32m and \033[0m"  << name2 << "\033[32m are friends now :)\033[0m " << endl;
				}
				else
				{
					io.displayMessage("\033[1;31mThey are already friends.\033[0m");
					break;
				}
				break;
			}
				//admin.makeFriendship();
			case 7:
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
					break;
				}
				if (member1->getNumOfFriends() == 0)
				{
					io.displayMessage("\033[1;31mThis member doesn't have any friends yet.\033[0m");
					break;
				}
				else
				{
					member1->showFriends();
				}
				io.displayMessage( "Please Choose the member you want to unfriend" );
				string name2 = io.getUserInput();
				Member* member2 = io.getMember(name2);
				if ((!member1->checkFriendship(name2)))
				{
					io.displayMessage("\033[1;31mThey are not friends.\033[0m");
					break;
				}
				else
				{
					admin.unFriendship(*member1, *member2);
					break;
				}
				//admin.unFriendship();
				break;
			}
			case 8:
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
					break;
				}
				io.printAllPages();
				io.displayMessage("Please enter the page's name from the list:  ");
				name = io.getUserInput();
				FanPage* page = io.getPage(name);
				if (!page)
				{
					io.noSuchName();
					break;
				}
				if (member->checkIfAlreadyFolowing(page->getName()))
				{
					io.displayMessage("\033[1;31mThey are already connected.\033[0m");
					break;
				}
				admin.ConnectFanToPage(*member, *page);
				break;
			}				
			case 9:
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
					break;
				}
				if (member->getNumOfPages() == 0)
				{
					io.displayMessage("\033[1;31mThis member doesn't follow any pages yet.\033[0m");
					break;
				}
				member->printAllPages();
				io.displayMessage("Please enter the page's name from the list:  ");
				name = io.getUserInput();
				FanPage* page = io.getPage(name);
				if (!page)
				{
					io.noSuchName();
					break;
				}
				if (member->checkIfAlreadyFolowing(page->getName()))
				{
					admin.disConnectFanAndPage(*member,*page);
					io.displayMessage("sucsses!");
					break;
				}
				admin.ConnectFanToPage(*member, *page);
				break;
			}
			case 10:
				admin.printAcounts();
				break;
			case 11:
			{
				int selector = io.selectMemberOrPage();
				if (selector == 1)
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
						break;
					}
					member->showFriends();
					member->showFanPages();
				}
				else if (selector == 2)
				{	
					getchar();
					io.printAllPages();
					io.displayMessage("Please enter the page's name: ");
					string name = io.getUserInput();
					FanPage* page = io.getPage(name);
					if (!page)
					{
						io.noSuchName();
						break;
					}
					cout << page->getName() << "'s fans are:" << endl;
					page->printFans();
					break;
				}
				break;
			}
			cout << endl;
		}
		 }while (action != 12);
		cout << "\033[32mBye Bye :)\033[0m";
	}
		_CrtDumpMemoryLeaks();
}