/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:36:12 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/13 18:00:56 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# include "Data.hpp"

class Serializer
{
private:
//----ORTHODOX CANONICAL FORM-----
	Serializer();
	Serializer(const Serializer& copy);
	~Serializer();
	Serializer& operator = (const Serializer& other);
public:
//-----FUNCIONS-----
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif