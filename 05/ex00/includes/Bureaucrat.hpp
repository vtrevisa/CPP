/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:27:38 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 19:41:46 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:

	std::string const	_name;
	int					_grade;

public:

	//-----GETTERS-----
	std::string			getName() const;
	int					getGrade() const;

	//-----FUNCTIONS-----
	void				incrementGrade();
	void				decrementGrade();

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

	//-----ORTODOX CANONICAL FORM-----
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator = (const Bureaucrat& other);
	~Bureaucrat();
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& b);

// Reset
#define RESET           "\033[0m"

// Foreground Colors (256-color mode)
#define UNIQUE_RED      "\033[38;5;196m"
#define UNIQUE_GREEN    "\033[38;5;46m"
#define UNIQUE_YELLOW   "\033[38;5;226m"
#define UNIQUE_BLUE     "\033[38;5;21m"
#define UNIQUE_MAGENTA  "\033[38;5;201m"
#define UNIQUE_CYAN     "\033[38;5;51m"
#define UNIQUE_ORANGE   "\033[38;5;208m"
#define UNIQUE_PINK     "\033[38;5;200m"

// Background Colors (256-color mode)
#define BG_UNIQUE_RED      "\033[48;5;196m"
#define BG_UNIQUE_GREEN    "\033[48;5;46m"
#define BG_UNIQUE_YELLOW   "\033[48;5;226m"
#define BG_UNIQUE_BLUE     "\033[48;5;21m"
#define BG_UNIQUE_MAGENTA  "\033[48;5;201m"
#define BG_UNIQUE_CYAN     "\033[48;5;51m"
#define BG_UNIQUE_ORANGE   "\033[48;5;208m"
#define BG_UNIQUE_PINK     "\033[48;5;200m"

// Custom Colors for Test
#define HEADER_COLOR       UNIQUE_MAGENTA
#define SEPARATOR_COLOR    UNIQUE_CYAN
#define PASS_COLOR         UNIQUE_GREEN
#define FAIL_COLOR         UNIQUE_RED
#define EXCEPTION_COLOR    UNIQUE_YELLOW

#endif