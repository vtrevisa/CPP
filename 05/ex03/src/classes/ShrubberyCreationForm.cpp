/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:18:35 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 20:50:16 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ShrubberyCreationForm.hpp"

//-----ORTODOX CANONICAL FORM-----
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  AForm ("Shrubbery Creation", 145, 137)
{
	std::cout << "SCF default constructor called!" << std::endl;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy)
{
	std::cout << "SCF copy constructor called!" << std::endl;
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (ShrubberyCreationForm const &other)
{
	std::cout << "SCF copy assingment overload called!" << std::endl;
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "SCF default destructor called!" << std::endl;///
}

//-----FUNCTIONS-----

static void	drawTrees(std::string fileName)
{
	std::ofstream file(fileName.c_str(), std::ios_base::app);
	if (!file.is_open() || file.fail())
		throw(std::ios_base::failure("Error creating the file"));
file << "                      - - -" << std::endl;
file << "                   -        -  -     --    -"<< std::endl;
file << "                -                 -         -  -"<< std::endl;
file << "                                -"<< std::endl;
file << "                               -                --"<< std::endl;
file << "               -          -            -              -"<< std::endl;
file << "               -            '-,        -               -"<< std::endl;
file << "               -              'b      *"<< std::endl;
file << "                -              '$    #-                --"<< std::endl;
file << "               -    -           $:   #:               -"<< std::endl;
file << "             --      -  --      *#  @):        -   - -"<< std::endl;
file << "                          -     :@,@):   ,-**:'   -"<< std::endl;
file << "              -      -,         :@@*: --**'      -   -"<< std::endl;
file << "                       '#o-    -:(@'-@*\"'  -"<< std::endl;
file << "               -  -       'bq,--:,@@*'   ,*      -  -"<< std::endl;
file << "                          ,p$q8,:@)'  -p*'      -"<< std::endl;
file << "                   -     '  - '@@Pp@@*'    -  -"<< std::endl;
file << "                    -  - --    Y7'.'     -  -"<< std::endl;
file << "                              :@):."<< std::endl;
file << "                             .:@:'."<< std::endl;
file << "                           .::(@:. "<< std::endl;

	file.close();
}
void	ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	try 
	{
		AForm::execute(b);
		drawTrees(_target + "_shrubbery");
	}
	catch (std::exception& e)
	{
		std::cout	<< AForm::getName() << " has not been executed because "
					<< e.what() << std::endl;
	}
}
