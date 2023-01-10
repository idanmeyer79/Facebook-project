#ifndef __STASUS_WITH_VIDEO_H__
#define __STASUS_WITH_VIDEO_H__
#include <iostream>
#pragma warning(disable: 4996)
#include "status.h"

class StatusWithVideo : public Status
{
private:
	std::string statusColor;
public:
	StatusWithVideo(std::string text, std::string color);
	virtual void printStatus() const override;
	friend std::ostream& operator<< (std::ostream& out, const StatusWithVideo& status);


};

#endif //!__STASUS_WITH_VIDEO_H__