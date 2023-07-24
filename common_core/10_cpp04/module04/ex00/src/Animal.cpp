/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:04:03 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/24 21:44:44 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Animal.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Animal::Animal(void) : _type("Animal") {
	std::cout << YELLOW "[Default Constructor Animal] " << NC << "A wild " << this->_type << " appeared" << std::endl;
}

/* Copy Constructor */
Animal::Animal(Animal const& rhs) {
	*this = rhs;
	std::cout << YELLOW "[Copy Constructor Animal] " << NC << "A twin " << rhs._type << " appeared" << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

/* Default Deconstructor */
Animal::~Animal(void) {
	std::cout << YELLOW "[Destructor Animal] " << NC << "The animal was scared and ran away" << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

Animal&	Animal::operator=(Animal const& rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/* ----- GETTER ----------------------- */

std::string	Animal::getType(void) const {
	return (this->_type);
}

/* ----- PROTECTED METHOD --------------- */

void Animal::makeSound(void) const {
	std::cout << YELLOW "✧⁺⸜(●′▾‵●)⸝⁺✧" << std::endl;
	std::cout << std::endl;
	std::cout << "⠀⠀⢠⣶⣦⡀⠀⠀⠰⣿⣿⡄⠀⠀⢠⣿⣿⠆⠀⠀⢠⣶⣦⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠈⢿⣿⣷⠀⠀⠀⣿⣿⡇⠀⠀⢸⣿⣿⠀⠀⠀⣾⣿⡟⠀⠀"  << std::endl;
	std::cout << "⠀⠀⠀⠀⠉⠉⠀⠀⠀⠈⠉⠁⠀⠀⠈⠉⠁⠀⠀⠀⠉⠉⠀⠀⠀"  << std::endl;
	std::cout << "⣴⣄⠀⠀⠀⠀⢀⣴⡄⠀⢀⣤⣴⣦⣤⡀⠀⢠⣦⡀⠀⠀⠀⠀⣠⣦" << std::endl;
	std::cout << "⣿⣿⠀⠀⠀⠀⢸⣿⠇⢠⣿⡟⠋⠙⢻⣿⡄⠸⣿⡇⠀⠀⠀⠀⣿⣿" << std::endl;
	std::cout << "⢸⣿⣄⣴⣶⡄⣾⣿⠀⢾⣿⡁⠀⠀⢈⣿⡷⠀⣿⣷⢠⣶⣦⣠⣿⡇" << std::endl;
	std::cout << "⠈⣿⣿⡿⠻⣿⣿⡿⠀⠘⣿⣧⣄⣠⣼⣿⠃⠀⢿⣿⣿⠟⢿⣿⣿⠁" << std::endl;
	std::cout << "⠀⠻⠛⠁⠀⠘⠻⠃⠀⠀⠈⠛⠻⠟⠛⠁⠀⠀⠘⠟⠃⠀⠈⠛⠟⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⣀⣀⠀⠀⠀⢀⣀⡀⠀⠀⢀⣀⡀⠀⠀⠀⣀⣀⠀⠀⠀"  << std::endl;
	std::cout << "⠀⠀⢀⣾⣿⡿⠀⠀⠀⣿⣿⡇⠀⠀⢸⣿⣿⠀⠀⠀⢿⣿⣧⠀⠀"  << std::endl;
	std::cout << "⠀⠀⠘⠿⠟⠁⠀⠀⠰⣿⣿⠃⠀⠀⠘⣿⣿⠆⠀⠀⠘⠿⠟⠀⠀"  << std::endl;
	std::system(PLAY_WOW);
	std::cout << std::endl;
}