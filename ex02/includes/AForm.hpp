/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:19:58 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/22 11:12:44 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
	const std::string	_name;
	bool				_isSigned;
	const int			_requiredGradeToSign;
	const int			_requiredGradeToExecute;

	public:
	AForm();
	AForm(std::string name, int gradeToExecute, int gradeToSign);
	AForm(const AForm &src);
	AForm &operator=(const AForm &rhs);
	virtual ~AForm();
	std::string	getName() const;
	bool	getIsSigned() const;
	int		getRequiredGradeToSign() const;
	int		getRequiredGradeToExecute() const;
	void	beSigned(Bureaucrat &bureaucrat);
	void	signing();
	void	execute(const Bureaucrat &executor) const;
	virtual void	executeSpecificForm(const Bureaucrat &executor) const = 0;
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
	class FormNotSignedException : public std::exception
	{
		public:
		explicit FormNotSignedException();
		const char	*what() const throw();
		virtual ~FormNotSignedException() throw();
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &bureaucrat);

#endif
