/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:41:21 by Manny             #+#    #+#             */
/*   Updated: 2023/11/10 20:43:24 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(std::string const& name, int gradeToSign, int gradeToExecute);
		AForm(AForm const& rhs);
		virtual ~AForm(void);

		AForm& operator=(AForm const& rhs);

		std::string const&	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getIsSigned(void) const;

		void				beSigned(Bureaucrat const& bureaucrat);
		virtual void		execute(Bureaucrat const& executor) const = 0;
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too low"; }
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Form is not signed"; }
		};

	private:
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		bool				_isSigned;

		AForm(void);
};

std::ostream& operator<<(std::ostream& os, AForm const& rhs);

#endif
