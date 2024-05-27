/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:20:16 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/27 12:30:57 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	for(int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}