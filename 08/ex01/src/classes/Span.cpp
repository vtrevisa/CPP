/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:23:09 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/19 17:34:07 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Span.hpp"

//-----SETTERS-----
void	Span::addNumber(int number)
{
	if (_vector.size() >= _size)
	 	throw FullSpanException();
	_vector.push_back(number);
}

void	Span::addMany(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vector.size() + std::distance(begin, end) > _size)
		throw FullSpanException();
	_vector.insert(_vector.begin(), begin, end);
}

//-----FUNCTIONS-----

int	Span::shortestSpan()
{
	if (this->_vector.empty() || this->_vector.size() == 1)
		throw NoSpanException();
	std::vector<int> sortedVector = _vector;
	std::sort(sortedVector.begin(), sortedVector.end());
	int	minDistance = std::abs(*_vector.begin() - *(_vector.end() - 1));
	for (size_t i = 1; i < sortedVector.size(); i++) 
	{
		int distance = std::abs(sortedVector[i] - sortedVector[i - 1]);
		if (distance < minDistance)
			minDistance = distance;
	}
	return minDistance;
}

int	Span::longestSpan()
{
	if (this->_vector.empty() || this->_vector.size() == 1)
		throw NoSpanException();
	return (*std::max_element(_vector.begin(), _vector.end())
					- *std::min_element(_vector.begin(), _vector.end()));
}

//-----EXCEPTIONS-----
const char *Span::FullSpanException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "empty or single element Span";
}

//-----ORTHODOX CANONICAL FORM-----
Span::Span(unsigned int n) : _size(n)
{
	#ifdef DEBUG
		std::cout << "Parameterized constructor called" << std::endl;
	#endif
	_vector.reserve(_size);
}

Span::Span(const Span &copy)
{
	#ifdef DEBUG
		std::cout << "Copy constructor called" << std::endl;
	#endif
	*this = copy;
}

Span& Span::operator = (const Span &other)
{
	#ifdef DEBUG
		std::cout << "Assignment operator overload called" << std::endl;
	#endif
	if (this != &other)
	{
		_size = other._size;
		_vector = other._vector;
	}
	return *this;
}

Span::~Span()
{
	#ifdef DEBUG
		std::cout << "Default Destructor called" << std::endl;
	#endif
}