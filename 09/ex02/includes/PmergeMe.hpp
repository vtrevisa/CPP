/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:08:43 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/26 19:43:13 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>

class PmergeMe
{
public:
	//-----ORTHODOX CANONICAL FORM-----
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	~PmergeMe();

	// MERGE INSERT FUNCTION
	void mergeInsert(int argc, char* argv[]);

private:
	// SORTING METHODS
	void sort(std::vector<int> &vec) const;
	void sort(std::deque<int> &deq) const;

	// DISPLAY METHODS
	void displayBefore(const std::vector<int> &vec) const;
	void displayAfter(const std::vector<int> &vec) const;
	void displayTime(double time, const std::string &containerName) const;

	// PRIVATE SORTING METHODS
	void mergeInsertSort(std::vector<int> &vec, int left, int right) const;
	void mergeInsertSort(std::deque<int> &deq, int left, int right) const;
	void merge(std::vector<int> &vec, int left, int mid, int right) const;
	void merge(std::deque<int> &deq, int left, int mid, int right) const;
};

#endif