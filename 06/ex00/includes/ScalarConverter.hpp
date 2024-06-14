/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:58:43 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/13 16:22:12 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits.h>
# include <cstdlib>
# include <string>
# include <cmath>
# include <cctype>
# include <cerrno>
# include <iomanip>

// Color codes as global variables
const std::string RESET = "\033[0m";
const std::string RED = "\033[31;1m";
const std::string GREEN = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE = "\033[34;1m";
const std::string PURPLE = "\033[35;1m";
const std::string CYAN = "\033[36;1m";
const std::string GRAY = "\033[37;1m";

//-----TYPES-----
enum types
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PFLOAT,
	PSEUDO,
	INVALID
};

class ScalarConverter
{
private:

//-----ORTODOX CANONICAL FORM-----
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter();
	ScalarConverter& operator = (const ScalarConverter &other);
	
public:
//-----FUNCTIONS-----
	static void	convert(const std::string str);
};

//-----UTILS-----
int	getType(std::string str);
typedef bool (*findTypes)( const std::string str );
bool	isChar(std::string str);
bool	isInt(std::string str);
bool	isFloat(std::string str);
bool	isDouble(std::string str);
bool	isPseudoLiteral(std::string str);
void	setChar(std::string str);
void	setInt(std::string str);
void	setFloat(std::string str);
void	setDouble(std::string str);
void	printPseudoLiteral(std::string str);
void	printAll(char c, int i, float f, double d, int error);

#endif // SCALARCONVERTER_HPP