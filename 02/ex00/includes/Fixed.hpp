/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:31:17 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/30 09:32:53 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
	
	int					_fixed_value;
	static const int	_fract_bit = 8;

	public:

	int					getRawBits(void) const ;
	void				setRawBits(int const raw);

	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator = (const Fixed &fixed);
	~Fixed();
};

#endif