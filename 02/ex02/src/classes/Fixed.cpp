/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:31:13 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/03 13:48:11 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Fixed.hpp"
#include <filesystem>


Fixed::Fixed() : _fixed_value(0)
{
	std::cout << "\nDefault constructor called" << std::endl;
}

Fixed::Fixed(const int fixed)
{
	std::cout << "\nInt constructor called" << std::endl;
	_fixed_value = fixed << _fract_bit;
}

Fixed::Fixed(const float fixed)
{
	std::cout << "\nFloat constructor called" << std::endl;
	_fixed_value = roundf(fixed * (1 << _fract_bit));
}

Fixed::~Fixed()
{
	std::cout << "\nDefault destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "\nCopy constructor called" << std::endl;
	*this = fixed;
}

Fixed&	Fixed::operator = (const Fixed &fixed)
{
	std::cout << "\nCopy assignment operator overload called" << std::endl;
	if (this != &fixed)
		this->_fixed_value = fixed.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const
{
	return this->_fixed_value;
}

void	Fixed::setRawBits(int const fixed)
{
	this->_fixed_value = fixed;
}

float	Fixed::toFloat() const
{
	return (float)_fixed_value / (1 << this->_fract_bit);
}

int	Fixed::toInt() const
{
	return (_fixed_value >> this->_fract_bit);
}

std::ostream& operator << (std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed	Fixed::operator + (const Fixed &fixed)
{
	Fixed ret;

	ret._fixed_value = this->getRawBits() + fixed.getRawBits();
	return ret;
}

Fixed	Fixed::operator - (const Fixed &fixed)
{
	Fixed ret;

	ret._fixed_value = this->getRawBits() - fixed.getRawBits();
	return ret;
}

Fixed	Fixed::operator * (const Fixed &fixed)
{
	Fixed ret;

	ret._fixed_value = (this->getRawBits() * fixed.getRawBits()) >> _fract_bit;
	return ret;
}

Fixed	Fixed::operator / (const Fixed &fixed)
{
	Fixed ret;

	if (fixed.getRawBits() == 0)
	{
		std::cout << "Error: Division b zero" << std::endl;
		return -1;
	}
	ret._fixed_value = (this->getRawBits() << _fract_bit) / fixed.getRawBits();
	return ret;
}

Fixed& Fixed::operator ++ ()
{
	++_fixed_value;
	return *this;
}

Fixed Fixed::operator ++ (int)
{
	Fixed temp(*this);

	++_fixed_value;
	return temp;
}

Fixed&	Fixed::operator -- ()
{
	--_fixed_value;
	return *this;
}

Fixed	Fixed::operator -- (int)
{
	Fixed temp(*this);

	--_fixed_value;
	return temp;
}

bool	Fixed::operator > (const Fixed &fixed) const
{
	return (this->_fixed_value > fixed._fixed_value);
}

bool	Fixed::operator < (const Fixed &fixed) const
{
	return (this->_fixed_value < fixed._fixed_value);
}

bool	Fixed::operator >= (const Fixed &fixed) const
{
	return (this->_fixed_value >= fixed._fixed_value);
}

bool	Fixed::operator <= (const Fixed &fixed) const
{
	return (this->_fixed_value <= fixed._fixed_value);
}

bool	Fixed::operator == (const Fixed &fixed) const
{
	return (this->_fixed_value == fixed._fixed_value);
}

bool	Fixed::operator != (const Fixed &fixed) const
{
	return (this->_fixed_value != fixed._fixed_value);
}

Fixed& Fixed::min (Fixed &fix1, Fixed &fix2)
{
	return fix1 < fix2 ? fix1 : fix2;
}

const Fixed& Fixed::min (const Fixed &fix1, const Fixed &fix2)
{
	return fix1 < fix2 ? fix1 : fix2;
}

Fixed& Fixed::max (Fixed &fix1, Fixed &fix2)
{
	return fix1 > fix2 ? fix1 : fix2;
}

const Fixed& Fixed::max (const Fixed &fix1, const Fixed &fix2)
{
	return fix1 > fix2 ? fix1 : fix2;
}