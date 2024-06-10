/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:02:18 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 17:22:40 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

void	tests()
{
	std::cout << "---------------------------------------------------------\n";
	std::cout << "********************* ABSTRACT TEST *********************\n";
	std::cout << "---------------------------------------------------------\n";
	std::cout << "Create a Animal array with 10 elements." << std::endl;
	std::cout << "Fill the Animal array with 10 Animals." << std::endl;
	std::cout << "Half of them are Cats and the other half are Dogs.\n";;
	std::cout << "---------------------------------------------------------\n";;

	AAnimal *animals[10];

	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creating a deep copy of one of the Cats in the array,\n";
	std::cout << "using a new scope." << std::endl;
	std::cout << "Cat created with the copy constructor." << std::endl;
	std::cout << "Copied Cat will make a sound and print its idea.\n";
	std::cout << "Copied Cat will be destroyed with the end of the scope.\n";;
	std::cout << "---------------------------------------------------------\n";;

	if (animals[4]->getType() == "Cat")
	{
		Cat copyCat((Cat&)*animals[4]);

		std::cout << "\nSound: ";
		copyCat.makeSound();

		std::cout << std::endl;
		std::cout << "Idea: " << copyCat.getIdea(42) << "\n\n";
	}
	else
		std::cout << "Error: animals[4] is not of type Cat." << std::endl;

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Checking if the original Cat is still alive." << std::endl;
	std::cout << "Printing the Cat's type, sound and idea." << std::endl;
	std::cout << "Print Cat's idea means that the Cat's brain was\n";
	std::cout << "successfully deep copied." << std::endl;;
	std::cout << "---------------------------------------------------------\n";;

	std::cout << "Type: " << animals[4]->getType() << std::endl;

	std::cout << "\nSound: ";
	animals[4]->makeSound();

	std::cout << std::endl;
	std::cout << "Idea: " << ((Cat*)animals[4])->getIdea(42) << std::endl;

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creating a deep copy of one of the Dogs in the array,\n";
	std::cout << "using a new scope." << std::endl;
	std::cout << "Dog created with the copy constructor." << std::endl;
	std::cout << "Copied Dog will make a sound and print its idea.\n";
	std::cout << "Copied Dog will be destroyed with the end of the scope.\n";;
	std::cout << "---------------------------------------------------------\n";;

	if (animals[7]->getType() == "Dog")
	{
		Dog copyDog((Dog&)*animals[7]);

		std::cout << "\nSound: ";
		copyDog.makeSound();

		std::cout << std::endl;
		std::cout << "Idea: " << copyDog.getIdea(42) << "\n\n";
	}
	else
		std::cout << "Error: animals[7] is not of type Dog." << std::endl;

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Checking if the original Dog is still alive." << std::endl;
	std::cout << "Printing the Dog's type, sound and idea." << std::endl;
	std::cout << "Print Dog's idea means that the Dog's brain was\n";
	std::cout << "successfully deep copied." << std::endl;;
	std::cout << "---------------------------------------------------------\n";;

	std::cout << "Type: " << animals[7]->getType() << std::endl;

	std::cout << "\nSound: ";
	animals[7]->makeSound();

	std::cout << std::endl;
	std::cout << "Idea: " << ((Dog*)animals[7])->getIdea(42) << std::endl;

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Deleting the Animal array.\n";;
	std::cout << "---------------------------------------------------------\n";;

	for (int i = 0; i < 10; ++i)
		delete animals[i];

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creating a new Cat and a new Dog.\n";;
	std::cout << "---------------------------------------------------------\n";;

	Cat snow;
	Dog billy;

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creating a deep copy of the Cat and the Dog, using the\n";
	std::cout << "assignation operator." << std::endl;
	std::cout << "The copies are created in a new scope." << std::endl;
	std::cout << "Copied Cat and Dog will make a sound and print their idea.\n";;
	std::cout << "---------------------------------------------------------\n";;

	{
		Cat cat2 = snow;
		Dog dog2 = billy;

		std::cout << std::endl;
		snow.makeSound();
		std::cout << "Idea: " << snow.getIdea(10) << std::endl;

		std::cout << std::endl;
		billy.makeSound();
		std::cout << "Idea: " << billy.getIdea(10) << std::endl;
		std::cout << std::endl;
	}

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Checking if the original Cat and Dog are still alive.\n";
	std::cout << "Printing the Cat's and Dog's sound and idea." << std::endl;
	std::cout << "Print Cat's and Dog's idea means that the Cat's and Dog's\n";
	std::cout << "brain was successfully deep copied." << std::endl;;
	std::cout << "---------------------------------------------------------\n";;

	std::cout << "Sound: ";
	snow.makeSound();

	std::cout << "Idea: " << snow.getIdea(10) << std::endl;

	std::cout << "\nSound: ";
	billy.makeSound();

	std::cout << "Idea: " << billy.getIdea(10) << std::endl;

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Cat and Dog are destroyed with the end of the program.\n";;
	std::cout << "---------------------------------------------------------\n";
}

int	main ( void )
{
	tests();

	//Abstract Class test
	//AAnimal animal;

	return 0;
}