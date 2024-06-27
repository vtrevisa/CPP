/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:53:14 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/24 15:35:52 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

template <typename T>
void printElement(const T& element) {
	std::cout << element << " ";
}

template <typename T>
void doubleElement(T& element) {
	element *= 2;
}

int main() {
	// Header
	std::cout << CYAN << "*************************\n";
	std::cout << "***** Template Tests *****\n";
	std::cout << "*************************\n\n" << RESET;

	// Test iter with printElement function
	std::cout << YELLOW << "*************************\n";
	std::cout << "Testing iter with printElement function:\n";
	std::cout << "*************************\n" << RESET;

	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
	std::cout << "Original intArray: ";
	iter(intArray, intArrayLength, printElement<int>);
	std::cout << std::endl << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
	std::cout << "Original doubleArray: ";
	iter(doubleArray, doubleArrayLength, printElement<double>);
	std::cout << std::endl << std::endl;

	char charArray[] = {'A', 'B', 'C', 'D', 'E'};
	size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);
	std::cout << "Original charArray: ";
	iter(charArray, charArrayLength, printElement<char>);
	std::cout << std::endl << std::endl;

	// Test iter with doubleElement function
	std::cout << GREEN << "*************************\n";
	std::cout << "Testing iter with doubleElement function:\n";
	std::cout << "*************************\n" << RESET;

	std::cout << "Doubling intArray elements..." << std::endl;
	iter(intArray, intArrayLength, doubleElement<int>);
	std::cout << "Modified intArray: ";
	iter(intArray, intArrayLength, printElement<int>);
	std::cout << std::endl << std::endl;

	std::cout << "Doubling doubleArray elements..." << std::endl;
	iter(doubleArray, doubleArrayLength, doubleElement<double>);
	std::cout << "Modified doubleArray: ";
	iter(doubleArray, doubleArrayLength, printElement<double>);
	std::cout << std::endl << std::endl;

	return 0;
}