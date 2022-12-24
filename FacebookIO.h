#ifndef FACEBOOK_IO_H
#define FACEBOOK_IO_H

#include <string>
#include"Admin.h"
#include"FanPage.h"
#include"member.h"

//class Member;
//class FanPage;

class FacebookIO 
{
private:
    Admin* admin;
public:
    FacebookIO(Admin* admin) { this->admin = admin; }
    void displayMessage(const std::string& message) const;
    void wellcome();
    void printMenu();
    void nameAlreadyTaken()     { std::cout << "\033[1;31mName already taken, please enter another name\033[0m" << std::endl;}
    void noSuchName()           { std::cout << "\033[1;31mThis name is not in the system!\033[0m" << std::endl;}
    void InvalidAction()        { std::cout << "\033[1;31mInvalid Action!\033[0m" << std::endl;}
    void success()              { std::cout << "\033[32m Action succeeded :)\033[0m " << std::endl; }
    std::string getUserInput();
    Member getDetailsForMember();
    FanPage getDetailsForPage();
    Status getStatusFromUser();
    int selectMemberOrPage();
    Member* getMember(const std::string name);
    FanPage* getPage(const std::string name);
    void printAllMembers() const;
    void printAllPages() const;
    void printAllMemberStatuses(const Member& member) const;
    void printAllPageStatuses(const FanPage& page) const;
};

#endif


