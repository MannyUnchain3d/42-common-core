/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:06:38 by Manny             #+#    #+#             */
/*   Updated: 2023/11/10 21:16:44 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* Parameter Constructor */
PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

/* Copy Constructor */
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& rhs) :
	AForm(rhs), _target(rhs._target){
}

/* ----- DESTRUCTOR ------------------- */

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

/* ----- OPERATOR OVERLOAD ------------ */

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {
	(void)rhs;
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
