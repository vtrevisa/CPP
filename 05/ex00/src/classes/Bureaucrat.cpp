/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:41:48 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 19:41:39 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Bureaucrat.hpp"

//-----ORTHODOR CANONICAL FORM-----

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{
	std::cout << "Default constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Parameterized constructor called!" << std::endl;
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Copy constructor called!" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other)
{
	std::cout << "Copy assignment overload called!" << std::endl;
	if (this != &other)
	{
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default destructor called!" << std::endl;
}

//-----EXCEPTIONS-----
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade in too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade in too low!";
}

//-----GETTERS-----

std::string	Bureaucrat::getName() const
{
	return _name;
}

int			Bureaucrat::getGrade() const
{
	return _grade;
}

//-----FUNCTIONS-----
void		Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	--_grade;
}

void		Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	++_grade;
}

//-----OUT OF CLASS-----
std::ostream& operator << (std::ostream& os, const Bureaucrat& b)
{
	os	<< b.getName()
		<< ", bureaucrat grade "
		<< b.getGrade()
		<< std::endl;
	return os;
}