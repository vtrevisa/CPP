/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:28:30 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/14 09:37:57 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"

void subjectTests( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main() {
	// Header
	std::cout << CYAN << "*************************\n";
	std::cout << "***** Template Tests *****\n";
	std::cout << "*************************\n\n" << RESET;

	std::cout << BLUE << "*************************\n";
	std::cout << "Subject Tests\n";
	std::cout << "*************************\n" << RESET;

	subjectTests();

	// Test swap
	std::cout << YELLOW << "\n*************************\n";
	std::cout << "Testing swap function:\n";
	std::cout << "*************************\n" << RESET;

	int intA = 1, intB = 2;
	std::cout << "Before swap: intA = " << intA << ", intB = " << intB << std::endl;
	swap(intA, intB);
	std::cout << "After swap: intA = " << intA << ", intB = " << intB << std::endl << std::endl;

	double doubleA = 1.1, doubleB = 2.2;
	std::cout << "Before swap: doubleA = " << doubleA << ", doubleB = " << doubleB << std::endl;
	swap(doubleA, doubleB);
	std::cout << "After swap: doubleA = " << doubleA << ", doubleB = " << doubleB << std::endl << std::endl;

	char charA = 'A', charB = 'B';
	std::cout << "Before swap: charA = " << charA << ", charB = " << charB << std::endl;
	swap(charA, charB);
	std::cout << "After swap: charA = " << charA << ", charB = " << charB << std::endl << std::endl;

	// Test min
	std::cout << GREEN << "*************************\n";
	std::cout << "Testing min function:\n";
	std::cout << "*************************\n" << RESET;

	std::cout << "Min of 3 and 4: " << min(3, 4) << std::endl;
	std::cout << "Min of 5.5 and 2.2: " << min(5.5, 2.2) << std::endl;
	std::cout << "Min of 'x' and 'y': " << min('x', 'y') << std::endl << std::endl;

	// Test max
	std::cout << MAGENTA << "*************************\n";
	std::cout << "Testing max function:\n";
	std::cout << "*************************\n" << RESET;

	std::cout << "Max of 3 and 4: " << max(3, 4) << std::endl;
	std::cout << "Max of 5.5 and 2.2: " << max(5.5, 2.2) << std::endl;
	std::cout << "Max of 'x' and 'y': " << max('x', 'y') << std::endl;

	return 0;
}