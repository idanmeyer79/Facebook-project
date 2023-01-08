#ifndef __STASUS_WITH_PHOTO_H__
#define __STASUS_WITH_PHOTO_H__
#include <iostream>
#pragma warning(disable: 4996)
#include "status.h"

class StatusWithPhoto : public Status
{
private:
	std::string statusColor;
public:
	StatusWithPhoto(std::string text,std::string color);
	virtual void printStatus() const override;
};

#endif //!__STASUS_WITH_PHOTO_H__
