/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:11:20 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 11:08:24 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLAS_HPP
# define PHONEBOOK_CLAS_HPP

#include <iomanip>
#include <iostream>
#include <string>

#include "Contacts.hpp"
#include "Utils.hpp"

class PhoneBook
{
	private:

	int				ContactCount;
	int				ContactIndex;
	Contacts		contacts[8];

	static bool		valIndex(std::string index);
	static bool		valName(std::string name);
	static bool		valNumber(std::string number);

	public:

	Utils utils;

	void			add_contact(void);
	void			search_contact(void);

	PhoneBook();
	~PhoneBook();
};

#endif