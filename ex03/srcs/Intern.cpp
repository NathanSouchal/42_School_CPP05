/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:40:38 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/23 08:39:22 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm	*Intern::makePresForm(std::string target)
{
	AForm *formPtr = new PresidentialPardonForm(target);
	return (formPtr);
}

AForm	*Intern::makeRobForm(std::string target)
{
	AForm *formPtr = new RobotomyRequestForm(target);
	return (formPtr);
}

AForm	*Intern::makeShrubbForm(std::string target)
{
	AForm *formPtr = new ShrubberyCreationForm(target);
	return (formPtr);
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	typedef AForm* (Intern::*functionPtr)(std::string target);
	functionPtr array_f_ptr[] = {&Intern::makePresForm, &Intern::makeRobForm, &Intern::makeShrubbForm};
	std::string formNameArray[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 4; i++)
	{
		if (!formName.compare(formNameArray[i]))
		{
			std::cout << "Intern creates " << formNameArray[i] << " form" << std::endl;
			return ((this->*array_f_ptr[i])(target));
		}
	}
	std::cout << "Intern cannot create a Form that doesn't exist !" << std::endl;
	return (0);
}

