/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:22:07 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/17 18:02:47 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef easyFind_HPP
# define easyFind_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>


template <typename T>
typename T::iterator easyFind(T &first, int second)
{
	typename T::iterator i;
	
	i = std::find(first.begin(), first.end(), second);
	if (i == first.end())
		throw std::exception();
	return i;
}

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