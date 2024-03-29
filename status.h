#ifndef __STATUS_H__
#define __STATUS_H__
#include <ctime>
#include<iostream>
#pragma warning(disable: 4996)

constexpr int SKIP_CLASS = 6;

class Status
{
protected:
	std::string text;
	std::string date_and_time;

public:
	static constexpr int MAX_LEN_OF_STATUS = 100;
	friend std::ostream& operator<< (std::ostream& out, const Status& status);
	Status(std::ifstream& file);

	/**
	 * Constructs a new status with the given text.
	 *
	 * @param text The text of the status.
	 */
	Status(const std::string text);

	/**
	 * Sets the text of the status.
	 *
	 * @param text The new text of the status.
	 * @return `true` if the text was set successfully, `false` otherwise.
	 */
	bool setText(const std::string text);

	/**
	 * Returns the text of the status.
	 *
	 * @return The text of the status.
	 */
	std::string getText() { return text; }

	/**
	 * Returns the date and time at which the status was created.
	 *
	 * @return The date and time at which the status was created.
	 */
	std::string getDateAndTime() { return date_and_time; }

	/**
	 * Shows the status.
	 */
	virtual void printStatus() const;

	/**
	 * Compares this status to another status based on their text.
	 *
	 * @param other The other status to compare to.
	 * @return `true` if the statuses have the same text, `false` otherwise.
	 */
	bool operator==(Status& other);

	/**
	 * Compares this status to another status based on their text.
	 *
	 * @param other The other status to compare to.
	 * @return `true` if the statuses have different text, `false` otherwise.
	 */
	bool operator!=(Status& other);

	/**
	@brief Saves the FanPage object to a file.
	@param outFile The output file stream to save the FanPage object to.
	*/
	virtual void saveToFile(std::ofstream& outFile) const;
};

#endif // !__STATUS_H__



