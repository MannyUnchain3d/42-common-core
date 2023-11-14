/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:32:15 by Manny             #+#    #+#             */
/*   Updated: 2023/11/13 21:37:10 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Parameter Constructor */
RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
	AForm("Robotomy Request Form", 72, 45), _target(target) {
}

/* Copy Constructor */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& rhs) :
	AForm(rhs), _target(rhs._target){
}

/* ----- DESTRUCTOR ------------------- */

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

/* ----- OPERATOR OVERLOAD ------------ */

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
	(void)rhs;
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	static int	i;
	if (i % 2 == 0)
		std::cout << "Bzzzzzz! " << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
	i++;
}
