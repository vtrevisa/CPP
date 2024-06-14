/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:32:08 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/13 16:30:21 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	 if (argc != 2)
	{
		std::cout << RED << std::endl;
		std::cout << "Error: wrong number of arguments" << std::endl;
		std::cout << "Usage: ./convert [value]\n" << RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
