#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw();
{
	return "Error: grid too high (minimum and 1)"
}

const char* Bureaucrat::GradeTooLowGrade::what() const throw();
{
	return "Error: grid too low (maximum is 150)"
}


Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << name << " constructor called" << std::endl
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	_name = other._name;
	_grade = other._grade;
	std::cout << "Bureaucrat "<< other._name << " copy constructor called" << std::endl
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		std::cout << "Bureaucrat "<< other._name << " operator constructor called" << std::endl
		_name = other._name;
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destructor called" << std::endl
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowExpection();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat with classification " << b.getGrade();
    return os;
}


