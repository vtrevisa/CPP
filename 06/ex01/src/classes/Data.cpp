/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:58:12 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/13 18:05:04 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Data.hpp"


//-----GETTERS-----
int Data::getIndex( void ) const
{
	return this->_index;
}

std::string Data::getName( void ) const
{
	return this->_name;
}

//-----SETTERS-----
void Data::setIndex( int index )
{
	this->_index = index;
}

void Data::setName( std::string name )
{
	this->_name = name;
}

//-----ORTODOX CANONICAL FORM-----
Data::Data( void ) : _index(0), _name("Default")
{
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data( int index, std::string name ) : _index(index), _name(name)
{
	std::cout << "Data parameterized constructor called" << std::endl;
}

Data::Data( Data const &copy )
{
	std::cout << "Data copy assignment operator called" << std::endl;
	*this = copy;
}

Data::~Data( void )
{
	std::cout << "Data default destructor called" << std::endl;
}

Data& Data::operator=( Data const &other )
{
	std::cout << "Data copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_index = other._index;
		this->_name = other._name;
	}
	return *this;
}

//-----OTHER OPERATORS-----
std::ostream &operator<<(std::ostream& os, Data const &data)
{

	os << GRAY << "***Data Informations***" << std::endl;
	std::cout << "Index: " << data.getIndex() << std::endl;
	std::cout << "Name: " << data.getName() << std::endl;
	return os;
}