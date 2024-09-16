/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:36:52 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/22 14:48:33 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "AForm.hpp"

class Intern
{
	public :
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &rhs);
	~Intern();
	AForm	*makeRobForm(std::string target);
	AForm	*makePresForm(std::string target);
	AForm	*makeShrubbForm(std::string target);
	AForm	*makeForm(std::string formName, std::string target);
};

#endif