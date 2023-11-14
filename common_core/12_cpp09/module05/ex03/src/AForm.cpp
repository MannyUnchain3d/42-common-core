/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:04:01 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/10 18:53:59 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Parameter Constructor */
AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

/* Copy Constructor */
AForm::AForm(AForm const& rhs): _name(rhs.getName()), _gradeToSign(rhs.getGradeToSign()),
							  _gradeToExecute(rhs.getGradeToExecute()), _isSigned(rhs.getIsSigned()) {
}

/* ----- DESTRUCTOR ------------------- */

AForm::~AForm(void) {}

/* ----- OPERATOR OVERLOAD ------------ */

AForm& AForm::operator=(AForm const& rhs) {
	if (this != &rhs)
		_isSigned = rhs.getIsSigned();
	return (*this);
}

/* ----- GETTER ----------------------- */

std::string const&	AForm::getName(void) const {
	return (_name);
}

int	AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}

int	AForm::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

bool	AForm::getIsSigned(void) const {
	return (_isSigned);
}


/* ----- PUBLIC METHOD ---------------- */

void AForm::beSigned(Bureaucrat const& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

/* ----- OPERATOR OVERLOAD ------------- */

std::ostream& operator<<(std::ostream& os, AForm const& rhs) {
	os << "#---------- FORM INFO ----------#" << std::endl;
	os << "AForm name: " << rhs.getName() << std::endl;
	os << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	os << "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
	os << "Signed: " << (rhs.getIsSigned() ? "Yes" : "No") << std::endl;
	return (os);
}
