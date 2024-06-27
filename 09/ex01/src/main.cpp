/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:53:11 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/23 11:53:23 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "USAGE: " << argv[0] << " \"<RPN EXPRESSION>\"" << std::endl;
		return 1;
	}

	try {
		RPN rpn;
		int result = rpn.evaluate(argv[1]);
		std::cout << result << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
