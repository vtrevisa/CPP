/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:51:27 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/24 16:53:33 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Uncomment the line below to enable debug messages
// #define DEBUG

#include "../../includes/RPN.hpp"

//-----MEMBER FUNCTIONS-----
int RPN::evaluate(const std::string &expression) const
{
	std::stack<int>		s;
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (isdigit(token[0]))
			s.push(token[0] - '0');
		else
		{
			checkToken(token);
			performOperation(s, token);
		}
	}
	if (s.size() != 1)
		throw std::invalid_argument("INVALID RPN EXPRESSION");
	return s.top();
}

void RPN::checkToken(const std::string &token) const
{
	if (token.size() != 1 || std::string("+-*/").find(token) == std::string::npos)
		throw std::invalid_argument("INVALID TOKEN IN RPN EXPRESSION");
}

void RPN::performOperation(std::stack<int> &s, const std::string &token) const
{
	if (s.size() < 2)
		throw std::invalid_argument("INVALID RPN EXPRESSION");

	int b = s.top(); s.pop();
	int a = s.top(); s.pop();

	switch (token[0]) {
		case '+': s.push(a + b); break;
		case '-': s.push(a - b); break;
		case '*': s.push(a * b); break;
		case '/':
			if (b == 0)
				throw std::runtime_error("DIVISION BY ZERO");
			s.push(a / b); break;
		default:
			throw std::invalid_argument("UNKNOWN OPERATOR");
	}
}

//-----ORTHODOX CANONICAL FORM-----
RPN::RPN()
{
#ifdef DEBUG
	std::cout << "DEFAULT CONSTRUCTOR CALLED" << std::endl;
#endif
}

RPN::RPN(const RPN &other)
{
#ifdef DEBUG
	std::cout << "COPY CONSTRUCTOR CALLED" << std::endl;
#endif
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
#ifdef DEBUG
	std::cout << "ASSIGNMENT OPERATOR CALLED" << std::endl;
#endif
	if (this != &other){}
	return *this;
}

RPN::~RPN()
{
#ifdef DEBUG
	std::cout << "DESTRUCTOR CALLED" << std::endl;
#endif
}
