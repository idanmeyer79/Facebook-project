#ifndef __PAGE_H__
#define __PAGE_H__
#include"member.h"
#include"status.h"
class FanPage
{
private:
	char* pageName;
	Member* fans;
	Status* statuses;
	int numOfStatuses = 0;
	int numOfFans = 0;


public:
	bool setName();
	char* getName() { return pageName; }
	void addFan(Member* fan);
	void printFans();
	void removeFan(Member* fan);
	void printAllStatuses();
	void addStatus(char* text);


};

#endif // !__PAGE_H__



