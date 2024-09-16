/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:27:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/26 09:45:10 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Ronald("Ronald", 151);
		Bureaucrat Roland("Roland", 0);
		Bureaucrat Romuald("Romuald", -1);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	Bureaucrat nobody;
	std::cout << nobody << std::endl;

	Bureaucrat Robert("Robert", 100);
	std::cout << Robert << std::endl;
	Robert.decrementGrade();
	std::cout << Robert << std::endl;
	Robert.incrementGrade();
	std::cout << Robert << std::endl;

	Bureaucrat Boss("Boss", 1);
	try
	{
		Boss.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	Bureaucrat CoffeeMaker("CoffeeMaker", 150);
	try
	{
		CoffeeMaker.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}