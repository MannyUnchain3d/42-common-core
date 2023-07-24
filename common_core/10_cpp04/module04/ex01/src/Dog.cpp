/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:56:59 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/25 05:01:20 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Dog.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Dog::Dog(void) {
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << BLUE "[Default Constructor Dog] " << NC "A wild " << this->_type << " appeared" << std::endl;
}

/* Copy Constructor */
Dog::Dog(Dog const& rhs) : Animal(rhs) {
	*this = rhs;
	std::cout << BLUE "[Copy Constructor Dog] " << NC << "A twin " << rhs._type << " appeared" << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

/* Default Deconstructor */
Dog::~Dog(void) {
	delete this->_brain;
	std::cout << BLUE "[Destructor Dog] " << NC << "The dog was scared and ran away" << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

Dog&	Dog::operator=(Dog const& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = rhs.getBrain()->clone();
	}
	return (*this);
}

/* ----- GETTER -------------------------- */
Brain*	Dog::getBrain(void) const {
	return (this->_brain);
}

/* ----- PROTECTED METHOD --------------- */

void Dog::makeSound(void) const {
	std::cout << BLUE "โฮ่ง! โฮ่ง! โฮ่ง!            ⢀⣤⣶⣄⢀⣀⣀⠀     " << std::endl;
	std::cout << "                          ⠸⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀   " << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣤⣤⣤⣤⣤⣤⣀⣀  ⠹⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣴⠾⠛⠉⠉⠉⠀⠀⠀⠀⠀⠉⠉⠉⠛⠷⣶⣼⣿⣉⣁⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⣠⡾⠛⠉⠛⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⡏⠉⠙⠛⢶⣄⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⢠⣾⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⣧⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⢠⣿⠃⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀  ⠈⢿⡇⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠹⣿⡎⠀⠀⠀⣠⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⢻⡆⠀⠀⣆⣿⡇⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⣿⡀⠀⡀⠀⣿⠁⠀⢠⣾⣿⡿⠆⠀⠀⠀⠀⠀⠀⢀⣾⣿⡿⠆⠀⠀⢈⣿⠀⣄⣾⡿⠁⠀⠀⠀ " << std::endl;
	std::cout << "⠀⠀⠀⠘⣿⣧⣇⢀⣇⠀⠀⠘⣿⣿⣷⡆⠀⠀⠀⠀⠀⠀⠈⢿⣿⣷⠖⠀⠀⢸⣿⣷⠿⠋⠀⠀⠀⠀⠀ " << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠉⠙⠻⣿⣆⡀⠀⠀⠉⠉⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣸⣿⠁⣀⣀⣀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⢀⣠⡶⠾⠛⠓⠶⣿⡟⠀⠀⠀⠀⠀⠀⠠⣾⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⠟⠋⠉⠛⠻⣦⡀⠀" << std::endl;
	std::cout << "⢀⣾⠋⠀⠀⠀⠀⠀⠘⣿⣠⣄⡀⠀⠀⠀⠀⠛⠿⠟⠁⠀⠀⠀⠀⠀⡀⡀⠀⣴⣾⡏⠀⠀⠀⠀⠀⠈⣿⡄" << std::endl;
	std::cout << "⢸⣯⠀⢠⠀⠀⢀⣄⣠⣿⠿⢿⣷⣤⣦⣀⣤⣤⣤⣀⣀⣀⣼⣆⣼⣷⣿⡾⠿⢿⣧⣀⣦⠀⠀⣤⠀ ⣸⡧" << std::endl;
	std::cout << "⠘⠿⣷⣾⣷⣤⠾⠿⠛⠁⠀⠀⠀⠁⠀⠉⠉⠀⠀⠀⠈⠉⠉⠉⠉⠉⠁⠀⠀⠀⠀⠉⠛⠻⠷⠾⠿⠟⠛⠁" << std::endl;
	std::system(PLAY_DOG);
	std::cout <<  NC << std::endl;
}