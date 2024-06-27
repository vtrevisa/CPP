/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:42:39 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/14 09:53:54 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename I, typename Func>
void iter(I array, int lenght, Func function)
{
	if (!array || !lenght || !function)
		return ;
	for (int i = 0; i < lenght; i++)
		function(array[i]);
}

// Define color codes for the test output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#endif