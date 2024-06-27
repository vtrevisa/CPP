/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:08:40 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/19 17:02:33 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
private:

	unsigned int		_size;
	std::vector<int>	_vector;

public:
//-----SETTERS-----
void	addNumber(int number);
void	addMany(std::vector<int>::iterator begin, std::vector<int>::iterator end);

//-----FUNCTIONS------
int		shortestSpan();
int		longestSpan();

//-----EXCEPTIONS-----
class FullSpanException : public std::exception
{
	virtual const char* what() const throw();
};

class NoSpanException : public std::exception
{
	virtual const char* what() const throw();
};

//-----ORTHODOX CANONICAL FORM-----
	Span(const unsigned int _size);
	Span(const Span &copy);
	Span& operator = (const Span &other);
	~Span();
};

// Color codes as global variables
const std::string RESET = "\033[0m";
const std::string RED = "\033[31;1m";
const std::string GREEN = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE = "\033[34;1m";
const std::string PURPLE = "\033[35;1m";
const std::string CYAN = "\033[36;1m";
const std::string GRAY = "\033[37;1m";

#endif