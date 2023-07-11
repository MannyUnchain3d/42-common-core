/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 02:08:19 by Manny             #+#    #+#             */
/*   Updated: 2023/07/12 02:07:43 by Manny            ###   ########.fr       */
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
	t_func		funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4 && levels[i] != level)
		i++;
	if (i < 4)
		(this->*funcs[i])();
}

void	Harl::debug(void) {
	std::cout << YELLOW << "I love having extra bacon for my 7XL-double-cheese-triple-pickle",
	std::cout << "-special ketchup burger. I really do!" << NC << std::endl;
}

void	Harl::info(void) {
	std::cout << YELLOW << "I cannot believe adding extra bacon costs more money. ",
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << NC << std::endl;
}

void	Harl::warning(void) {
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free. ",
	std::cout << "I’ve been coming for years whereas you started working here since last month." << NC << std::endl;
}

void	Harl::error(void) {
	std::cout << YELLOW << "This is unacceptable! I want to speak to the manager now." << NC << std::endl;
}