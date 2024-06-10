/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:51:33 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 17:15:08 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "CAT default constructor called!" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "CAT copy constructor called!" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "CAT destructor called!" << std::endl;
}

Cat&	Cat::operator = (const Cat &other)
{
	std::cout << "CAT assingment operator overload called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "멍 멍 (meong meong)" << std::endl;
}