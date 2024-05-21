/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:32:00 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 11:06:35 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PhoneBook.hpp"

Utils::Utils(){this->running = true;}
Utils::~Utils(){}

void	Utils::headerDisplay()
{
	std::cout << std::setw(10) << std::right << "Index"
			  << '|' << std::setw(10) << std::right << "First name"
			  << '|' << std::setw(10) << std::right << "Last name"
			  << '|' << std::setw(10) << std::right << "Nickname"
			  << '\n';
}

void Utils::bodyDisplay(std::string firstName, std::string lastName, std::string nickname, int index)
{
	firstName = (firstName.length() > 10) ? (firstName.substr(0, 9) + ".") : firstName;
	lastName = (lastName.length() > 10) ? (lastName.substr(0, 9) + ".") : lastName;
	nickname = (nickname.length() > 10) ? (nickname.substr(0, 9) + ".") : nickname;

	std::cout << std::string(45, '-') << '\n'
			  << std::setw(10) << std::right << index << '|'
			  << std::setw(10) << std::right << firstName << '|'
			  << std::setw(10) << std::right << lastName << '|'
			  << std::setw(10) << std::right << nickname << '\n';
}

bool	Utils::getCommand(std::string msg, std::string &value, bool (*validate) (std::string))
{
	std::string input;

	if (this->running == false)
		return (false);
	while (this->running == true)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.bad() || std::cin.fail())
		{
			std::cout << "Wrong input or EoF, don't do that to me, please :<" << std::endl;
			this->running = false;
			return (false);
		}
		if (input.length() > 150)
		{
			std::cout << "Command can't have more than 150 characteres" << std::endl;
			continue;
		}
		if (input.empty() == true)
		{
			std::cout << "Please enter some command" << std::endl;
			continue;
		}
		if (validate != NULL)
			if (validate(input) == false)
				continue;
		value = input;
		return (true);
	}
	return (false);
}

void	Utils::singleContact(std::string data[])
{
	if (data == NULL)
	{
		std::cout << "Contact is empty" << std::endl;
		return;
	}
	std ::cout << std::string(45, '-') << '\n'
			   << "First name: " << data[0] << '\n'
			   << "Last name: " << data[1] << '\n'
			   << "Nickname: " << data[2] << '\n'
			   << "Phone number: " << data[3] << '\n'
			   << "Darkest secret: " << data[4] << '\n'
			   << std::string(45, '-') << '\n';
}

void	Utils::showMenu(void)
{
	std::cout << "\n"
			  << "Type [ADD] to add a new Contacts\n"
			  << "Type [SEARCH] to search for a Contacts\n"
			  << "Type [EXIT] to exit the Phonebook\n"
			  << std::endl;
}