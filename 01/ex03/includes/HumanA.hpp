/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:47:22 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 17:39:59 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:

	std::string			_name;
	Weapon				&_weapon;

	public:

	void				attack();

	const std::string	getName();
	const Weapon		getWeapon();

	void				setName(std::string name);
	void				setWeapon(Weapon& weapon);
		
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
};

#endif