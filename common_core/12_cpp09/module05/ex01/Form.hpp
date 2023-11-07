/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:03:46 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/07 21:07:17 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(std::string const& name, int gradeToSign);
		Form(std::string const& name, int gradeToSign, int gradeToExecute);
		Form(Form const& rhs);
		~Form(void);

		Form& operator=(Form const& rhs);

		std::string const&	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getIsSigned(void) const;

		void				beSigned(Bureaucrat const& bureaucrat);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too low"; }
		};

	private:
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		bool				_isSigned;

		Form(void);
};

std::ostream& operator<<(std::ostream& os, Form const& rhs);

#endif
