/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:05:08 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/13 16:25:45 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ScalarConverter.hpp"

//-----FUNCTIONS-----
void ScalarConverter::convert(const std::string str)
{
	int	type;

	type = getType(str);
	void (*print[5])(std::string) = {	&setChar,
										&setInt,
										&setFloat,
										&setDouble,
										&printPseudoLiteral};
	if (type < 5)
		(print[type](str));
	else
	 std::cout << "Wrong paramenter" << std::endl;
}

//-----ORTODOX CANONICAL FORM-----
ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called!" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "Copy constructor called!" << std::endl;
	*this = copy;
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "Default destructor called!" << std::endl;	
}
ScalarConverter& ScalarConverter::operator = (const ScalarConverter &other)
{
	std::cout << "Assignment operator overload called!" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}
