/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:29:11 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/08 15:35:30 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
//-----FUNCTIONS-----
AForm* makeForm(std::string name, std::string target);

//-----EXCEPTIONS-----
class FormDoesNotExistException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

//-----ORTHODOX CANONICAL FORM-----
	Intern();
	Intern(const Intern& copy);
	~Intern();
	Intern& operator = (const Intern& other);
};

#endif