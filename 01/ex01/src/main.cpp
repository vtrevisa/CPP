/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:59:31 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 11:06:55 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int	main(void)
{
	PhoneBook		book;
	std::string		command;

	std::cout << "This is your phonebook!" << std::endl;
	while (book.utils.running)
	{
		book.utils.showMenu();
		if (book.utils.getCommand("Input your command: ", command, NULL) == false)
			return (false);
		if (command == "ADD" || command == "add")
			book.add_contact();
		else if (command == "SEARCH" || command == "search")
			book.search_contact();
		else if (command == "EXIT" || command == "exit")
			return (0);
		else
			std::cout << "Invalid command, please use ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}