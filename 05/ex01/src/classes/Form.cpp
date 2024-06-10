/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:41:48 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 10:42:29 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Form.hpp"
#include "../../includes/Bureaucrat.hpp"

//-----ORTHODOR CANONICAL FORM-----

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signedStatus(false)
{
	std::cout << "Form default constructor called!" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy)
: _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << "Form copy constructor called!" << std::endl;
	*this = copy;
}

Form& Form::operator = (const Form& other)
{
	std::cout << "Form copy assignment overload called!" << std::endl;
	if (this != &other)
	{
		_signedStatus = other._signedStatus;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form default destructor called!" << std::endl;
}

//-----EXCEPTIONS-----
const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

//-----GETTERS-----

std::string	Form::getName() const
{
	return _name;
}

int			Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

int			Form::getGradeToSign() const
{
	return _gradeToSign;
}

bool		Form::getSignedStatus() const
{
	return _signedStatus;
}

//-----FUNCTIONS-----
void		Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signedStatus = true;
}

//-----OUT OF CLASS-----
std::ostream& operator << (std::ostream& os, const Form& f)
{
	os	<< "Form " << f.getName()
		<< ", signed: " << (f.getSignedStatus() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return os;
}