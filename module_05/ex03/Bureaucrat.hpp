#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <expection>

class AForm;

class Bureaucrat
{
	private:
		int _grade;
		const std::string _name;

	public:


		class GradeTooHighException : public std::expection
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowExpection : public std::expection
		{
			public:
				const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other)
		~Bureaucrat();

		const std::string getName() const;
		int				  getGrade() const;


		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form);
		void executeForm(AForm const & form);


};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif