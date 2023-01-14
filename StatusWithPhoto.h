#ifndef __STASUS_WITH_PHOTO_H__
#define __STASUS_WITH_PHOTO_H__
#include <iostream>
#include <fstream>
#pragma warning(disable: 4996)
#include "status.h"

class StatusWithPhoto : public Status
{
private:
	std::string statusColor;
public:
	StatusWithPhoto(std::ifstream& file);
	virtual ~StatusWithPhoto() {}
	StatusWithPhoto(std::string text,std::string color);
	virtual void printStatus() const override;
	friend std::ostream& operator<< (std::ostream& out, const StatusWithPhoto& status);
	virtual void saveToFile(std::ofstream& outFile) const override;



};

#endif //!__STASUS_WITH_PHOTO_H__
