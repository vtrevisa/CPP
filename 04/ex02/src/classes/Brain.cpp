/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:53:35 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 15:28:23 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Brain.hpp"

Brain::Brain()
{
	std::string ideas[] = {"Cuddle",
						   "Sleep",
						   "Complain",
						   "Ask for food",
						   "Random toghts"};
	for (int i = 0; i < 100; i++)
		_ideas[i] = ideas[rand() % 5];
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain (const Brain& copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator = (const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int N)
{
	return this->_ideas[N];
}