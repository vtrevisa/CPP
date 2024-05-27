/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:05 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/21 15:18:44 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	int	z = 10;

	std::cout << BLUE << "---------------------------------------------" << std::endl;
	std::cout << "*********" << GREEN << "TESTING MEMORY ALOCCATION" << BLUE << "*********" << std::endl;
	std::cout << "---------------------------------------------\n" << std::endl;
	std::cout << "Creating Horde with " << z << " zombies..." << std::endl;
	Zombie *horde = zombieHorde(z, "Arlly");

	std::cout << "\nCalling announce function" << std::endl;
	for (int i = 0; i < z; i++)
		horde[i].announce();

	std::cout << "\nDeleting Horde" << std::endl;
	delete[] horde;

	return (0);
}