#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int current_index;
		int total_contacts;
		std::string getValidInput(const std::string& fieldName) const;
	
	public:
		void addContact();
		void searchContact();
		void displayContactList();
		void displayContact(int index);
	};

#endif