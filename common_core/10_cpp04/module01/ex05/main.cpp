/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:39:30 by Manny             #+#    #+#             */
/*   Updated: 2023/07/12 02:12:54 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	std::string	input;
	Harl		harl;

	std::cout << "Type: \"DEBUG\", \"INFO\", \"WARNING\", ",
	std::cout << "\"ERROR\" or \"EXIT\"" << std::endl;

	do {
		std::cout << "Enter a level: ";
		if (!std::getline(std::cin, input))
			break ;
		harl.complain(input);
	} while (input.compare("EXIT"));
	return (0);
}