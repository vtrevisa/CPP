/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:42:20 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/22 18:07:49 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/BitcoinExchange.hpp"

//#define DEBUG
//-----FUNCTIONS-----
void	BitcoinExchange::_getDataBase()
{
	std::ifstream	file("data.csv");
	if (!file.is_open())
		throw DataBaseFileNotOpenException();
	file.peek();
	if (file.eof())
	{
		file.close();
		throw DataBaseFileEmptyException();
	}
	_extractDataBase(file);
}

void	BitcoinExchange::_extractDataBase(std::ifstream& file)
{
	std::string	rate, line, date;

	std::getline(file, line);
	_trim(line);
	_verifyHeader(line, RATES);
	while (std::getline(file, line))
	{
		_trim(line);
		date = line.substr(0, line.find(','));
		rate = line.substr(line.find(',') + 1);
		_trim(date);
		_exchangeRates[date] = _getValue(rate, line);
	}
}

void	BitcoinExchange::readInput(std::string fileName)
{
	std::ifstream	file(fileName.c_str());

	if (!file.is_open())
		throw InputFileNotOpenException();
	file.peek();
	if (file.eof())
	{
		file.close();
		throw InputFileEmptyException();
	}
	_getInputData(file);
}

void	BitcoinExchange::_getInputData(std::ifstream &file)
{
	std::string	line, date;
	float		value;

	std::getline(file, line);
	_trim(line);
	_verifyHeader(line, INPUT);
	while (std::getline(file, line))
	{
		try
		{
		_trim(line);
		_verifyLine(line, date, value, INPUT);
		std::cout << date << " | " << value;
		std::cout << " => "<< value * _getRates(date) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			continue ;
		}
	}
}

void	BitcoinExchange::_trim(std::string &str)
{
	str.erase(0, str.find_first_not_of(" \t\r\n"));
	str.erase(str.find_last_not_of(" \t\r\n") + 1);
}

void	BitcoinExchange::_verifyHeader(std::string &header, int type)
{
	std::istringstream	ss(header);
	std::string			date, value;
	std::string			standard = (type == INPUT ) ? "value" : "exchange_rate";
	char				d = (type == INPUT) ? '|' : ',';
	
	if (std::getline(ss, date, d) && std::getline(ss, value))
	{
		_trim(date);
		_trim(value);
		if (!date.length() || !value.length() || date != "date" || value != standard)
		{
			if (type == RATES)
				throw InvalidDataBaseException();
			else
				throw InvalidInputException();
		}
	}
	if (type == INPUT)
	{
		std::cout	<< date << std::setw(8) << std::right << d
					<< std::setw(6) << std::right << value
					<< std::endl;
	}
	
}

void	BitcoinExchange::_verifyLine(std::string& line, std::string& date, float& value, int type)
{
	char	d = (type == INPUT) ? '|' : ',';
	size_t	pos = line.find(d);

	if (pos == std::string::npos || pos == 0 || pos == line.length() - 1)
	{
		std::cout << line;
		throw BadInputException();
	}

	date = line.substr(0, pos);
	std::string str = line.substr(pos + 1);
	value = _getValue(str, line);
	_trim(date);
	if (!_verifyDate(date))
	{
		std::cout << line;
		throw BadDateException();
	}
	_verifyValueRange(value, line);	
}

float	BitcoinExchange::_getValue(std::string &str, std::string &line)
{
	float	value;
	
	_trim(str);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]) && str[i] != '.')
		{
			std::cout << line;
			throw BadValueException();
		}
	}
	std::istringstream	iss(str);
	iss >> value;
	return value;
}

bool	BitcoinExchange::_verifyDate(std::string &date)
{
	int	year, month, day;

	if (!_verifyDateFormat(date))
		return false;
	_getDate(date, year, month, day);
	if (!_verifyYear(year) || !_verifyMonth(month) ||
					!_verifyDay(day, month, year))
		return false;
	return true;
}

