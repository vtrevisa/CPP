/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:18:18 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/21 09:33:53 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MutantStack.hpp"

// Constructors
template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "Default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other)
{
	std::cout << "Copy constructor called" << std::endl;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &other)
{
	std::cout << "Assignment operator overload called" << std::endl;

	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Default destructor called" << std::endl;

}

// Member function definitions
template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template<typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template<typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const
{
	return this->c.rend();
}
