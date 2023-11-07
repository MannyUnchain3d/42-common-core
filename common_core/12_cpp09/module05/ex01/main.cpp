/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:47:04 by Manny             #+#    #+#             */
/*   Updated: 2023/11/07 21:27:12 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	try {
		Bureaucrat bureaucrat("Alfred", 11);
		Form form("Holyday Request", 10);
			
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}
