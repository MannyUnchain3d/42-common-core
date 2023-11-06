/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:47:04 by Manny             #+#    #+#             */
/*   Updated: 2023/11/05 00:56:46 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		for (int i = 145; i < 151; i++) {
			Bureaucrat bureaucrat("Alfred", i);
			std::cout << bureaucrat << std::endl;
			bureaucrat.decrementGrade();
		}
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		for (int i = 5; i > 0; i--) {
			Bureaucrat bureaucrat("Robin", i);
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade();
		}
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
