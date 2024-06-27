/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:06:17 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/14 09:46:40 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename S>
void swap(S& param1, S& param2)
{
	S tmp = param2;
	param2 = param1;
	param1 = tmp;
};

template <typename M>
M min(M param1, M param2)
{
	return ((param1 < param2) ? param1 : param2);
};

template <typename MA>
MA max(MA param1, MA param2)
{
	return ((param1 > param2) ? param1 : param2);
};

// Define color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#endif