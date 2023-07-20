/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:26:47 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 05:34:24 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"
#include "colors.h"

int	main(void) {
	DiamondTrap	diamond1("Sagat");
	DiamondTrap	diamond2(diamond1);
	
	std::cout << std::endl;
	
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;
	diamond1.whoAmI();
	diamond1.attack("Bison");
	diamond1.takeDamage(8);
	diamond1.beRepaired(10);
	diamond1.highFivesGuys();
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;

	std::cout << std::endl;

	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;
	diamond2.whoAmI();
	diamond2.takeDamage(69);
	diamond2.beRepaired(100000000);
	diamond2.highFivesGuys();
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;

	std::cout << std::endl;

	return (0);
}