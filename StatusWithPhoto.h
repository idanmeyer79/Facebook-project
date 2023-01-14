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
	/**

	@brief Copy constructor for StatusWithPhoto objects.
	@param other The StatusWithPhoto object to be copied.
	*/
	StatusWithPhoto(const StatusWithPhoto& other);
	/**

	@brief Constructs a StatusWithPhoto object by loading data from a file.
	@param file The input file stream to read the data from.
	*/
	StatusWithPhoto(std::ifstream& file);
	/**

	@brief Destructor for StatusWithPhoto objects.
	*/
	virtual ~StatusWithPhoto() {}
	/**

	@brief Constructs a StatusWithPhoto object with the given text and color.
	@param text The text of the status.
	@param color The color of the status.
	*/
	StatusWithPhoto(std::string text, std::string color);
	/**

	@brief Prints the text and color of the status to the console.
	*/
	virtual void printStatus() const override;
	/**

	@brief Overloads the << operator for outputting StatusWithPhoto objects.
	@param out The output stream.
	@param status The StatusWithPhoto object to be outputted.
	@return The output stream.
	*/
	friend std::ostream& operator<< (std::ostream& out, const StatusWithPhoto& status);
	/**

	@brief Saves the StatusWithPhoto object to a file.
	@param outFile The output file stream to save the StatusWithPhoto object to.
	*/
	virtual void saveToFile(std::ofstream& outFile) const override;
};

#endif //!__STASUS_WITH_PHOTO_H__
