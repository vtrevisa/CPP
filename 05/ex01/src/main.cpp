/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:28:36 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 18:33:08 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

#include <iostream>

void printTestHeader(const std::string& header) {
	std::cout << HEADER_COLOR << header << RESET << std::endl;
	std::cout << SEPARATOR_COLOR << "******************************" << RESET << std::endl;
}

void printTestFooter() {
	std::cout << SEPARATOR_COLOR << "******************************" << RESET << std::endl;
}

void printTestResult(const std::string& testName, bool passed) {
	if (passed) {
		std::cout << PASS_COLOR << "[PASS] " << testName << RESET << std::endl;
	} else {
		std::cout << FAIL_COLOR << "[FAIL] " << testName << RESET << std::endl;
	}
}

void testBureaucrat() {
	printTestHeader("Testing Bureaucrat");

	try {
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade(); // This should throw an exception
		printTestResult("Increment grade beyond limit", false);
	} catch (const std::exception& e) {
		std::cerr << EXCEPTION_COLOR << e.what() << RESET << std::endl;
		printTestResult("Increment grade beyond limit", true);
	}
	std::cout << SEPARATOR_COLOR << "-----------------------------" << RESET << std::endl;

	try {
		Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade(); // This should throw an exception
		printTestResult("Decrement grade beyond limit", false);
	} catch (const std::exception& e) {
		std::cerr << EXCEPTION_COLOR << e.what() << RESET << std::endl;
		printTestResult("Decrement grade beyond limit", true);
	}
	std::cout << SEPARATOR_COLOR << "-----------------------------" << RESET << std::endl;

	try {
		Bureaucrat b3("Charlie", 0); // This should throw an exception
		printTestResult("Initialize with invalid high grade", false);
	} catch (const std::exception& e) {
		std::cerr << EXCEPTION_COLOR << e.what() << RESET << std::endl;
		printTestResult("Initialize with invalid high grade", true);
	}
	std::cout << SEPARATOR_COLOR << "-----------------------------" << RESET << std::endl;

	try {
		Bureaucrat b4("David", 151); // This should throw an exception
		printTestResult("Initialize with invalid low grade", false);
	} catch (const std::exception& e) {
		std::cerr << EXCEPTION_COLOR << e.what() << RESET << std::endl;
		printTestResult("Initialize with invalid low grade", true);
	}
	std::cout << SEPARATOR_COLOR << "-----------------------------" << RESET << std::endl;

	// New test where everything works correctly
	printTestHeader("Testing Bureaucrat Grade Adjustments");

	try {
		Bureaucrat b5("Eve", 75);
		std::cout << b5 << std::endl;

		// Increment grade 5 times
		for (int i = 0; i < 5; ++i) {
			b5.incrementGrade();
			std::cout << b5 << std::endl;
		}

		// Decrement grade 5 times
		for (int i = 0; i < 5; ++i) {
			b5.decrementGrade();
			std::cout << b5 << std::endl;
		}

		printTestResult("Grade adjustment operations", true);
	} catch (const std::exception& e) {
		std::cerr << EXCEPTION_COLOR << e.what() << RESET << std::endl;
		printTestResult("Grade adjustment operations", false);
	}

	printTestFooter();
}

void testForm() {
	printTestHeader("Testing Form");

	try {
		Bureaucrat b1("Alice", 2);
		Form f1("Form1", 3, 5);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		printTestResult("Form signing", true);
	} catch (const std::exception& e) {
		std::cerr << EXCEPTION_COLOR << e.what() << RESET << std::endl;
		printTestResult("Form signing", false);
	}

	std::cout << SEPARATOR_COLOR << "-----------------------------" << RESET << std::endl;

	try {
		Bureaucrat b2("Bob", 5);
		Form f2("Form2", 3, 5);
		std::cout << f2 << std::endl;
		b2.signForm(f2); // This should throw an exception
		printTestResult("Form signing with low grade", false);
	} catch (const std::exception& e) {
		std::cerr << EXCEPTION_COLOR << e.what() << RESET << std::endl;
		printTestResult("Form signing with low grade", true);
	}

	printTestFooter();
}

int main() {
	testBureaucrat();
	testForm();
	return 0;
}