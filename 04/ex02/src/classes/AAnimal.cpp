/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:51:17 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 15:30:17 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AANIMAL default constructor called!" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AANIMAL default constructor called and Aanimal named!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type)
{
	std::cout << "AANIMAL copy constructor called!" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << "AANIMAL destructor called!" << std::endl;
}

AAnimal&	AAnimal::operator = (const AAnimal &other)
{
	std::cout << "AANIMAL operator overload called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

std::string AAnimal::getType()
{
	return _type;
}

void	AAnimal::setType(std::string type)
{
	_type = type;
}
