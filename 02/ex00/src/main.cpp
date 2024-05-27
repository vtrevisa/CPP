/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:05 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 13:47:30 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie allyne("Arlly");
	Zombie *tomas = newZombie("Tom");

	allyne.announce();
	tomas->announce();
	randomChump("Raz");

	delete (tomas);
	return (0);
}