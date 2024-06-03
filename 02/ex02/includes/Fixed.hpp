/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:31:17 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/31 10:19:21 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>

class	Fixed
{
	private:
	
	int					_fixed_value;
	static const int	_fract_bit = 8;

	public:

	int					getRawBits(void) const ;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	
	Fixed(const int fixed);
	Fixed(const float fixed);

	Fixed				operator + (const Fixed &fixed);
	Fixed				operator - (const Fixed &fixed);
	Fixed				operator * (const Fixed &fixed);
	Fixed				operator / (const Fixed &fixed);

	Fixed&				operator ++ ();
	Fixed				operator ++ (int);
	Fixed&				operator -- ();
	Fixed				operator -- (int);

	bool				operator > (const Fixed &fixed) const;
	bool				operator < (const Fixed &fixed) const;
	bool				operator >= (const Fixed &fixed) const;
	bool				operator <= (const Fixed &fixed) const;
	bool				operator == (const Fixed &fixed) const;
	bool				operator != (const Fixed &fixed) const;

	static Fixed&		min(Fixed &fix1, Fixed &fix2);
	static const Fixed&	min(const Fixed &fix1, const Fixed &fix2);
	static Fixed&		max(Fixed &fix1, Fixed &fix2);
	static const Fixed&	max(const Fixed &fix1, const Fixed &fix2);

	Fixed();
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed&	operator = (const Fixed &fixed);
};

std::ostream&	operator<< (std::ostream& os, const Fixed& fixed);
#endif