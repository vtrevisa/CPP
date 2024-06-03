/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:59:30 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 17:35:02 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/HumanA.hpp"

HumanA::HumanA( std::string	name, Weapon &weapon ) : _name(name), _weapon(weapon){}

HumanA::~HumanA(){}

const std::string	HumanA::getName()
{
	return _name;
}

const Weapon	HumanA::getWeapon()
{
	return _weapon;
}

void			HumanA::setName(std::string name)
{
	_name = name;
}

void			HumanA::setWeapon(Weapon &weapon)
{
	_weapon = weapon;
}

void			HumanA::attack()
{
	std::cout << _name << " attacks with her/his "
			  << _weapon.getType() << std::endl;
}

