/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:30:27 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/27 12:40:56 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Sed.hpp"
#include <cstddef>
#include <fstream>
#include <string>

Sed::Sed(){}
Sed::~Sed(){}

int	Sed::sed(int argc, char *argv[])
{	
	if (argc != 4)
	{
		std::cout << "Expected: ./sed <filename> <strOld> <strNew>" 
				  << std::endl;
		return -1;
	}
	_file = std::string(argv[1]);
	if (Sed::openFile() < 0)
		return -1;
	if (Sed::createFile() < 0)
		return -1;
	_strOld = argv[2];
	_strNew = argv[3];
	replace();
	return 0;
}

int	Sed::openFile()
{
	std::ifstream	file;

	file.open(_file.c_str());
	if (!file.is_open())
	{
		std::cout << "Couldn't open the file" << std::endl;
		return -1;
	}
	file.peek();
	if (file.eof())
	{
		std::cout << "Loaded an empty file!" << std::endl;
		file.close();
		return -1;
	}
	return 0;
}

int	Sed::createFile()
{
	std::string		fileReplace;

	fileReplace = _file + ".replace";
	std::ofstream myFile (fileReplace.c_str()); //may be fileReplace.c_str() and may need traits
	if (!myFile.is_open())
	{
		std::cout << "Coudn't create the '" << _file << ".replace' " << std::endl;
		myFile.close();
		return -1;
	}
	return 0;
}

void	Sed::replaceStr(std::string &str)
{
	size_t	add;

	add = str.find(_strOld);
	while (add != std::string::npos)
	{
		std::cout << add + '0' << std::endl;
	
		str.erase(add, _strOld.size());
		str.insert(add, _strNew);
		add += _strNew.size();
		add = str.find(_strOld, add);
	}
}

void	Sed::replace()
{
	std::string		str;
	std::ifstream	file;
	std::ofstream	replace;

	file.open(_file.c_str());
	replace.open((_file+ ".replace").c_str()) ;
	while (std::getline(file, str))
	{
		replaceStr(str);
		replace << str << "\n";
	}
	file.close();
	replace.close();
}