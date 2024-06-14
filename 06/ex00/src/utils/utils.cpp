/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:51:10 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/13 13:51:48 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ScalarConverter.hpp"

//-----UTILS-----
int	getType(std::string str)
{
	if (str.empty())
		return INVALID;
	findTypes checkTypes[5] = {	&isChar,
								&isInt,
								&isFloat,
								&isDouble,
								&isPseudoLiteral};
	for (int i = 0; i < 5; i++)
	{
		if (checkTypes[i](str))
			return types(i);
	}
	return INVALID;
}

bool isChar(const std::string str)
{
	if (str.length() == 1 && str.at(0) > 31 && str.at(0) < 127)
		return true;
	return false;
}

bool isInt(const std::string str)
{
	char	*endptr;
	int		value = static_cast<int>(std::strtol(str.c_str(), &endptr, 10));
	if ((value == 0 && errno != 0) || endptr == str.c_str())
		return false;
	if (str.find('.') == std::string::npos && *endptr == 0)
		return true;
	return false;
}

bool isFloat(const std::string str)
{
	char	*endptr;
	double	value = std::strtof(str.c_str(), &endptr);

	if ((errno != 0 && value == 0) || endptr == str.c_str())
		return false;
	if (str.find('.') != std::string::npos && *endptr == 'f' && *(endptr + 1) == 0)
		return true;
	return false;
}

bool isDouble(std::string str)
{
	char* endptr;

	double value = std::strtod(str.c_str(), &endptr);

	if ((errno != 0 && value == 0) || endptr == str.c_str())
		return false;
	if (str.find('.') != std::string::npos && *endptr == '\0')
		return true;
	return false;
}

bool isPseudoLiteral(std::string str)
{
	std::string pseudoLiterals[6] = { "-inff", "+inff", "-inf", "+inf", "nan", "nanf" };

	for (int i = 0; i < 6; ++i)
	{
		if (pseudoLiterals[i] == str)
			return true;
	}
	return false;
}

void setChar(std::string str)
{
	int	c;
	int	error = 0;

	if (str.length() == 1 && str[0] >='0' && str[0] <= '9')
		c = str[0] - 48;
	else
		c = static_cast<char>(str[0]);
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	if (str.length() == 1 && str[0] >='0' && str[0] <= '9')
		c -= 49;

	printAll(c, i, f, d, error);
}

void setInt(std::string str)
{
	char*	ptr;
	int		error = 0;

	long int l = std::strtol(str.c_str(), &ptr, 10);
	int i = static_cast<int>(l);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if (l > INT_MAX || l < INT_MIN)
		error = 2;

	printAll(c, i, f, d, error);
}

void setFloat(std::string str)
{
	char*	ptr;
	int		error = 0;

	float f = std::strtof(str.c_str(), &ptr);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
		error = 1;

	printAll(c, i, f, d, error);
}

void setDouble(std::string str)
{
	char*	ptr;
	int		error = 0;

	double d = std::strtod(str.c_str(), &ptr);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (d > INT_MAX || d < INT_MIN)
		error = 1;
	printAll(c, i, f, d, error);
}

void printPseudoLiteral(std::string str)
{
	std::cout << BLUE << " char: ";
	std::cout << RED << "impossible";
	std::cout << RESET << std::endl;

	std::cout << GREEN << " int: ";
	std::cout << RED << "impossible";
	std::cout << RESET << std::endl;

	std::cout << CYAN << " float: ";
	std::cout << str;
	if (str == "nan" || str == "+inf" || str == "-inf")
		std::cout << "f";
	std::cout << RESET << std::endl;

	std::cout << PURPLE << " double: ";
	if (str == "nanf" || str == "+inff" || str == "-inff")
		str.erase(str.length() - 1);
	std::cout << str;
	std::cout << RESET << std::endl;
}

void printAll(char c, int i, float f, double d, int error)
{
	std::cout << BLUE << "char: ";
	if (i < CHAR_MIN || i > CHAR_MAX)
		std::cout << RED << "impossible";
	else if (!isprint(c))
		std::cout << RED << "Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << RESET << std::endl;

	std::cout << GREEN << "int: ";
	if (error)
		std::cout << RED << "impossible";
	else
		std::cout << i;
	std::cout << RESET << std::endl;

	std::cout << CYAN << "float: ";
	if (error == 2)
		std::cout << RED << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	std::cout << RESET << std::endl;

	std::cout << PURPLE << "double: ";
	if (error == 2)
		std::cout << RED << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << d;
	std::cout << RESET << std::endl;
}
