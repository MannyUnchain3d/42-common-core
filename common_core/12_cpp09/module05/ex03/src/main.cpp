/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:56:26 by Manny             #+#    #+#             */
/*   Updated: 2023/11/15 18:02:04 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <cstdlib> // needed only on linux for EXIT_SUCCESS
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void) {
	Intern	someRandomIntern;
	
	std::cout << YELLOW << "# ---------- Form 1 (PresidentialPardonForm) ---------- #" << NC << std::endl;
	AForm*	presidential;
	presidential = someRandomIntern.makeForm("presidential pardon", "Lincoln");
	Bureaucrat bureaucrat("Alfred", 10);
	bureaucrat.executeForm(*presidential);
	bureaucrat.signForm(*presidential);
	delete presidential;
	
	std::cout << std::endl;
	
	std::cout << YELLOW << "# ---------- Form 2 (Robotomy) ---------- #" << NC << std::endl;
	AForm*	rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Bureaucrat	bureaucrat2("Robin", 50);
	bureaucrat.signForm(*rrf);
	bureaucrat.executeForm(*rrf);
	bureaucrat.executeForm(*rrf);
	bureaucrat.executeForm(*rrf);
	bureaucrat.executeForm(*rrf);
	delete rrf;

	std::cout << std::endl;
	
	std::cout << YELLOW << "# ---------- Form 3 (Shrubbery) ---------- #" << NC << std::endl;
	AForm*	shrubbery;
	shrubbery = someRandomIntern.makeForm("shrubbery creation", "Home");
	Bureaucrat	bureaucrat3("Batman", 1);
	bureaucrat.signForm(*shrubbery);
	bureaucrat.executeForm(*shrubbery);
	delete shrubbery;
	
	std::cout << std::endl;

	std::cout << RED << "# ---------- Invalid Form ---------- #" << NC << std::endl;
	try {
		Intern	someRandomIntern2;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("invalid name", "Terminator");
		delete rrf;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
