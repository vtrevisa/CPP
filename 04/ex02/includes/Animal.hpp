/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:43:31 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 17:13:12 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:

	std::string	_type;

	public:

	std::string	getType();
	void		setType(std::string type);

	virtual void		makeSound() const;
	
	Animal();
	Animal(std::string type);
	Animal(const Animal &copy);
	virtual ~Animal();
	Animal&	operator = (const Animal &other);
};

#endif