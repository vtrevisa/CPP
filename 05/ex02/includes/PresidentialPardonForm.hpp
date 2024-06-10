/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:18:35 by vtrevisa          #+#    #+#             */
/*   Updated: 2024/06/07 20:40:30 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;

public:
//-----ORTODOX CANONICAL FORM-----
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &copy);
	PresidentialPardonForm& operator = (PresidentialPardonForm const &other);
	virtual ~PresidentialPardonForm( void );

//-----FUNCTIONS-----
	void	execute(Bureaucrat const &b) const;
};

#endif