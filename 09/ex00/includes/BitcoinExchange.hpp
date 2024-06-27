/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:06:57 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/22 18:05:39 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <map>
# include <algorithm>

# define INPUT 1
# define RATES 2

class BitcoinExchange
{
private:
	std::map<std::string, float>	_exchangeRates;

//-----PRIVATE ORTHODOX CANONICAL FORM-----
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator = (const BitcoinExchange &other);

//-----FUNCTIONS-----
	void	_getDataBase( void );
	void	_extractDataBase( std::ifstream& file );
	void	_getInputData( std::ifstream& file );
	void	_trim( std::string& str );
	void	_verifyHeader( std::string& header, int type );
	void	_verifyLine( std::string& line, std::string& date, float& value, int type );
	float	_getValue( std::string &str, std::string &line );
	bool	_verifyDate( std::string& date );
	bool	_verifyDateFormat( std::string& date );
	void	_getDate( std::string& date, int& year, int &month, int& day);
	bool	_verifyYear( int& year );
	bool	_verifyMonth( int& month );
	bool	_verifyDay( int& day, int& month, int& year );
	void	_verifyValueRange( float& value, std::string &line );
	float	_getRates( std::string date );

public:
//-----PUBLIC ORTHODOX CANONICAL FORM-----
	BitcoinExchange();
	~BitcoinExchange();

//-----EXCEPTIONS-----
	class DataBaseFileNotOpenException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DataBaseFileEmptyException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InputFileNotOpenException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InputFileEmptyException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InvalidDataBaseException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class BadInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class BadDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class BadValueException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class UnderValueException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class AboveValueException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DateNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

//-----FUNCIONS-----
		void	readInput( std::string fileName );
};

void	errorMsg(std::string error);

// Color codes as global variables
const std::string RESET = "\033[0m";
const std::string RED = "\033[31;1m";
const std::string GREEN = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE = "\033[34;1m";
const std::string PURPLE = "\033[35;1m";
const std::string CYAN = "\033[36;1m";
const std::string GRAY = "\033[37;1m";

#endif