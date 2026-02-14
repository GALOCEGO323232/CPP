#ifndef CONTACT_HPP
#define CONTACT_HPP

# include "Includes.hpp"

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		void setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret()	const;
		void  displayFull() const;
};

#endif
