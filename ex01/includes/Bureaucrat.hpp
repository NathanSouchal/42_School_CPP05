/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:25:18 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/26 09:42:41 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <cstring>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
	const std::string	_name;
	int					_grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();
	int			getGrade() const;
	std::string	getName() const;
	void		incrementGrade();
	void		decrementGrade();
	void		signForm(Form &form);
	class GradeTooLowException : public std::exception
	{
		private:
		std::string	_message;

		public:
		explicit GradeTooLowException(std::string message);
		const char	*what() const throw();
		virtual ~GradeTooLowException() throw();
	};
	class GradeTooHighException : public std::exception
	{
		private:
		std::string	_message;

		public:
		explicit GradeTooHighException(std::string message);
		const char	*what() const throw();
		virtual ~GradeTooHighException() throw();
	};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif