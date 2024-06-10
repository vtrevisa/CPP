/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:51:17 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 17:15:08 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "ANIMAL default constructor called!" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "ANIMAL default constructor called and animal named!" << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << "ANIMAL copy constructor called!" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "ANIMAL destructor called!" << std::endl;
}

Animal&	Animal::operator = (const Animal &other)
{
	std::cout << "ANIMAL operator overload called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

std::string Animal::getType()
{
	return _type;
}

void	Animal::setType(std::string type)
{
	_type = type;
}

void	Animal::makeSound() const
{
	std::cout << "Grrrrrr... (generic animal sound)" << std::endl;
}

