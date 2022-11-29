#include <iostream>
#include"Admin.h"
#pragma warning(disable: 4996)
using namespace std;

int main()
{
	Admin admin;

	Status status1((char*)"Hey its Boaz");
	Status status2((char*)"Boaz 2");
	Status status3((char*)"Hey its Romina");
	Status status4((char*)"Romina 2");
	Status status5((char*)"Hey its Arie");
	Status status6((char*)" Arie 2");
	Status status7((char*)"welcome to Mondial 2022");
	Status status8((char*)"Mondial 2022 2");
	Status status9((char*)"welcome to re'evim beravcha");
	Status status10((char*)"re'evim beravcha 2");
	Status status11((char*)"welcome to keren kalif fans");
	Status status12((char*)"keren kalif fans 2");

	Member member1((char*)"Boaz", Date(1, 1, 2000));
	Member member2((char*)"Romina", Date(2, 2, 2000));
	Member member3((char*)"Arie", Date(3, 3, 2000));

	FanPage fanPage1((char*)"M");
	FanPage fanPage2((char*)"re'evim beravcha");
	FanPage fanPage3((char*)"keren kalif fans");

	admin.users.addMember(&member1);
	admin.users.addMember(&member2);
	admin.users.addMember(&member3);
	admin.fanPages.addPage(&fanPage1);
	admin.fanPages.addPage(&fanPage2);
	admin.fanPages.addPage(&fanPage3);

	member1.addStatus(status1);
	member1.addStatus(status2);
	member2.addStatus(status3);
	member2.addStatus(status4);
	member3.addStatus(status5);
	member3.addStatus(status6);
	fanPage1.addStatus(status7);
	fanPage1.addStatus(status8);
	fanPage2.addStatus(status9);
	fanPage2.addStatus(status10);
	fanPage3.addStatus(status11);
	fanPage3.addStatus(status12);

	admin.makeFriendship(member1, member2);
	/*admin.getusers().addMember(&member2);
	admin.getusers().addMember(&member3);
    admin.getFanPages().addPage(&fanPage1);
	admin.getFanPages().addPage(&fanPage2);
	admin.getFanPages().addPage(&fanPage3);*/

	admin.menu();
}
