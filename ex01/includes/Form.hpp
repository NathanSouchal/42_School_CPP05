/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:19:58 by nsouchal          #+#    #+#             */
/*   Updated: 2024/08/21 11:36:36 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
	const std::string	_name;
	bool				_isSigned;
	const int			_requiredGradeToSign;
	const int			_requiredGradeToExecute;

	public:
	Form();
	Form(std::string name, int gradeToExecute, int gradeToSign);
	Form(const Form &src);
	Form &operator=(const Form &rhs);
	~Form();
	std::string	getName() const;
	bool	getIsSigned() const;
	int		getRequiredGradeToSign() const;
	int		getRequiredGradeToExecute() const;
	void	beSigned(Bureaucrat &bureaucrat);
	void	signing();
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

std::ostream &operator<<(std::ostream &o, const Form &bureaucrat);

#endif
