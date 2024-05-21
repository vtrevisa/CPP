/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:30:22 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/05/20 19:04:36 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
#define UTIL_HPP

class Utils
{
	public:
	
	Utils();
	~Utils();
	
	bool	running;

	void	showMenu(void);
	void	headerDisplay(void);
	void	bodyDisplay(std::string firstName, std::string lastName, std::string nickName, int index);
	bool	getCommand(std::string msg, std::string &value, bool (*validate) (std::string));
	void	singleContact(std::string setData[]);
};

#endif