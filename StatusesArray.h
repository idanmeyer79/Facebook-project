#ifndef __StatusesArray__
#define __StatusesArray__
#include <iostream>
#include<vector>
#include"Status.h"
#pragma warning(disable: 4996)
#define new MYDEBUG_NEW
#ifdef _DEBUG 
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif // _DEBUG 
class StatusesArray
{
private:
	std::vector<Status*> statusArray;

public:
	~StatusesArray();
	void free();
	std::vector<Status*> getStatusArray() {return statusArray; 	}
	void addStatusToArray(Status& s);
	void printAllStatuses() const ;
	void print10() const ;
};

#endif // !__StatusesArray__

