/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:47:36 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/25 10:59:17 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{

	std::string		_file;
	std::string		_strOld;
	std::string		_strNew;
	
	int		openFile(void);
	int		createFile(void);
	void	replace(void);
	void	replaceStr(std::string &line);

	public:

	int	sed (int argc, char *argv[]);

	Sed();
	~Sed();
};
#endif