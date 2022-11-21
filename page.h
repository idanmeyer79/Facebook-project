#ifndef __PAGE_H__
#define __PAGE_H__
#include"member.h"
#include"status.h"
class page
{
private:
	char* name;
	Member* fans;
	status* statuses;
	int numOfStatuses = 0;
	int numOfFans = 0;


public:
	bool setName();
	char* getName() { return name; }
	void addFan(Member fan);
	void printFans();
	void removeFan(Member fan);
	void printAllStatuses();


};

#endif // !__PAGE_H__



