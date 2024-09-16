/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:27:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/21 11:33:09 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Fredrisch("Fredrisch", 50);
	Bureaucrat Heinrisch("Heinrisch", 49);
	Form blankPaper;
	std::cout << blankPaper << std::endl;
	Form unPostiche("un postiche", 49, 49);
	std::cout << unPostiche << std::endl;
	try
	{
		blankPaper.beSigned(Fredrisch);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		unPostiche.beSigned(Fredrisch);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << blankPaper << std::endl;
	std::cout << unPostiche << std::endl;
	Heinrisch.signForm(unPostiche);
	std::cout << unPostiche << std::endl;
	Heinrisch.signForm(blankPaper);
	return (0);
}