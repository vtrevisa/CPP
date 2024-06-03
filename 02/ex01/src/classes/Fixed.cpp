/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:31:13 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/03 13:40:27 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Fixed.hpp"


Fixed::Fixed() : _fixed_value(0)
{
	std::cout << "Default constructior called" << std::endl;
}

Fixed::Fixed(const int fixed)
{
	std::cout << "Int constructior called" << std::endl;
	_fixed_value = fixed * (1 << _fract_bit);
}

Fixed::Fixed(const float fixed)
{
	std::cout << "Float constructior called" << std::endl;
	_fixed_value = roundf(fixed *  (1 << _fract_bit));
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed&	Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator overload called" << std::endl;
	if (this != &fixed)
		_fixed_value = fixed.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const
{
	return _fixed_value;
}

void	Fixed::setRawBits(int const fixed)
{
	_fixed_value = fixed;
}

float	Fixed::toFloat() const
{
	return (float)_fixed_value / (1 << _fract_bit);
}

int	Fixed::toInt() const
{
	return _fixed_value >> _fract_bit;
}

std::ostream& operator << (std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}