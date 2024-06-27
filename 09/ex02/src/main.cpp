/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:24:56 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/26 19:59:47 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char* argv[])
{
	try {
		PmergeMe sorter;
		sorter.mergeInsert(argc, argv);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}