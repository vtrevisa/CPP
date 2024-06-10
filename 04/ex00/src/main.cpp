/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:02:18 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 14:38:21 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int	main ( void )
{
	std::cout << "---------------------------------------------------------\n";
	std::cout << "********************* SUBJECT TEST **********************\n";
	std::cout << "---------------------------------------------------------\n";
	std::cout << "Instantiate Animal class, atributing to a Animal pointer.\n";
	std::cout << "---------------------------------------------------------\n";

	Animal* meta = new Animal();

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Instantiate Dog class, atributing to a Animal pointer.\n";
	std::cout << "---------------------------------------------------------\n";

	Animal* j = new Dog();

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Instantiate Cat class, atributing to a Animal pointer.\n";
	std::cout << "---------------------------------------------------------\n";

	Animal* i = new Cat();

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Get the type of the Animal atributed to the Dog pointer.\n";
	std::cout << "---------------------------------------------------------\n";

	std::cout << j->getType() << std::endl;

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Get the type of the Animal atributed to the Cat pointer.\n";
	std::cout << "---------------------------------------------------------\n";

	std::cout << i->getType() << std::endl;


	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Make the Cat sound.\n";
	std::cout << "---------------------------------------------------------\n";

	i->makeSound();

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Make the Dog sound.\n";
	std::cout << "---------------------------------------------------------\n";

	j->makeSound();

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Make the Animal sound.\n";
	std::cout << "---------------------------------------------------------\n";

	meta->makeSound();

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "****************** WRONG ANIMALS TESTS ******************\n";
	std::cout << "---------------------------------------------------------\n";
	std::cout << "Instantiate WrongAnimal class, atributing to a\nWrongAnimal";
	std::cout << " pointer.\n";
	std::cout << "---------------------------------------------------------\n";

	WrongAnimal* wrongAnimal = new WrongAnimal();


	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Instantiate WrongCat class, atributing to a\nWrongAnimal";
	std::cout << " pointer.\n";
	std::cout << "---------------------------------------------------------\n";

	WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Get the type of the WrongAnimal atributed to the\nWrongCat";
	std::cout << " pointer.\n";
	std::cout << "---------------------------------------------------------\n";

	std::cout << wrongCat->getType() << std::endl;

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Make the WrongCat sound.\n";
	std::cout << "---------------------------------------------------------\n";

	wrongCat->makeSound();

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Make the WrongAnimal sound.\n";
	std::cout << "---------------------------------------------------------\n";

	wrongAnimal->makeSound();

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "Delete all the pointers.\n";
	std::cout << "---------------------------------------------------------\n";

	delete meta;
	delete j;
	delete i;
	delete wrongAnimal;
	delete wrongCat;

	std::cout << "\n---------------------------------------------------------\n";
	std::cout << "********************* END OF TESTS **********************\n";
	std::cout << "---------------------------------------------------------\n";

	return 0;
}