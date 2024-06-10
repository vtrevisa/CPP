/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:58:59 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 13:00:22 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCAT default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCAT copy constructor called!" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCAT destructor called!" << std::endl;
}

WrongCat&	WrongCat::operator = (const WrongCat &other)
{
	std::cout << "WrongCAT assingment operator overload called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Mimimimimi mimi mimi" << std::endl;
}