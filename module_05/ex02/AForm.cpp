#include "AForm.hpp"
#include "Bureaucrat.hpp"


const char* AForm::GradeTooHighException::what() const throw()
{
	return "Error: form grade too high (minimum is 1)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Error: form grade too low (maximum is 150)";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Error: form is not signed";
}

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	std::cout << "Form " << _name <<  " constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _signed(other._signed),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form " << _name <<  " copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		std::cout << "Form " << other._name <<  " copy constructor called" << std::endl;
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Form " << _name << " destructor called" << std::endl;
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::checkExecution(Bureaucrat const &executor) const
{
	if (!_signed)
		throw NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();

}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form name:          " << f.getName()                            << std::endl;
    os << "Signed:             " << (f.getSigned() ? "yes" : "no")        << std::endl;
    os << "Grade to sign:      " << f.getGradeToSign()                    << std::endl;
    os << "Grade to execute:   " << f.getGradeToExecute()                 << std::endl;

    return os;
}
