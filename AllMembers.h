#ifndef __AllMembers__
#define __AllMembers__

#include"Member.h"

class AllMembers
{
private:
	Member** allMembers;
	int numOfMembers = 0;

public:
	void addMember(Member& p);
	void printAllMembers();

};


#endif // !__AllMembers_H__

