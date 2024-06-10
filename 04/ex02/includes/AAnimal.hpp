/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:43:31 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 16:23:48 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:

	std::string	_type;

	public:

	std::string	getType();
	void		setType(std::string type);

	virtual void		makeSound() const = 0;
	
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &copy);
	virtual ~AAnimal();
	AAnimal&	operator = (const AAnimal &other);
};

#endif