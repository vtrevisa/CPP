/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:28:36 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 22:08:20 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

static void bureaucratTest( void )
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
		Bureaucrat bureaucrat("Mark", 2);
		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
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
	std::cout << "Creation of bureaucrat 'James' with grade 151...\n";
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
}

static void shrubberyTest( void )
{
	std::cout << "---------------------------------------------------------\n";
	std::cout << "********************* SHRUBBERY TEST ********************\n";
	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creation of a ShrubberyCreationForm Test\n";
	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creation of ShrubberyCreationForm 'home' with grade to\n";
	std::cout << "sign 145 and grade to execute 137..." << std::endl;
	std::cout << "Creation of bureaucrat 'James' with grade 138...\n";
	std::cout << "The bureaucrat 'James' tries to execute the form 'home'...\n";
	std::cout << "The bureaucrat 'James' can't execute the form 'home',\n";
	std::cout << "because it's not signed..." << std::endl;
	std::cout << "The bureaucrat 'James' signs the form 'home'...\n";
	std::cout << "The bureaucrat 'James' tries to execute the form 'home'...\n";
	std::cout << "The bureaucrat 'James' can't execute the form 'home',\n";
	std::cout << "because his grade is too low..." << std::endl;
	std::cout << "The bureaucrat 'James' increments his grade..." << std::endl;
	std::cout << "The bureaucrat 'James' executes the form 'home' creating\n";
	std::cout << "a file 'home_shrubbery'..." << std::endl;
	std::cout << "---------------------------------------------------------\n";

	try
	{
		ShrubberyCreationForm form("home");
		std::cout << form;

		Bureaucrat bureaucrat("James", 138);
		std::cout << bureaucrat;

		bureaucrat.executeForm(form);

		bureaucrat.signForm(form);
		std::cout << form;

		bureaucrat.executeForm(form);

		bureaucrat.incrementGrade();
		std::cout << bureaucrat;

		bureaucrat.executeForm(form);
	}
		catch (std::exception &e)
	{
		std::cout << std::endl;
		std::cout << e.what() << RESET << std::endl;
	}
}

static void robotomyTest( void )
{
	std::cout << "---------------------------------------------------------\n";
	std::cout << "********************* ROBOTOMY TEST *********************\n";
	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creation of a RobotomyRequestForm Test\n";
	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creation of RobotomyRequestForm 'R2-D2' with grade to\n";
	std::cout << "sign 72 and grade to execute 45..." << std::endl;
	std::cout << "Creation of bureaucrat 'Luke' with grade 46...\n";
	std::cout << "The bureaucrat 'Luke' signs the form 'R2-D2'...\n";
	std::cout << "The bureaucrat 'Luke' tries to execute the form 'R2-D2',\n";
	std::cout << "The bureaucrat 'Luke' can't execute the form 'R2-D2',\n";
	std::cout << "because his grade is too low..." << std::endl;
	std::cout << "The bureaucrat 'Luke' increments his grade..." << std::endl;
	std::cout << "The bureaucrat 'Luke' executes the form 'R2-D2'\n";
	std::cout << "---------------------------------------------------------\n";

	try
	{
		RobotomyRequestForm form("R2-D2");
		std::cout << form;

		Bureaucrat bureaucrat("Luke", 46);
		std::cout << bureaucrat;

		bureaucrat.signForm(form);
		std::cout << form;

		bureaucrat.executeForm(form);

		bureaucrat.incrementGrade();
		std::cout << bureaucrat;

		bureaucrat.executeForm(form);
	}
		catch (std::exception &e)
	{
		std::cout << std::endl;
		std::cout << e.what() << RESET << std::endl;
	}

	std::cout << "---------------------------------------------------------\n";
	std::cout << "*************** PRESIDENTIAL PARDON TEST ****************\n";
	std::cout << "---------------------------------------------------------\n";
	std::cout << "---------------------------------------------------------\n";
	std::cout << "PresidentialPardonForm Test" << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << "Creation of bureaucrat 'Leila' with grade 26...\n";
	std::cout << "Creation of PresidentialPardonForm 'Billy' with grade to\n";
	std::cout << "sign 25 and grade to execute 5..." << std::endl;
	std::cout << "The bureaucrat 'Leila' tries to execute the form 'Billy'...\n";
	std::cout << "The bureaucrat 'Leila' can't execute the form 'Billy',\n";
	std::cout << "because it's not signed..." << std::endl;
	std::cout << "The bureaucrat 'Leila' tries to sign the form 'Billy'...\n";
	std::cout << "The bureaucrat 'Leila' can't sign the form 'Billy',\n";
	std::cout << "because his grade is too low..." << std::endl;
	std::cout << "The bureaucrat 'Leila' increments his grade...\n";
	std::cout << "The bureaucrat 'Leila' signs the form 'Billy'...\n";
	std::cout << "The bureaucrat 'Leila' tries to execute the form 'Billy'...\n";
	std::cout << "The bureaucrat 'Leila' can't execute the form 'Billy',\n";
	std::cout << "because his grade is too low..." << std::endl;
	std::cout << "The bureaucrat 'Leila' increments his grade 20 times...\n";
	std::cout << "The bureaucrat 'Leila' executes the form 'Billy'...\n";
	std::cout << "---------------------------------------------------------\n";
	try
	{
		Bureaucrat bureaucrat("Leila", 26);
		std::cout << bureaucrat;

		PresidentialPardonForm form("Billy");
		std::cout << form;

		bureaucrat.executeForm(form);
		bureaucrat.signForm(form);
		std::cout << form;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat;

		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		for (int i = 0; i < 20; i++)
			bureaucrat.incrementGrade();

		std::cout << bureaucrat;
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;

	}
}

int main ( void )
{
	std::cout << "---------------------------------------------------------\n";
	std::cout << "************************* TESTS *************************\n";
	std::cout << "---------------------------------------------------------\n";

	bureaucratTest();
	shrubberyTest();
	robotomyTest();

	std::cout << "---------------------------------------------------------\n";
	std::cout << "********************** END OF TEST **********************\n";
	std::cout << "---------------------------------------------------------\n";

	return 0;
}