/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:44:13 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/02 12:29:28 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class	ClapTrap
{
	private:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

	public:

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	
	std::string	getName();
	void		setName(std::string name);
	int			getHitPoints();
	int			getEnergyPoints();
	int			getAttackDamage();

	ClapTrap(std::string name);
	ClapTrap ();
	~ClapTrap();
	ClapTrap (const ClapTrap &copy);
	ClapTrap& operator = (const ClapTrap &copy);
};

void		showStatus(ClapTrap &ctrp, int status);

#endif