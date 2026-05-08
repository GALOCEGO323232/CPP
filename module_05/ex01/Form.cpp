#include "Form.hpp"
#include "Bureaucrat.hpp"


const char* Form::GradeTooHighException::what() const throw()
{
	return "Error: form grade too high (minimum is 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Error: form grade too low (maximum is 150)";
}

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw gradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw gradeTooLowException();
	std::cout << "Form " << _name <<  " constructor called" << std::endl;
}

Form::Form(const Form& other)
{
	_name = other._name;
	_signed = other._signed;
	_gradeToSign = other._gradeToSign;
	_gradeToExecute = other._gradeToExecute;
	std::cout << "Form " << _name <<  " copy constructor called" << std::endl;
}

Form &Form::operator=(const Form& other)
{
	if (this != &other)
	{
		std::cout << "Form " << other._name <<  " copy constructor called" << std::endl;
		_name = other._name;
		_signed = other._signed;
		_gradeToSign = other._gradeToSign;
		_gradeToExecute = other._gradeToExecute;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << _name << " destructor called" << std::endl
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void beSigned(const Bureaucrat& bureaucrat)
{
	if (Bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form name:          " << f.getName()                            << std::endl;
    os << "Signed:             " << (f.getSigned() ? "yes" : "no")        << std::endl;
    os << "Grade to sign:      " << f.getGradeToSign()                    << std::endl;
    os << "Grade to execute:   " << f.getGradeToExecute()                 << std::endl;

    return os;
}

