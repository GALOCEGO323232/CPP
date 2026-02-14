#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

# include "Contact.hpp"
# include "Includes.hpp"

class phonebook
{
	private:
		Contact contacts[8];
		int count;
		int index;

	public:
		PhoneBook();
    void addContact();
    void searchContact() const;
};

