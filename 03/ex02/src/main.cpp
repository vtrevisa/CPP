/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:10:23 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/03 16:27:28 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int	main ( void )
{
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "************************ FRAGTRAP TEST ************************" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "ClapTrap Tom is created with name Tom" << std::endl;
	std::cout << "ScavTrap Raz is created with name Raz" << std::endl;
	std::cout << "FragTrap Arlly is created with name Arlly" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	ClapTrap Tom("Tom");
	ScavTrap Raz("Raz");
	FragTrap Arlly("Arlly");

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Tom attacks Raz" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Tom.attack(Raz.getName());
	Raz.takeDamage(Tom.getAttackDamage());

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Tom attacks Arlly" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Tom.attack(Arlly.getName());
	Arlly.takeDamage(Tom.getAttackDamage());

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Raz attacks Tom" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Raz.attack(Tom.getName());
 	Tom.takeDamage(Raz.getAttackDamage());

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Tom repairs himself with 20 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Tom.beRepaired(20);

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Arlly attacks Raz 5 times" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		Arlly.attack(Raz.getName());
		Raz.takeDamage(Arlly.getAttackDamage());
	}

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Raz repairs himself with 30 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Raz.beRepaired(30);

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Tom try repairs himself with 5 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Tom.beRepaired(5);

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Raz give up from war, and he is now a gatekeeper" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Raz.guardGate();

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Arlly are happy and he is now a high five guy" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Arlly.highFivesGuys();

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "Tom, Raz  and Arlly are destroyed" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	return 0;
}