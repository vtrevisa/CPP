/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:24:50 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 13:52:57 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Zombie.hpp"

Zombie::Zombie(std::string name){this->name = name;}
Zombie::~Zombie(){std::cout << this->name << " has died :<" << std::endl;}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiinnnzzzzZ..." << std::endl;
}