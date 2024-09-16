/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:17:59 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/26 09:56:31 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Blank paper"), _isSigned(false), _requiredGradeToSign(150), _requiredGradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToExecute, int gradeToSign): _name(name), _isSigned(false), _requiredGradeToSign(gradeToSign), _requiredGradeToExecute(gradeToExecute)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw AForm::GradeTooHighException("Cannot create Form, grade is too high !");
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw AForm::GradeTooLowException("Cannot create Form, grade is too low !");
	std::cout << "Form specific attributes constructor called" << std::endl;
}

AForm::AForm(const AForm &src): _name(src._name), _requiredGradeToSign(src._requiredGradeToSign), _requiredGradeToExecute(src._requiredGradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

AForm &AForm::operator=(const AForm &rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	this->_isSigned = rhs._isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int		AForm::getRequiredGradeToExecute() const
{
	return (_requiredGradeToExecute);
}

int		AForm::getRequiredGradeToSign() const
{
	return (_requiredGradeToSign);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _requiredGradeToSign)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException("Cannot signe form, grade is too low");
}

void	AForm::signing()
{
	_isSigned = true;
}

AForm::GradeTooLowException::GradeTooLowException(std::string message): _message(message) {}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return (_message.c_str());
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::GradeTooHighException::GradeTooHighException(std::string message): _message(message) {}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return (_message.c_str());
}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::FormNotSignedException::FormNotSignedException() {}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Cannot execute, form is not signed");
}
AForm::FormNotSignedException::~FormNotSignedException() throw() {}

std::ostream	&operator<<(std::ostream &o, const AForm &form)
{
	o << "Form " << form.getName() << ": is signed = " << form.getIsSigned() \
	<< " | required grade to sign = " << form.getRequiredGradeToSign() \
	<< " | required grade to execute = " << form.getRequiredGradeToExecute();
	return (o);
}

void	AForm::execute(const Bureaucrat &executor) const
{
	executeSpecificForm(executor);
}
