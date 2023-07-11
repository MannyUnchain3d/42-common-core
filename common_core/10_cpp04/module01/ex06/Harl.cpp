/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:35:51 by Manny             #+#    #+#             */
/*   Updated: 2023/07/12 03:20:09 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	std::cout << GREEN << "Harl is born." << NC << std::endl << std::endl;
}

Harl::~Harl(void) {
	std::cout << std::endl << RED << "Harl is dead." << NC << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	switch (i) {
		case 0:
			this->debug();
		//Intentional fallthrough
		case 1:
			this->info();
		//Intentional fallthrough
		case 2:
			this->warning();
		//Intentional fallthrough
		case 3:
			this->error();
			break ;
			
		default:
			std::cout << YELLOW << "[ Probably complaining about insignificant problems ]" << NC << std::endl;
	}
}

void	Harl::debug(void) {
	std::cout << YELLOW << "I love having extra vegan bacon in my burger!" << NC << std::endl;
}

void	Harl::info(void) {
	std::cout << YELLOW << "You didn’t put enough vegan bacon in my burger!" << NC << std::endl;
}

void	Harl::warning(void) {
	std::cout << YELLOW << "I deserve to have some extra vegan bacon for free!" << NC << std::endl;
}

void	Harl::error(void) {
	std::cout << YELLOW << "This is unacceptable! I want to speak to the manager now!" << NC << std::endl;
}