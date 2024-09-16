/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:36:28 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/26 10:10:07 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("nobody"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Cannot create Bureaucrat, grade is too high !");
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Cannot create Bureaucrat, grade is too low !");
	std::cout << "Bureaucrat specific attributes constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src):_name(src._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException("Cannot incremente Bureaucrat's grade, it already has the highest !");
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException("Cannot decremente Bureaucrat's grade, it already has the lowest !");
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	if (_grade <= form.getRequiredGradeToSign())
	{
		if (!form.getIsSigned())
		{
			form.signing();
			std::cout << _name << " signed " << form.getName() << std::endl;
		}
		else
			std::cout << _name << " couldn't sign " << form.getName() << " because it's already signed !" << std::endl;
	}
	else
		std::cout << _name << " couldn't sign " << form.getName() << " because grade is too low !" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string message): _message(message) {}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return (_message.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string message): _message(message) {}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return (_message.c_str());
}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

void	Bureaucrat::executeForm(const AForm &form)
{
	if (_grade <= form.getRequiredGradeToExecute())
	{
		if (form.getIsSigned())
		{
			std::cout << _name << " executed " << form.getName() << std::endl;
			form.execute(*this);
		}
		else
			throw AForm::FormNotSignedException();
	}
	else
		throw Bureaucrat::GradeTooLowException("Cannot execute form, grade is too low !");
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
	o << bureaucrat.getName() << " ,bureaucrat grade " << bureaucrat.getGrade();
	return (o);
}
