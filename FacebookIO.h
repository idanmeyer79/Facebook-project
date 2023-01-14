#ifndef FACEBOOK_IO_H
#define FACEBOOK_IO_H

#include <string>
#include"Admin.h"
#include"FanPage.h"
#include"member.h"

class FacebookIO 
{
private:
    Admin* admin;
public:
    static constexpr int MAX_LEN_OF_NAME = 20;
    FacebookIO(Admin* admin)    { this->admin = admin; }
    void nameAlreadyTaken()     { std::cout << "\033[1;31mName already taken, please enter another name\033[0m" << std::endl;}
    void noSuchName()           { std::cout << "\033[1;31mThis name is not in the system!\033[0m" << std::endl;}
    void InvalidAction()        { std::cout << "\033[1;31mInvalid Action!\033[0m" << std::endl;}
    void success()              { std::cout << "\033[32mAction succeeded :)\033[0m " << std::endl; }
    /**
     * Prompts the user for input and returns the input as a string.
     *
     * @return The user's input.
     */
    std::string getUserInput();

    /**
     * Displays the given message to the user.
     *
     * @param message The message to display.
     */
    void displayMessage(const std::string& message) const;

    /**
     * Displays a wellcome message to the user.
     */
    void wellcome();

    /**
     * Prints the main menu options to the user.
     */
    void printMenu();

    /**
     * Prompts the user for the details of a new member, and returns a `Member` object with the entered details.
     *
     * @return The new member.
     */
    Member getDetailsForMember();

    /**
     * Prompts the user for the details of a new fan page, and returns a `FanPage` object with the entered details.
     *
     * @return The new fan page.
     */
    FanPage getDetailsForPage();

    /**
     * Prompts the user for a new status and returns it as a `Status` object.
     *
     * @return The new status.
     */
    Status* getStatusFromUser();

    /**
     * Prompts the user to select a member or a fan page, and returns their selection as an integer.
     *
     * @return `1` if the user selected a member, `2` if the user selected a fan page.
     */
    int selectMemberOrPage();

    /**
     * Returns a pointer to the member with the given name, if it exists.
     *
     * @param name The name of the member to find.
     * @return A pointer to the member with the given name, or `nullptr` if no such member exists.
     */
    Member* getMember(const std::string name);

    /**
     * Returns a pointer to the fan page with the given name, if it exists.
     *
     * @param name The name of the fan page to find.
     * @return A pointer to the fan page with the given name, or `nullptr` if no such fan page exists.
     */
    FanPage* getPage(const std::string name);

    /**
     * Prints the names of all members in the list of members.
     */
    void printAllMembers() const;

    /**
     * Prints the names of all fan pages in the list of fan pages.
     */
    void printAllPages() const;

    /**
     * Prints the statuses of the given member.
     *
     * @param member The member to print the statuses of.
     */
    void printAllMemberStatuses(const Member& member) const;

    /**
     * Prints the statuses of the given fan page.
     *
     * @param page The fan page to print the statuses of.
     */
    void printAllPageStatuses(const FanPage& page) const;
    
    /**
     * Generates and returns a new name for a Member object.
     * @return A string representing the new name for the Member object.
     */
    std::string getNewNameForNewMember()noexcept(false);

    /**
     * Generates and returns a new name for a FanPage object.
     * @return A string representing the new name for the FanPage object.
     */
    std::string getNewNameForNewFanPage()noexcept(false);

    /**
     * Asks the user to choose a Member object from a list of Member objects.
     * @return A pointer to the chosen Member object.
     */
    Member* chooseMemberFromList()noexcept(false);

    /**
     * Asks the user to choose a FanPage object from a list of FanPage objects.
     * @return A pointer to the chosen FanPage object.
     */
    FanPage* chooseFanPageFromList() noexcept(false);

    /**
     * Returns a Member object and handle any exaptions in the proccess.
     * @return A pointer to the exception Member object.
     */
    Member* getMemberException();

    /**
     * Returns a FanPage object and handle any exaptions in the proccess.
     * @return A pointer to the exception FanPage object.
     */
    FanPage* getPageException();

    int selectTypeOfStatus();
};
#endif


