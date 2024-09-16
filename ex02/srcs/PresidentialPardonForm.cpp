/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:28:46 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/22 13:32:14 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 5, 25), _target("default target")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 5, 25), _target(target)
{
	std::cout << "PresidentialPardonForm specific target constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::executeSpecificForm(const Bureaucrat &executor) const
{
	std::string	fileName;

	if (executor.getGrade() <= getRequiredGradeToExecute())
	{
		if (getIsSigned())
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		else
			throw AForm::FormNotSignedException();
	}
	else
		throw AForm::GradeTooLowException("Cannot execute, grade is too low");
}