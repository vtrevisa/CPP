/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:56:58 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 12:56:59 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:

	void	makeSound() const;

	WrongCat();
	WrongCat(const WrongCat &copy);
	~WrongCat();
	WrongCat&	operator = (const WrongCat &other);
};

#endif