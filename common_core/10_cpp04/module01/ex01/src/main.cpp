/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:07:08 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/09 02:10:27 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <limits>
#include <sstream>

Zombie *zombieHorde( int N, std::string name );

std::string colorZombie(std::string const color, std::string const name) {
	return (color + name + NC);
}

int	getNbZombies(void) {
	int		nb;
	bool	isValidInput = false;

	std::cout << "How many zombies do you want Master? " << std::endl << "> ";
	std::string input;
	while (!isValidInput) {
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		std::stringstream ss(input);
		if (ss >> nb && !(ss >> input) && nb >= MIN_ZOMBIES && nb <= MAX_ZOMBIES)
			isValidInput = true;
		else {
			std::cout << "Please choose between " << MIN_ZOMBIES << " and " << MAX_ZOMBIES;
			std::cout << " Master..." << std::endl << "> ";
		}
	}
	return (nb);
}

std::string	getHordeName(void) {
	std::string	name;
	
	std::cout << "What is the name of this horde Master? " << std::endl << "> ";
	std::getline(std::cin, name);
	if (std::cin.eof()) {
		return (std::string());
	}
	if (name.empty()) {
		std::cout << "I will choose Randy then..." << std::endl;
		name = "Randy";
	}
	return (name);
}

int	main(void) {
	int	nb = getNbZombies();
	if (nb == 0) {
		std::cout << "The dead won't rise today Master..." << std::endl;
		return (1);
	}
	std::string	name = getHordeName();
	if (name.empty()) {
		std::cout << "The dead won't rise today Master..." << std::endl;
		return (1);
	}
	std::cout << GREEN << "Raising the horde " << colorZombie(RED, name);
	std::cout << " with " << nb << " zombie(s)!" << NC << std::endl;

	Zombie*	horde = zombieHorde(nb, colorZombie(RED, name));
	if (horde == NULL) {
		std::cout << "The dead won't rise today Master..." << std::endl;
		return (1);
	}
	std::cout << GREEN << "Behold the night of the living dead!" << NC << std::endl;
	for (int i = 0; i < nb; i++) 
		horde[i].announce();
	std::cout << GREEN << "The horde is dead, long live the horde!" << NC << std::endl;
	delete [] horde;
	return (0);
}