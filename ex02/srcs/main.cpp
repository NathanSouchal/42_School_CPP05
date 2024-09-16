/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:27:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/26 11:12:43 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	AForm *Shrubbery = new ShrubberyCreationForm("somewhere");
	AForm *Shrubbery2 = new ShrubberyCreationForm("justHere");
	Bureaucrat Boss("boss", 10);
	Boss.signForm(*Shrubbery);
	try
	{
		Shrubbery->execute(Boss);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Boss.signForm(*Shrubbery2);
	try
	{
		Boss.executeForm(*Shrubbery2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	AForm *Robotomy = new RobotomyRequestForm("someone");
	Boss.signForm(*Robotomy);
	try
	{
		Robotomy->execute(Boss);
		Robotomy->execute(Boss);
		Robotomy->execute(Boss);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	AForm *PresidentialPardon = new PresidentialPardonForm("Trezeguet");
	Boss.signForm(*PresidentialPardon);
	try
	{
		PresidentialPardon->execute(Boss);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete (PresidentialPardon);
	delete (Shrubbery);
	delete (Shrubbery2);
	delete (Robotomy);
	return (0);
}