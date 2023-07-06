/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:07:08 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/07 00:23:48 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string colorZombie(std::string const color, std::string const name) {
	return (color + name + NC);
}

int	main(void) {
	std::string	name;
	
	std::cout << std::endl << RED << "Creating a zombie on the heap" << NC << std::endl << std::endl;
	std::cout << "Enter a name for the zombie: " << std::flush;
	std::cin >> name;

	Zombie* heapZombie = newZombie(colorZombie(RED, name));
	heapZombie->announce();
	delete heapZombie;

	std::cout << std::endl << YELLOW << "Creating a random zombie on the stack" << NC << std::endl << std::endl;
	randomChump(colorZombie(YELLOW, "Randy"));
	return (0);
}