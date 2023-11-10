/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:04:01 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/10 18:53:59 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Parameter Constructor */
Form::Form(std::string const& name, int gradeToSign, int gradeToExecute) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

/* Copy Constructor */
Form::Form(Form const& rhs): _name(rhs.getName()), _gradeToSign(rhs.getGradeToSign()),
							  _gradeToExecute(rhs.getGradeToExecute()), _isSigned(rhs.getIsSigned()) {
}

/* ----- DESTRUCTOR ------------------- */

Form::~Form(void) {}

/* ----- OPERATOR OVERLOAD ------------ */

Form& Form::operator=(Form const& rhs) {
	if (this != &rhs)
		_isSigned = rhs.getIsSigned();
	return (*this);
}

/* ----- GETTER ----------------------- */

std::string const&	Form::getName(void) const {
	return (_name);
}

int	Form::getGradeToSign(void) const {
	return (_gradeToSign);
}

int	Form::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

bool	Form::getIsSigned(void) const {
	return (_isSigned);
}


/* ----- PUBLIC METHOD ---------------- */

void Form::beSigned(Bureaucrat const& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

/* ----- OPERATOR OVERLOAD ------------- */

std::ostream& operator<<(std::ostream& os, Form const& rhs) {
	os << "#---------- FORM INFO ----------#" << std::endl;
	os << "Form name: " << rhs.getName() << std::endl;
	os << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	os << "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
	os << "Signed: " << (rhs.getIsSigned() ? "Yes" : "No") << std::endl;
	return (os);
}
