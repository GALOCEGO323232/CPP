#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string _name
		bool		_signed
		const int  _gradeToSign
		const int  _gradeToExecute
	
	public:

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		Form();
		Form(cosnt std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getName() const;
		bool			   getSigned() const;
		int				   getGradeToSign() const;
		int				   getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
}

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif