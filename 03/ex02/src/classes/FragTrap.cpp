/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:09:48 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/03 16:25:35 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/FragTrap.hpp"

FragTrap::FragTrap (std::string name) : ClapTrap(name)
{
	std::cout << "Default constructor called and FragTrap named" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap () : ClapTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap (const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap&	FragTrap::operator = (const FragTrap &other)
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

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name
			  << " wants to high five you =)" 
			  << std::endl;
}