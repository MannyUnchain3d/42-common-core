/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:40:41 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/10 20:53:29 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Bureaucrat::Bureaucrat(void) {
}

/* Parameter Constructor */
Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

/* Copy Constructor */
Bureaucrat::Bureaucrat(Bureaucrat const& rhs) : _name(rhs._name), _grade(rhs._grade) {
}

/* ----- DESTRUCTOR ------------------- */

Bureaucrat::~Bureaucrat(void) {
}

/* ----- OPERATOR OVERLOAD ------------ */

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
	if (this != &rhs)
		_grade = rhs.getGrade();
	return (*this);
}

/* ----- GETTER ----------------------- */

std::string const&	Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

/* ----- PUBLIC METHOD ---------------- */

void	Bureaucrat::incrementGrade(void) {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

/* ----- OPERATOR --------------------- */

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs) {
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (os);
}