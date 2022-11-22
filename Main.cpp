#include <iostream>
#include"AllPages.h"
#include "AllMembers.h"
#include "Date.h"
#include"Status.h"
#include "Page.h"
#include "Member.h"
#pragma warning(disable: 4996)
using namespace std;

Member& createMember();

int main()
{
	AllMembers allMembers;

	int action;

	do
	{
		cout << "Wellcome to facebook!" << endl;
		cout << "Please choose an action:" << endl;
		cout << "1 - create an acount" << endl;
		cout << "2 - create a fan page" << endl;
		cout << "3 - add status to a fan page/member" << endl;
		cout << "4 - show all fan page/member statuses" << endl;
		cout << "5 - show 10 new statuses" << endl;
		cout << "6 - add a friend" << endl;
		cout << "7 - delete friendship" << endl;
		cout << "8 - add fan page" << endl;
		cout << "9 - delete fan page" << endl;
		cout << "10 - show all acounts and fan pages" << endl;
		cout << "11 - show all friends/fans" << endl;
		cout << "12 - exit" << endl;
		cout << "_______________________" << endl;
		cin >> action;

		switch (action) {
		case 1:
			allMembers.addMember(createMember());
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:

			break;
		case 11:

			break;
		}

		allMembers.printAllMembers();

	} while (action != 12);
}

Member& createMember()
{
	Date date;
	int day, month, year;
	char slash_dummy;
	char* name = new char[20];

	cout << "Please enter a name - max 20 letters" << endl;
	cin >> name;
	cout << "Please enter date of birth - format dd/mm/yyyy" << endl;
	cin >> day >> slash_dummy >> month >> slash_dummy >> year;
	date.setDate(day, month, year);
	Member member(name, date);
	return member;
}
