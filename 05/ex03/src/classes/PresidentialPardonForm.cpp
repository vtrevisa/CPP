/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:18:35 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 22:13:17 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PresidentialPardonForm.hpp"

//-----ORTODOX CANONICAL FORM-----
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm ("Presidential Pardon", 25, 5)
{
	std::cout << "PPF default constructor called!" << std::endl;
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy)
{
	std::cout << "PPF copy constructor called!" << std::endl;
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (PresidentialPardonForm const &other)
{
	std::cout << "PPF copy assingment overload called!" << std::endl;
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PPF default destructor called!" << std::endl;///
}

//-----FUNCTIONS-----
void	PresidentialPardonForm::execute(Bureaucrat const &b) const
{
	try 
	{
		AForm::execute(b);
		std::cout	<< AForm::getName() << " has been executed targeting "
					<< _target << std::endl;
		std::cout	<< _target << " has been pardoned by Zaphod Beeblebrox."
					<< std::endl;
	}
	catch (std::exception& e)
	{
		std::cout	<< AForm::getName() << " has  not been executed because "
					<< e.what() << std::endl;
	}
	
}
