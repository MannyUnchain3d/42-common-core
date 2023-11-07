/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:42:13 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/07 21:29:03 by etetopat         ###   ########.fr       */
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
	// Make your Destructor here
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

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	} catch (Form::GradeTooLowException& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

/* ----- OPERATOR --------------------- */

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs) {
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (os);
}