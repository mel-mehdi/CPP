#include "PhoneBook.hpp"
#include <iostream>

int main(){
    PhoneBook book;
    std::string command;
    std::cout << "Welcome to My Awesome PhoneBook!\n\nAvailable commands:\nADD    = Add a new contact\nSEARCH = Search for a contact\nEXIT   = Exit the program\n\n";
    while (true) {
        std::cout << "Enter command: ";

        if (!std::getline(std::cin, command)) {
            std::cout << "\n";
            break;
        }
        else if (command == "EXIT")
            break;
        else if (command == "ADD")
            book.addContact();
        else if (command == "SEARCH")
            book.searchContact();
        else
            std::cout << "Invalid command. Please try again.\n";
    }
    std::cout << "Goodbye!\n";
    return 0;
}