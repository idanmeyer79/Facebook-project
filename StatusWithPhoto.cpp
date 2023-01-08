#include "StatusWithPhoto.h"
using namespace std;

StatusWithPhoto::StatusWithPhoto(string text, string color) :Status(text)
{
	statusColor = color;
}

void StatusWithPhoto::printStatus() const
{
	Status::printStatus();
	cout << "this is printed in " << statusColor << endl;
	system("start yosi.jpeg");
}
