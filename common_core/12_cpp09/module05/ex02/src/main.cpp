/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:56:26 by Manny             #+#    #+#             */
/*   Updated: 2023/11/13 20:31:36 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <cstdlib> // needed only on linux for EXIT_SUCCESS
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	try {
		Bureaucrat bureaucrat("Alfred", 10);
		PresidentialPardonForm form("President");
		RobotomyRequestForm form2("Robot");
		ShrubberyCreationForm form3("Shrubbery");
	
		std::cout << YELLOW << "# ---------- Form 1 (PresidentialPardonForm) ---------- #" << NC << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		std::cout << std::endl;
		std::cout << YELLOW << "# ---------- Form 2 (Robotomy) ---------- #" << NC << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
		std::cout << std::endl;
		std::cout << YELLOW << "# ---------- Form 3 (Shrubbery) ---------- #" << NC << std::endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}
