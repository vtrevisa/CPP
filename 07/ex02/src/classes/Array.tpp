/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:45:14 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/24 14:16:28 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Array.hpp"
#define DEBUG

// Default constructor: Creates an empty array
template <typename T>
Array<T>::Array() : _elements(new T[0]), _size(0)
{
	#ifdef DEBUG
	std::cout << "Default constructor called" << std::endl;
	#endif
}

// Constructor with an unsigned int n as a parameter: Creates an array of n _elements
// initialized by default
template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n)
{
	#ifdef DEBUG
	std::cout << "Parameterized constructor called" << std::endl;
	#endif
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other) : _elements(new T[other._size]), _size(other._size)
{
	#ifdef DEBUG
	std::cout << "Copy constructor called" << std::endl;
	#endif
	for (unsigned int i = 0; i < _size; ++i) {
		_elements[i] = other._elements[i];
	}
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator = (const Array& other)
{
	#ifdef DEBUG
	std::cout << "Assignment operator overload called" << std::endl;
	#endif
	if (this != &other)
	{
		if (this)
			delete[] _elements;
		_size = other._size;
		_elements = new T[other._size];
		for (unsigned int i = 0; i < _size; ++i) {
			_elements[i] = other._elements[i];
		}
	}
	return *this;
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	#ifdef DEBUG
	std::cout << "Default destructor called" << std::endl;
	#endif
	delete[] _elements;
}

// Const subscript operator for accessing _elements
template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size || index < 0)
		throw std::out_of_range("Index out of bounds");
	return _elements[index];
}

// Member function size() that returns the number of _elements in the array
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}