#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

std::string PhoneBook::getValidInput(const std::string& fieldName) const {
    std::string input;
    while (true) {
        std::cout << "Enter " << fieldName << ": ";
        if (!std::getline(std::cin, input) || std::cin.eof()) {
            std::cout << "\nError: Invalid input\n";
            return "";
        }
        // Skip special character sequences (like arrow keys)
        if (input.empty() || input[0] == '\033') {
            continue;
        }
        if (input.empty()) {
            std::cout << "Error: Field cannot be empty\n";
            continue;
        }
        return input;
    }
}

void PhoneBook::addContact() {
    Contact newContact;
    std::string fields[] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
    std::string inputs[5];
    
    for (int i = 0; i < 5; i++) {
        inputs[i] = getValidInput(fields[i]);
        if (inputs[i].empty())
            return;
    }

    newContact.setFirstName(inputs[0]);
    newContact.setLastName(inputs[1]);
    newContact.setNickname(inputs[2]);
    newContact.setPhone(inputs[3]);
    newContact.setSecret(inputs[4]);

    contacts[current_index] = newContact;
    current_index = (current_index + 1) % 8;
    if (total_contacts < 8)
        total_contacts++;

    std::cout << "Contact added successfully!\n";
}

void PhoneBook::searchContact() {
    if (total_contacts == 0) {
        std::cout << "Phonebook is empty!\n";
        return;
    }

    displayContactList();
    std::string input;
    std::cout << "Enter index to display: ";
    std::getline(std::cin, input);

    // Validate input is a single digit
    if (input.length() != 1 || !isdigit(input[0])) {
        std::cout << "Error: Invalid index\n";
        return;
    }

    int index = input[0] - '0';
    if (index < 0 || index >= total_contacts) {
        std::cout << "Error: Index out of range\n";
        return;
    }

    displayContact(index);
}

std::string truncateString(const std::string& str) {
    if (str.length() <= 10)
        return str;
    return str.substr(0, 9) + ".";
}

void PhoneBook::displayContactList()
{
    std::cout << "|--------------------------------------------|\n";
    std::cout << "|     Index|First Name| Last Name| Nickname  |\n";
    std::cout << "|--------------------------------------------|\n";

    for (int i = 0; i < total_contacts; i++) {
        std::cout << "|" << std::setw(10) << i << "|"
                  << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getNickname()) << " |\n";
    }
    std::cout << "|--------------------------------------------|\n";
}

void PhoneBook::displayContact(int index)  {
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhone() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getSecret() << std::endl;
}