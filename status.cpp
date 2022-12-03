#include "Status.h"
using namespace std;

#define new MYDEBUG_NEW
#ifdef _DEBUG
#define MYDEBUG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define MYDEBUG_NEW new
#endif //_DEBUG

Status::Status(const char* t) // c'tor with text
{
	text = new char[strlen(t) + 1];
	strcpy(text, t);

	time_t curr_time;
	curr_time = time(NULL);
	char* tm = ctime(&curr_time);
	this->date_and_time = new char[strlen(tm) + 1];
	strcpy(date_and_time, tm);
}

Status::Status(char* t)
{
	text = new char[strlen(t) + 1];
	strcpy(text, t);

	time_t curr_time;
	curr_time = time(NULL);
	char* tm = ctime(&curr_time);
	this->date_and_time = new char[strlen(tm) + 1];
	strcpy(date_and_time, tm);
}

Status::~Status() //d'tor
{
	delete[]text;
	delete[]date_and_time;
}

void Status::printStatus()
{
	cout << "The status created at: " << date_and_time << "The status is: " << text << endl;
}

bool Status:: setText(const char* text)
{
	if (strlen(text) > LEN_OF_STATUS)
	return false;

	strcpy(this->text , text);
	return true;
}

