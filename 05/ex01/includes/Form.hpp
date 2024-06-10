/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:54:46 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 18:11:16 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
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
	
//-----CANONICAL-----
	Form(const std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form& copy);
	Form& operator = (const Form &other);
	~Form();
};

std::ostream& operator << (std::ostream& os, const Form& form);

#endif