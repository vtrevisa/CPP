/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:10:23 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/03 16:10:22 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int	main ( void )
{
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "************************ SCAVTRAP TEST ************************" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "ClapTrap Arlly is created with name Arlly" << std::endl;
	std::cout << "ScavTrap Raz is created with name Raz" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	ClapTrap Arlly("Arlly");
	ScavTrap Raz("Raz");

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Arlly attacks Raz" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Arlly.attack(Raz.getName());
	Raz.takeDamage(Arlly.getAttackDamage());
	showStatus(Raz, 1);
	showStatus(Arlly, 2);

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Raz attacks Arlly" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Raz.attack(Arlly.getName());
 	Arlly.takeDamage(Raz.getAttackDamage());
	showStatus(Arlly, 1);
	showStatus(Raz, 2);


	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Arlly repairs himself with 20 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Arlly.beRepaired(20);
	showStatus(Arlly, 1);
	showStatus(Arlly, 2);

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Arlly attacks Raz 10 times" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		Arlly.attack(Raz.getName());
		Raz.takeDamage(Arlly.getAttackDamage());
		showStatus(Raz, 1);
		showStatus(Arlly, 2);
	}
	Arlly.attack(Raz.getName());
	Arlly.attack(Raz.getName());

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Raz repairs himself with 20 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Raz.beRepaired(20);
	showStatus(Raz, 1);
	showStatus(Raz, 2);

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Arlly try repairs himself with 5 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Arlly.beRepaired(5);

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Raz give up from war, and he is now a gatekeeper" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Raz.guardGate();

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Arlly and Raz are destroyed" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	
	return 0;
}