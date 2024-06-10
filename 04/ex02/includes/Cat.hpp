/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:43:31 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/05 17:12:34 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:

	Brain* _brain;

	public:

	void		makeSound() const;
	std::string	getIdea(int N);

	Cat();
	Cat(const Cat &copy);
	~Cat();
	Cat&	operator = (const Cat &other);
};

#endif