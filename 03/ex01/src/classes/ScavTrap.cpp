/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:29:00 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/03 16:21:37 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ScavTrap.hpp"

ScavTrap::ScavTrap (std::string name) : ClapTrap(name)
{
	std::cout << "Default constructor called and ScavTrap named" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap () : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap&	ScavTrap::operator = (const ScavTrap &other)
{
	std::cout << "Overload of '=' operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}

	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name
				  << " attacks " << target
				  << ", causing " << _attackDamage
				  << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		if (_energyPoints == 0)
			std::cout << "ScavTrap " << _name << " Couldn't attack, no Energy Points (" << _energyPoints << ")" << std::endl;
		if (_hitPoints == 0)
			std::cout << "ScavTrap " << _name << " Couldn't attack, no Hit Points (" << _hitPoints << ")" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name
			  << " is guarding the gate!" 
			  << std::endl;
}

void	showStatus(ScavTrap &strp, int status)
{
	std::cout << "Name: " << strp.getName() << std::endl;
	if (status == 1)
		std::cout << "Has " << strp.getHitPoints() << " HP left" << std::endl;
	if (status == 2)
		std::cout << "Has " << strp.getEnergyPoints() << " EP left" << std::endl;
	if (status == 3)
	{
		std::cout << "Has " << strp.getHitPoints() << " HP left and" << std::endl;
		std::cout << strp.getEnergyPoints() << " EP left" << std::endl;
	}
}
