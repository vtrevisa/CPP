/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:47:22 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 17:38:40 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:

	std::string			_name;
	Weapon				*_weapon;

	public:

	void				attack();

	const std::string	getName();
	const Weapon		getWeapon();

	void				setName(std::string name);
	void				setWeapon(Weapon& weapon);
		
	HumanB(std::string name);
	~HumanB();
};

#endif