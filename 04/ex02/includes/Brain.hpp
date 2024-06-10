/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:43:07 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 16:27:06 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "AAnimal.hpp"
#include <iostream>
#include <cmath>

class Brain
{
	private:

	std::string _ideas[100];

	public:

	std::string	getIdea(int N);

	Brain();
	~Brain();
	Brain (const Brain &copy);
	Brain& operator = (const Brain &other);
};

#endif