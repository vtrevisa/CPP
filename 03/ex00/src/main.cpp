/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:10:23 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/03 15:06:50 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int	main()
{
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "************************ CLAPTRAP TEST ************************" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "->ClapTrap a is created with name Arly" << std::endl;
	std::cout << "->ClapTrap b is created with no name and then called Raz" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	ClapTrap a("Arly");
	ClapTrap b;

	b.setName("Raz");

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "->Arly attacks Raz" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	a.attack(b.getName());
	showStatus(a, 2);
	b.takeDamage(a.getAttackDamage());
	showStatus(b, 1);
	
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "->Raz attacks Arly" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	b.attack(a.getName());
 	showStatus(b, 2);
	a.takeDamage(b.getAttackDamage());
	showStatus(a, 1);

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "->Arly repairs himself with 2 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	a.beRepaired(2);
	showStatus(a, 1);

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "->Arly attacks Raz 10 times" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		a.attack(b.getName());
		showStatus(a, 2);
		b.takeDamage(a.getAttackDamage());
		showStatus(b, 1);
	}
	a.attack(b.getName());
	a.attack(b.getName());

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "->Raz repairs himself with 2 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	b.beRepaired(2);
	showStatus(b, 1);
	showStatus(b, 2);

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "->Arly try repairs himself with 5 hit points" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	a.beRepaired(5);
	showStatus(a, 1);
	showStatus(a, 2);

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "->Arly and Raz are destroyed" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	return 0;
}