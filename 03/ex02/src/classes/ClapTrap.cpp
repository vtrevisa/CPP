/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:49:49 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/03 16:22:00 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ClapTrap.hpp"


ClapTrap::ClapTrap (std::string name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called and ClapTrap named" << std::endl;
}

ClapTrap::ClapTrap ()
: _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap &other)
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

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name
				  << " attacks " << target
				  << ", causing " << _attackDamage
				  << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		if (_energyPoints <= 0)
			std::cout << "ClapTrap " << _name << " Couldn't attack, no Energy Points (" << _energyPoints << ")" << std::endl;
		if (_hitPoints <= 0)
			std::cout << "ClapTrap " << _name << " Couldn't attack, no Hit Points (" << _hitPoints << ")" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name
				  << " took " << amount
				  << " points of damage!" << std::endl;
		_hitPoints -= amount;
		if (_hitPoints <= 0)
			std::cout << "ClapTrap " << _name << " has died" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " is alread dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name
				  << " repair it self, recovering " << amount
				  << " Hit Points!" << std::endl;
		_energyPoints -= 1;
		_hitPoints += amount;
	}
	else
	{
		if (_energyPoints <= 0)
			std::cout << "ClapTrap " << _name << " Couldn't recover, no Energy Points (" << _energyPoints << ")" << std::endl;
		if (_hitPoints <= 0)
			std::cout << "ClapTrap " << _name << " Couldn't recover, no Hit Points (" << _hitPoints << ")" << std::endl;
	}
}

std::string	ClapTrap::getName()
{
	return _name;
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
	std::cout << "Name set to " << name << std::endl;
}

int	ClapTrap::getHitPoints()
{
	return _hitPoints;
}

int	ClapTrap::getEnergyPoints()
{
	return _energyPoints;
}

int	ClapTrap::getAttackDamage()
{
	return _attackDamage;
}

void	showStatus(ClapTrap &ctrp, int status)
{
	std::cout << "Name: " << ctrp.getName() << std::endl;
	if (status == 1)
		std::cout << "Has " << ctrp.getHitPoints() << " HP left" << std::endl;
	if (status == 2)
		std::cout << "Has " << ctrp.getEnergyPoints() << " EP left" << std::endl;
	if (status == 3)
	{
		std::cout << "Has " << ctrp.getHitPoints() << " HP left and" << std::endl;
		std::cout << ctrp.getEnergyPoints() << " EP left" << std::endl;
	}
}

