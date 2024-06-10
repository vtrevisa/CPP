/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:18:35 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 21:58:20 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;

public:
//-----ORTODOX CANONICAL FORM-----
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	ShrubberyCreationForm& operator = (ShrubberyCreationForm const &other);
	virtual ~ShrubberyCreationForm( void );

//-----FUNCTIONS-----
	void	execute(Bureaucrat const &b) const;
};

#endif