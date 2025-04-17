#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    void setFirstName(std::string &name);
    void setLastName(std::string &name);
    void setNickname(std::string &nick);
    void setPhone(std::string &phone);
    void setSecret(std::string &secret);
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhone();
    std::string getSecret();
};

#endif