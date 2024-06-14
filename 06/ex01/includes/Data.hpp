/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:41:47 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/13 17:59:33 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

// Color codes as global variables
const std::string RESET = "\033[0m";
const std::string RED = "\033[31;1m";
const std::string GREEN = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE = "\033[34;1m";
const std::string PURPLE = "\033[35;1m";
const std::string CYAN = "\033[36;1m";
const std::string GRAY = "\033[37;1m";

class Data
{
private:
		int			_index;
		std::string	_name;

public:
//-----ORTODOX CANONICAL FORM-----
		Data( void );
		Data( int index, std::string name );
		Data( Data const &copy );
		~Data( void );
		Data& operator=( Data const &other );

//-----GETTERS-----
		int			getIndex(void) const;
		std::string	getName(void) const;

//-----SETTERS-----
		void		setIndex(int index);
		void		setName(std::string name);
};

//-----OTHER OPERATORS-----
std::ostream& operator << (std::ostream& out, Data const &data);

#endif