/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:55:46 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/26 11:11:45 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

int robotomyCount = 0;

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 45, 72), _target("default target")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 45, 72), _target(target)
{
	std::cout << "RobotomyRequestForm specific target constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::executeSpecificForm(const Bureaucrat &executor) const
{
	std::string	fileName;

	if (executor.getGrade() <= getRequiredGradeToExecute())
	{
		if (getIsSigned())
		{
			std::cout << "*Drilling noises*" << std::endl;
			robotomyCount++;
			if (robotomyCount % 2)
				std::cout << _target << " has been robotomized !" << std::endl;
			else
				std::cout << "Robotomy has failed" << std::endl;
		}
		else
			throw AForm::FormNotSignedException();
	}
	else
		throw AForm::GradeTooLowException("Cannot execute, grade is too low");
}