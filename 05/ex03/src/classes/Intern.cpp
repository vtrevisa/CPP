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

# include "../../includes/Intern.hpp"

//-----ORTHODOX CANONICAL FORM-----
Intern::Intern()
{
	std::cout << "Intern default constructor called!" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	std::cout << "Intern copy constructor called!" << std::endl;
	*this = copy;
}

Intern& Intern::operator = (const Intern& other)
{
	std::cout << "Intern copy assignment overload called!" << std::endl;
	if (this != &other){}
	return *this;
}
Intern::~Intern()
{
	std::cout << "Intern default destructor called!" << std::endl;
}

//-----EXCEPTION-----
const char* Intern::FormDoesNotExistException::what() const throw()
{
	return "Form does not exist!";
}

//----- FUNCTIONS -----
AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"shrubbery creation",
							"robotomy request",
							"presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			switch (i)
			{
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	throw Intern::FormDoesNotExistException();
	return NULL;
}
