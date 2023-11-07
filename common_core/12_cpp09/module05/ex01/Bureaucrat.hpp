/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:42:22 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/07 21:24:14 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(Bureaucrat const& rhs);
		~Bureaucrat(void);

		Bureaucrat& operator=(Bureaucrat const& rhs);

		std::string const&	getName(void) const;
		int					getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form& form);

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
		int 				_grade;

		Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs);

#endif
