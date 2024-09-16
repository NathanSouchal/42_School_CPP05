/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:17:59 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/26 09:50:33 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Blank paper"), _isSigned(false), _requiredGradeToSign(150), _requiredGradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToExecute, int gradeToSign): _name(name), _isSigned(false), _requiredGradeToSign(gradeToSign), _requiredGradeToExecute(gradeToExecute)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw Form::GradeTooHighException("Cannot create Form, grade is too high !");
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException("Cannot create Form, grade is too low !");
	std::cout << "Form specific attributes constructor called" << std::endl;
}

Form::Form(const Form &src): _name(src._name), _requiredGradeToSign(src._requiredGradeToSign), _requiredGradeToExecute(src._requiredGradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	this->_isSigned = rhs._isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int		Form::getRequiredGradeToExecute() const
{
	return (_requiredGradeToExecute);
}

int		Form::getRequiredGradeToSign() const
{
	return (_requiredGradeToSign);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _requiredGradeToSign)
		_isSigned = true;
	else
		throw Form::GradeTooLowException("Cannot sign form, grade is too low");
}

void	Form::signing()
{
	_isSigned = true;
}

Form::GradeTooLowException::GradeTooLowException(std::string message): _message(message) {}

const char	*Form::GradeTooLowException::what() const throw()
{
	return (_message.c_str());
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooHighException::GradeTooHighException(std::string message): _message(message) {}

const char	*Form::GradeTooHighException::what() const throw()
{
	return (_message.c_str());
}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

std::ostream	&operator<<(std::ostream &o, const Form &form)
{
	o << "Form " << form.getName() << ": is signed = " << form.getIsSigned() \
	<< " | required grade to sign = " << form.getRequiredGradeToSign() \
	<< " | required grade to execute = " << form.getRequiredGradeToExecute();
	return (o);
}
