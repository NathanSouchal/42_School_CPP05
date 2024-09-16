/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:24:31 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/22 12:37:30 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 137, 145), _target("default target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 137, 145), _target(target)
{
	std::cout << "ShrubberyCreationForm specific target constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::executeSpecificForm(const Bureaucrat &executor) const
{
	std::string	fileName;

	if (executor.getGrade() <= getRequiredGradeToExecute())
	{
		if (getIsSigned())
		{
			fileName = _target + "_shrubbery";
			std::ofstream file(fileName.c_str());
			if (file.is_open())
			{
				file << "              ,@@@@@@@," << std::endl;
				file << "     ,,, .   ,@@@@@@/@@,  .oo8888o." << std::endl;
				file << "  ,&%%&%&&%,@@@@@/@@@@@@,8888/88/8o" << std::endl;
				file << "  ,%&&&&&%&&%,@@@/@@@/@@@88/88888/88'" << std::endl;
				file << "  %&&%&%&/%&&%@@@@@/ /@@@88888/88888'" << std::endl;
				file << "  %&&%/ %&%%&&@@@ V /@@' `8888 `/88'" << std::endl;
				file << "  `&%& ` /%&'    |.|        8 '|8'" << std::endl;
				file << "      |o|        | |         | |" << std::endl;
				file << "      |.|        | |         | |" << std::endl;
				file.close();
			}
			else
				std::cerr << "file unable to open" << std::endl;
		}
		else
			throw AForm::FormNotSignedException();
	}
	else
		throw AForm::GradeTooLowException("Cannot execute, grade is too low");
}
