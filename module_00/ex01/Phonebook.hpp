#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include "Includes.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int count;
		int index;
	
		std::string getInput(std::string prompt);
		void displayContactsTable();
		void askContactIndexAndDisplay();

	public:
		PhoneBook();
    	void addContact();
    	void searchContact();
};
