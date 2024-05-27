/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumabB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:34:14 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 17:37:43 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/HumanB.hpp"

HumanB::HumanB( std::string	name) : _name(name)
{
	_weapon = NULL;
}

HumanB::~HumanB(){}

const std::string	HumanB::getName()
{
	return _name;
}

const Weapon	HumanB::getWeapon()
{
	return *_weapon;
}

void			HumanB::setName(std::string name)
{
	_name = name;
}

void			HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void			HumanB::attack()
{
	std::cout << _name << " attacks with her/his " << std::endl;
	if (!_weapon)
		std::cout << "hands (amazing *-*)" << std::endl;
	else
		std::cout << _weapon->getType() << std::endl;
}