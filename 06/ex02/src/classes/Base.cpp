/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:21:07 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/13 19:10:24 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Base.hpp"

Base*	generate()
{
	int i = std::rand();
	
	if (i % 2 == 0)
	{
		std::cout << "Class A created!" << std::endl;
		return new A;
	}
	else if (i % 3 == 0)
	{
		std::cout << "Class B created!" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Class C created!" << std::endl;
		return new C;
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Easy peasy, it's an A class!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Try something harder, it's a B class!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Are u joking? simply a C class!" << std::endl;
	else
		std::cout << "Unknown Derived Class, didn't like this" << std::endl;

}

void	identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Difinitively an A Class, i'm awesome!" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B b = dynamic_cast<B&>(p);
			std::cout << "Basically an B Class, next, please!" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C c = dynamic_cast<C&>(p);
				std::cout << "Just an C Class, i'll ace every single time!" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Damn, idk that one!" << std::endl;
			}
		}
	}
}

Base::~Base()
{
	std::cout << "Destructor called!" << std::endl;
}