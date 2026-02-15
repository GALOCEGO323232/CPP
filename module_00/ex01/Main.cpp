#include "Phonebook.hpp"

void displayMenu()
{
    PhoneBook phoneBook;
    std::string input;
    while (input != "EXIT")
    {
        std::cout << "\n------------ PHONEBOOK MENU ------------" << std::endl; 
        std::cout << "Type one of the options below:\n" << std::endl;
        std::cout << "ADD: save a new contact." << std::endl;
        std::cout << "SEARCH:  display a specific contact." << std::endl;
        std::cout << "EXIT: ends the program." << std::endl;
    
        std::getline(std::cin, input);
    
        if (input == "ADD")
            phoneBook.addContact();
        else if (input == "SEARCH")
            phoneBook.searchContact();
        else if (input == "EXIT")
            break;
        else
            std::cout << "Command not fount, try again" << std::endl;
    }
}

int main(void)
{
  displayMenu();
  return (0);
}