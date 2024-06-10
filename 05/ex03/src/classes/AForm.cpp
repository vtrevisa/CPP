/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:41:48 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 10:42:29 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/AForm.hpp"
#include "../../includes/Bureaucrat.hpp"

//-----ORTHODOR CANONICAL AFORM-----

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signedStatus(false)
{
	std::cout << "AForm default constructor called!" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy)
: _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << "AForm copy constructor called!" << std::endl;
	*this = copy;
}

AForm& AForm::operator = (const AForm& other)
{
	std::cout << "AForm copy assignment overload called!" << std::endl;
	if (this != &other)
	{
		_signedStatus = other._signedStatus;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm default destructor called!" << std::endl;
}

//-----EXCEPTIONS-----
const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm not signed!";
}

//-----GETTERS-----

std::string	AForm::getName() const
{
	return _name;
}

int			AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

int			AForm::getGradeToSign() const
{
	return _gradeToSign;
}

bool		AForm::getSignedStatus() const
{
	return _signedStatus;
}

//-----FUNCTIONS-----
void		AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signedStatus = true;
}

void		AForm::execute(const Bureaucrat& b) const
{
	if (!getSignedStatus())
		throw FormNotSignedException();
	if (b.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
}

//-----OUT OF CLASS-----
std::ostream& operator << (std::ostream& os, const AForm& f)
{
	os	<< "AForm " << f.getName()
		<< ", signed: " << (f.getSignedStatus() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute()
		<< std::endl;
	return os;
}