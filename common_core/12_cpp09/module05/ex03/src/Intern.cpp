/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:14:46 by Manny             #+#    #+#             */
/*   Updated: 2023/11/14 13:44:31 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Intern::Intern(void) {}

/* Copy Constructor */
Intern::Intern(Intern const& rhs) {
	*this = rhs;
}

/* ----- DESTRUCTOR ------------------- */

Intern::~Intern(void) {}

/* ----- OPERATOR OVERLOAD ------------ */

Intern& Intern::operator=(Intern const& rhs) {
	(void)rhs;
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

AForm* Intern::makeForm(std::string name, std::string target) {
	std::string formNames[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm* forms[] = {
		new PresidentialPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target)
	};

	AForm* createdForm = NULL;

	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << std::endl;
			createdForm = forms[i];
		} else {
			delete forms[i];
		}
	}

	if (!createdForm) {
		std::cout << "Intern can't create " << name << " form" << std::endl;
	}

	return createdForm;
}
