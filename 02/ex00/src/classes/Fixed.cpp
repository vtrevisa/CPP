/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:31:13 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/03 13:25:15 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Fixed.hpp"
#include <ostream>

Fixed::Fixed() : _fixed_value(0)
{
	std::cout << "Default constructior called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator overload called" << std::endl;
	if (this != &other)
		_fixed_value = other.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_value;
}

void	Fixed::setRawBits(int const fixed)
{
	this->_fixed_value = fixed;
}