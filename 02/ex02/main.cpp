/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:21:55 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 15:32:42 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31;1m";
const std::string GREEN = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE = "\033[34;1m";

int	main()
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string		*stringPTR = &brain;
	std::string		&stringREF = brain;

	std::cout << BLUE;
	std::cout << "------------------------------------------------------\n";
	std::cout << "*************** HI THIS IS BRAIN TEST ****************\n";
	std::cout << "------------------------------------------------------\n";
	std::cout << RESET << std::endl;

	std::cout << GREEN << "Memory address of the string variable:\t";
	std::cout << YELLOW << &brain << std::endl;

	std::cout << GREEN << "Memory address held by stringPTR:\t";
	std::cout << YELLOW << stringPTR << std::endl;

	std::cout << GREEN << "Memory address held by stringREF:\t";
	std::cout << YELLOW << &stringREF << std::endl;

	std::cout << BLUE;
	std::cout << "------------------------------------------------------\n\n";

	std::cout << GREEN << "Value of the string variable:\t";
	std::cout << YELLOW << brain << std::endl;

	std::cout << GREEN << "Value pointed to by stringPTR:\t";
	std::cout << YELLOW << *stringPTR << std::endl;

	std::cout << GREEN << "Value pointed to by stringREF:\t";
	std::cout << YELLOW << stringREF << std::endl;

	std::cout << BLUE;
	std::cout << "------------------------------------------------------\n\n";

	return 0;
	
}