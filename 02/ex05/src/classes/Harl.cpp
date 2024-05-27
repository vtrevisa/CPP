/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:34:43 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/27 12:16:04 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void	Harl::debug()
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-specialketchup"
			  << "burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money."
			  << " You didn’t put enough bacon in my burger! If you did, "
			  << "I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years whereas you started working here since last month."
			  << std::endl;
}

void	Harl::error()
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*levels[4])() = {&Harl::debug, \
									&Harl::error, \
									&Harl::info, \
									&Harl::warning};
	for (int i = 0; i < 5; i++)
	{
		if (level == lvl[i])
		{
			(this->*levels[i])();
			return ;
		}
	}
	std::cout << "Use only: DEBUG - INFO - WARNING - ERROR" << std::endl;
}