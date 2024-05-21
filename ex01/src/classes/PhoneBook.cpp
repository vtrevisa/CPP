/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:38:24 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 11:07:18 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->ContactCount = 0;
	this->ContactIndex = 0;
}

PhoneBook::~PhoneBook(){}

bool	PhoneBook::valIndex(std::string index)
{
	if (index[0] < '0' || index[0] > '7' || index.length() > 1)
	{
		std::cout << "Index must be between 0 and 7." <<  std::endl;
		return false;
	}
	return true;
}

bool PhoneBook::valName(std::string name)
{
	int len = name.length();

	if (len < 3 || len > 20)
	{
		std::cout << "First, Last or Nick Names must have between 3 and 20 characters." << '\n';
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (!std::isalpha(name[i]))
		{
			std::cout << "Name must have only letters." << '\n';
			return false;
		}
	}
	return true;
}

bool PhoneBook::valNumber(std::string number)
{
	int len = number.length();

	if (len < 3 || len > 20)
	{
		std::cout << "Phone Number must have between 3 and 20 characters." << '\n';
		return false;
	}

	for (int i = 0; i < len; i++)
	{
		if (!std::isdigit(number[i]))
		{
			std::cout << "Phone Number must have only numbers." << '\n';
			return false;
		}
	}
	return true;
}

void	PhoneBook::add_contact(void)
{
	std::string data[5];
	if (this->ContactIndex == 8)
		this->ContactIndex = 0;
	if (this->utils.getCommand ("Type the first name: ", data[0], this->valName) &&
		this->utils.getCommand ("Type the last name: ", data[1], this->valName) &&
		this->utils.getCommand ("Type the nickname: ", data[2], this->valName) &&
		this->utils.getCommand ("Type the phone number: ",data[3], this->valNumber) &&
		this->utils.getCommand ("Type the darkest secret: ",data[4], NULL))
	{
		this->contacts[this->ContactIndex].setData(data);
		if (this->ContactCount < 8)
			this->ContactCount++;
		this->ContactIndex++;
	}
}

void	PhoneBook::search_contact(void)
{
	if (this->ContactIndex == 0)
	{
		std::cout << "Your list is empty" << std::endl;
		return;
	}
	this->utils.headerDisplay();
	for (int i = 0; i < this->ContactCount;i++)
	{
		this->utils.bodyDisplay(this->contacts[i].getFirstName(), 
							  this->contacts[i].getLastName(), 
							  this->contacts[i].getNickName(),
							  i);
	}
	std::cout << std::string(45, '-') << std::endl;
	std::string input;
	if (this->utils.getCommand("Choose a contacts index ", input, this->valIndex))
		this->utils.singleContact(this->contacts[input[0] - '0'].getData());
}