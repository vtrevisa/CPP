/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:44:25 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/22 18:06:52 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main( int argc, char const *argv[] )
{
	if (argc != 2)
	{
		if (argc < 2)
			errorMsg("could not open file.");
		if (argc > 2)
			errorMsg("inout a single file");
		return (1);
	}
	try
	{
		BitcoinExchange exchange;
		exchange.readInput(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << RED;
		std::cerr << RED << "Error: " << e.what() << std::endl;
		std::cerr << RESET << std::endl;
	}

	return 0;
}