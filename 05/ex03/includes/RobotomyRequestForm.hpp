/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:18:35 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/10 15:34:18 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;

public:
//-----ORTODOX CANONICAL FORM-----
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &copy);
	RobotomyRequestForm& operator = (RobotomyRequestForm const &other);
	virtual ~RobotomyRequestForm( void );

//-----FUNCTIONS-----
	void	execute(Bureaucrat const &b) const;
};

#endif