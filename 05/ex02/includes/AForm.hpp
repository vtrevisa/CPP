/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:54:46 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 18:44:10 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
private:

	std::string const	_name;
	int const			_gradeToSign;
	int const			_gradeToExecute;
	bool				_signedStatus;

public:
//-----GETTERS-----
	std::string			getName() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	bool				getSignedStatus() const;

//-----FUNCTIONS-----
	void				beSigned(const Bureaucrat& b);
	virtual void		execute(const Bureaucrat& b) const = 0;

//-----EXCEPTIONS-----
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
//-----CANONICAL-----
	AForm(const std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& copy);
	AForm& operator = (const AForm &other);
	virtual ~AForm();
};

std::ostream& operator << (std::ostream& os, const AForm& Aform);

#endif