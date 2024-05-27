/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:30:52 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/27 11:35:21 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class	Harl
{
	private:
	
	void	debug();
	void	info();
	void	warning();
	void	error();

	public:
	
	void	complain(std::string level);

	Harl();
	~Harl();
};
#endif