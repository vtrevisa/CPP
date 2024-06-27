/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:33:41 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/17 17:11:38 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
private:
	T*				_elements;
	unsigned int	_size;

public:
//-----ORTHODOX CANONICAL FORM-----
	Array();
	Array(unsigned int n);
	Array (const Array &copy);
	Array& operator = (const Array &other);
	~Array();

//-----OTHER OPERATORS-----
	T& operator[](unsigned int index) const;

//-----FUNCTIONS-----
	unsigned int size() const;
};

#include "../src/classes/Array.tpp"

#endif //ARRAY_HPP