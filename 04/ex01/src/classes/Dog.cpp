/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:51:21 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 17:15:08 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "DOG default constructor called!" << std::endl;
	_brain = new Brain;
	_type =  "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "DOG copy constructor called!" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "DOG destructor called!" << std::endl;
}

Dog&	Dog::operator = (const Dog &other)
{
	std::cout << "DOG assingment operator overload called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "야옹 야옹 (Yaong Yaong)" << std::endl;
}

std::string Dog::getIdea(int N)
{
	return _brain->getIdea(N);
}
