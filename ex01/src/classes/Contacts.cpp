/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:36:33 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 11:06:23 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PhoneBook.hpp"

Contacts::Contacts(){}
Contacts::~Contacts(){}

void Contacts::setData(std::string data[])
{
	for (int i = 0; i < 5; i++)
		this->data[i] = data[i];
	this->isEmpty = false;
}

std::string *Contacts::getData(void)
{
	if (this->isEmpty)
		return (NULL);
	return (this->data);
}

std::string	Contacts::getFirstName(void) {return (this->data[0]);}
std::string	Contacts::getLastName(void) {return (this->data[1]);}
std::string	Contacts::getNickName(void) {return (this->data[2]);}
std::string	Contacts::getPhoneNumber(void) {return (this->data[3]);}
std::string	Contacts::getDarkestSecret(void) {return (this->data[4]);}