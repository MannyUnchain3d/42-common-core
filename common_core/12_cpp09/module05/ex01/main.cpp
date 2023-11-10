/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:47:04 by Manny             #+#    #+#             */
/*   Updated: 2023/11/10 19:28:40 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> // needed only on linux for EXIT_SUCCESS
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	try {
		Bureaucrat bureaucrat("Alfred", 10);
		Form form("Holyday Request", 10, 1);
			
		bureaucrat.signForm(form);
		std::cout << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}
