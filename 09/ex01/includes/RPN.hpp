/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:45:35 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/23 11:51:10 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN
{
private:
	void checkToken(const std::string &token) const;
	void performOperation(std::stack<int> &s, const std::string &token) const;

public:
	//-----MEMBER FUNCTIONS-----
	int evaluate(const std::string &expression) const;

	//-----ORTHODOX CANONICAL FORM-----
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
};

#endif

