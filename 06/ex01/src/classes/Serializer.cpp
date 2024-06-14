/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:49:11 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/13 18:01:05 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Serializer.hpp"

//-----ORTODOX CANONICAL FORM-----
Serializer::Serializer()
{
	std::cout << "Serializer constructor called!" << std::endl;
}
Serializer::Serializer(const Serializer &copy)
{
	std::cout << "Serializer copy constructor called!" << std::endl;
	*this = copy;
}
Serializer::~Serializer()
{
	std::cout << "Serializer destructor called!" << std::endl;	
}
Serializer& Serializer::operator = (const Serializer &other)
{
	std::cout << "Serializer assignment operator overload called!" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

//-----FUNCIONS-----
uintptr_t Serializer::serialize(Data* ptr)
{
	std::cout << GREEN << "Serializing data..." << RESET << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	std::cout << YELLOW << "Deserializing data..." << RESET << std::endl;
	return reinterpret_cast<Data*>(raw);
}