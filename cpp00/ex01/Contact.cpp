#include "Contact.hpp"

void Contact::setFirstName(std::string &name){first_name = name;}
void Contact::setLastName(std::string &name){last_name = name;}
void Contact::setNickname(std::string &nick){nickname = nick;}
void Contact::setPhone(std::string &phone){phone_number = phone;}
void Contact::setSecret(std::string &secret){darkest_secret = secret;}
std::string Contact::getFirstName(){return first_name;}
std::string Contact::getLastName(){return last_name;}
std::string Contact::getNickname(){return nickname;}
std::string Contact::getPhone(){return phone_number;}
std::string Contact::getSecret(){return darkest_secret;}