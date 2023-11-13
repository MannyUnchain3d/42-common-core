/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:27:23 by Manny             #+#    #+#             */
/*   Updated: 2023/11/10 22:14:14 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

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
		void				signForm(AForm& form);
		void				executeForm(AForm const& form) const;

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
