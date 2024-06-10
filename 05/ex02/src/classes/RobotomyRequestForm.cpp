/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:18:35 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 20:50:16 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RobotomyRequestForm.hpp"

//-----ORTODOX CANONICAL FORM-----
RobotomyRequestForm::RobotomyRequestForm(std::string target) :  AForm ("Robotomy Request", 72, 45)
{
	std::cout << "RRF default constructor called!" << std::endl;
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy)
{
	std::cout << "RRF copy constructor called!" << std::endl;
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (RobotomyRequestForm const &other)
{
	std::cout << "RRF copy assingment overload called!" << std::endl;
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RRF default destructor called!" << std::endl;///
}

//-----FUNCTIONS-----
void	RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	try 
	{
		AForm::execute(b);
		std::cout		<< AForm::getName() << " has been executed targeting "
						<< _target << std::endl;
		std::cout		<< "vrrrrrr...zhuuuuu...bzzzzzzz... (drilling noises)" 
						<< std::endl;
		if (rand() % 2 == 0)
			std::cout	<< _target << " has been robotomized successfully!"
						<< std::endl;
		else
			std::cout	<< "robotomy failed for " << _target
						<< std::endl;
	}
	catch (std::exception& e)
	{
		std::cout	<< AForm::getName() << " has  not been executed because "
					<< e.what() << std::endl;
	}
	
}
