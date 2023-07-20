/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:40:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 05:48:34 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "colors.h"

int	main(void) {
	ScavTrap	scav1("Ken");
	ScavTrap	scav2(scav1);
	
	std::cout << std::endl;
	
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;
	scav1.attack("Bison");
	scav1.takeDamage(8);
	scav1.beRepaired(5);
	scav1.guardGate();
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;

	std::cout << std::endl;

	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;
	scav2.takeDamage(100);
	scav2.beRepaired(5);
	scav2.guardGate();
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;

	std::cout << std::endl;

	return (0);
}