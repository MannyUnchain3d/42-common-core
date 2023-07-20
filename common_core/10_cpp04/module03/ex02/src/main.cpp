/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:40:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 06:00:05 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "colors.h"

int	main(void) {
	FragTrap	frag1("Chung Li");
	FragTrap	frag2(frag1);
	
	std::cout << std::endl;
	
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;
	frag1.attack("Bison");
	frag1.takeDamage(8);
	frag1.beRepaired(5);
	frag1.highFivesGuys();
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;

	std::cout << std::endl;

	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;
	frag2.takeDamage(100);
	frag2.beRepaired(5);
	frag2.highFivesGuys();
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;

	std::cout << std::endl;

	return (0);
}