bool BitcoinExchange::_verifyDateFormat(std::string& date)
{
	if (date.length() != 10)
		return (false);
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return false;
		}
		else if (!std::isdigit(date[i]))
			return false;
	}
	return true;
}

void	BitcoinExchange::_getDate(std::string &date, int &year, int &month, int &day)
{
	std::istringstream	iss(date);
	std::string			yearStr, monthStr, dayStr;

	std::getline(iss, yearStr, '-');
	std::getline(iss, monthStr, '-');
	std::getline(iss, dayStr);

	std::istringstream(yearStr) >> year;
	std::istringstream(monthStr) >> month;
	std::istringstream(dayStr) >> day;
}

bool BitcoinExchange::_verifyYear(int& year)
{
	return year >= 1 && year <= 9999;
}

bool BitcoinExchange::_verifyMonth(int& month)
{
	return month >= 1 && month <= 12;
}

bool BitcoinExchange::_verifyDay(int& day, int& month, int& year)
{
	int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysMonth[1] = 29;
	return day >= 1 && day <= daysMonth[month - 1];
}

void BitcoinExchange::_verifyValueRange(float& value, std::string &line)
{
	if (value < 0)
	{
		std::cout << line << RESET;
		throw UnderValueException();
	}
	if (value > 1000)
	{
		std::cout << line << RESET;
		throw AboveValueException();
	}
}

float BitcoinExchange::_getRates(std::string date)
{
	std::map<std::string, float>::iterator	it = _exchangeRates.find(date);
	
	if (it != _exchangeRates.end())
		return it->second;
	it =_exchangeRates.lower_bound(date);
	if (it != _exchangeRates.begin())
	{
		--it;
		return it->second;
	}
	throw DateNotFoundException();
}

//-----ORTHODOX CANONICAL FORM-----
BitcoinExchange::BitcoinExchange()
{
	#ifdef DEBUG
	std::cout << "BitcoinExchange constructor called!" << std::endl;
	#endif
	_getDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	#ifdef DEBUG
	std::cout << "BitcoinExchange copy constructor called!" << std::endl;
	#endif
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
	#ifdef DEBUG
	std::cout << "BitcoinExchange destructor called!" << std::endl;
	#endif
}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange &other)
{
	#ifdef DEBUG
	std::cout << "BitcoinExchange assignment operator overload called!" << std::endl;
	#endif
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

//-----EXCEPTIONS-----
const char *BitcoinExchange::DataBaseFileEmptyException::what() const throw()
{
	return "Data base file is empty!";
}

const char *BitcoinExchange::DataBaseFileNotOpenException::what() const throw()
{
	return "Couldn't open data base file!";
}

const char *BitcoinExchange::InputFileEmptyException::what() const throw()
{
	return "Input file is empty!";
}

const char *BitcoinExchange::InputFileNotOpenException::what() const throw()
{
	return "Couldn't open input file!";
}

const char *BitcoinExchange::InvalidDataBaseException::what() const throw()
{
	return "Data Base file format is invalid!";
}

const char *BitcoinExchange::InvalidInputException::what() const throw()
{
	return "Input file format is invalid!";
}

const char *BitcoinExchange::BadInputException::what() const throw()
{
	return " <= bad input";
}

const char *BitcoinExchange::BadDateException::what() const throw()
{
	return " <= invalid date format";
}

const char *BitcoinExchange::BadValueException::what() const throw()
{
	return " <= invalid value";
}

const char *BitcoinExchange::UnderValueException::what() const throw()
{
	return " <= not a positive number";
}

const char *BitcoinExchange::AboveValueException::what() const throw()
{
	return " <= too large a number";
}

const char *BitcoinExchange::DateNotFoundException::what() const throw()
{
	return "date not found";
}

void	errorMsg(std::string error)
{
	std::cerr << "Error: " << error << std::endl;
}