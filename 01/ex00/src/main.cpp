/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:05 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/03 11:51:58 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

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