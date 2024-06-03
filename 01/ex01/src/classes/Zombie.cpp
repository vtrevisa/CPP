/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:24:50 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 15:19:20 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << RED << "A wild ZOMBIE appeard" << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << GREEN << this->_name << " has died again :<" << RESET << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << YELLOW << this->_name << ": BraiiiiinnnzzzzZ..." <<  RESET << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}