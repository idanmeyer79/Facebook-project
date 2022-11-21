#ifndef __PAGE_H__
#define __PAGE_H__
#include"member.h"
#include"status.h"


class FanPage
{
private:
	char* name;
	Member** fans = nullptr;
	status** statuses = nullptr;
	int numOfStatuses = 0;
	int numOfFans = 0;


public:
	FanPage(char* name);
	bool setName(char* name);
	char* getName() { return name; }
	void addFan(Member* fan);
	void printFans();
	void removeFan(Member* fan);
	void printAllStatuses();
	void addStatus(char* text);


};

#endif // !__PAGE_H__



