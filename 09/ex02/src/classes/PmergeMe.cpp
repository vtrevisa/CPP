/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:19:04 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/27 13:07:32 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PmergeMe.hpp"

// MERGE INSERT FUNCTION
void PmergeMe::mergeInsert(int argc, char* argv[])
{
	if (argc < 2) {
		throw std::invalid_argument("Error: No input provided");
	}

	std::vector<int> vec;
	std::deque<int> deq;

	// Populate containers with command-line arguments
	for (int i = 1; i < argc; ++i) {
		int num;
		try {
			num = std::atoi(argv[i]);
			if (num < 0) throw std::invalid_argument("Negative number");
		} catch (const std::exception &e) {
			throw std::invalid_argument("Error: Invalid input \"" + std::string(argv[i]) + "\"");
		}
		vec.push_back(num);
		deq.push_back(num);
	}

	// Display the initial unsorted sequence
	displayBefore(vec);

	// Sort using std::vector
	clock_t start = clock();
	sort(vec);
	clock_t end = clock();
	double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	// Display the sorted sequence
	displayAfter(vec);
	displayTime(vector_time, "std::vector");

	// Sort using std::deque
	start = clock();
	sort(deq);
	end = clock();
	double deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	displayTime(deque_time, "std::deque");
}

// SORTING METHODS
void PmergeMe::sort(std::vector<int> &vec) const
{
	mergeInsertSort(vec, 0, vec.size() - 1);
}

void PmergeMe::sort(std::deque<int> &deq) const
{
	mergeInsertSort(deq, 0, deq.size() - 1);
}

// DISPLAY METHODS
void PmergeMe::displayBefore(const std::vector<int> &vec) const
{
	std::cout << "BEFORE: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::displayAfter(const std::vector<int> &vec) const
{
	std::cout << "AFTER: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::displayTime(double time, const std::string &containerName) const
{
	std::cout << "TIME TO PROCESS A RANGE OF ELEMENTS WITH " << containerName << ": " << time << " us" << std::endl;
}

// PRIVATE SORTING METHODS
void PmergeMe::mergeInsertSort(std::vector<int> &vec, int left, int right) const
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeInsertSort(vec, left, mid);
		mergeInsertSort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}
}

void PmergeMe::mergeInsertSort(std::deque<int> &deq, int left, int right) const
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeInsertSort(deq, left, mid);
		mergeInsertSort(deq, mid + 1, right);
		merge(deq, left, mid, right);
	}
}

void PmergeMe::merge(std::vector<int> &vec, int left, int mid, int right) const
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = vec[left + i];
	for (int j = 0; j < n2; ++j)
		R[j] = vec[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			vec[k++] = L[i++];
		else
			vec[k++] = R[j++];
	}

	while (i < n1)
		vec[k++] = L[i++];
	while (j < n2)
		vec[k++] = R[j++];
}

void PmergeMe::merge(std::deque<int> &deq, int left, int mid, int right) const
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<int> L(n1), R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = deq[left + i];
	for (int j = 0; j < n2; ++j)
		R[j] = deq[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			deq[k++] = L[i++];
		else
			deq[k++] = R[j++];
	}

	while (i < n1)
		deq[k++] = L[i++];
	while (j < n2)
		deq[k++] = R[j++];
}

//-----ORTHODOX CANONICAL FORM-----
PmergeMe::PmergeMe()
{
#ifdef DEBUG
	std::cout << "Default constructor called" << std::endl;
#endif
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
#ifdef DEBUG
	std::cout << "Copy constructor called" << std::endl;
#endif
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
#ifdef DEBUG
	std::cout << "Assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		// Add any necessary assignments here
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
#ifdef DEBUG
	std::cout << "Destructor called" << std::endl;
#endif
}
