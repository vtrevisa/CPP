/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:12:15 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/10 16:13:26 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main ( void )
{
	std::cout << "---------------------------------------------------------\n";
	std::cout << "******************** BUREAUCRAT TEST ********************\n";
	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creation of bureaucrat 'Mark' with grade 2..." << std::endl;
	std::cout << "The bureaucrat 'Mark' is printed with the overloaded\n";
	std::cout << " operator '<<'..." << std::endl;
	std::cout << "The bureaucrat 'Mark' increments his grade..." << std::endl;
	std::cout << "The bureaucrat 'Mark' is printed with the overloaded\n";
	std::cout << " operator '<<'..." << std::endl;
	std::cout << "The bureaucrat 'Mark' tries to increment his grade...\n";
	std::cout << "The bureaucrat 'Mark' can't increment his grade,\n";
	std::cout << "because it's the highest grade..." << std::endl;
	std::cout << "---------------------------------------------------------\n";
	try
	{
		Bureaucrat b1("Mark", 2);
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << RESET << std::endl;
	}

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creation of bureaucrat 'Default'" << std::endl;
	std::cout << "---------------------------------------------------------\n";

	try
	{
		Bureaucrat d;
		std::cout << d;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << RESET << std::endl;
	}

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creation of bureaucrat 'Brian' with grade 149...\n";
	std::cout << "The bureaucrat 'Brian' is printed with the overloaded\n";
	std::cout << " operator '<<'..." << std::endl;
	std::cout << "The bureaucrat 'Brian' decrements his grade..." << std::endl;
	std::cout << "The bureaucrat 'Brian' is printed with the overloaded\n";
	std::cout << " operator '<<'..." << std::endl;
	std::cout << "The bureaucrat 'Brian' tries to decrement his grade...\n";
	std::cout << "The bureaucrat 'Brian' can't decrement his grade,\n";
	std::cout << "because it's the lowest grade..." << std::endl;
	std::cout << "---------------------------------------------------------\n";

	try
	{
		Bureaucrat b2("Brian", 149);
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << RESET << std::endl;
	}

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creation of bureaucrat 'Anna' with grade 0..." << std::endl;
	std::cout << "Bureaucrat 'Anna' can't be created, because\n";
	std::cout << "the grade is too high..." << std::endl;
	std::cout << "---------------------------------------------------------\n";

	try
	{
		Bureaucrat b3("Anna", 0);
		std::cout << b3;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << RESET << std::endl;
	}

	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creation of bureaucrat 'James' with grade 151..." << std::endl;
	std::cout << "Bureaucrat 'James' can't be created, because\n";
	std::cout << "the grade is too low..." << std::endl;
	std::cout << "---------------------------------------------------------\n";

	try
	{
		Bureaucrat b4("James", 151);
		std::cout << b4;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << RESET << std::endl;
	}

	std::cout << "---------------------------------------------------------\n";
	std::cout << "---------------------- END OF TEST ----------------------\n";
	std::cout << "---------------------------------------------------------\n";

	return 0;
}