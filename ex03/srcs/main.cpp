/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:27:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/26 11:12:25 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat Gilbert("Gilbert", 1);
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf->beSigned(Gilbert);
	rrf->execute(Gilbert);
	delete(rrf);
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	rrf->beSigned(Gilbert);
	rrf->execute(Gilbert);
	delete(rrf);
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	rrf->beSigned(Gilbert);
	rrf->execute(Gilbert);
	delete(rrf);
	rrf = someRandomIntern.makeForm("babibou", "Bender");
	return (0);
}