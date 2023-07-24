/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:04:03 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/23 23:09:04 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "colors.h"

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
	std::cout << "⠀⠀⠈⢿⣿⣷⠀⠀⠀⣿⣿⡇⠀⠀⢸⣿⣿⠀⠀⠀⣾⣿⡟⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠉⠉⠀⠀⠀⠈⠉⠁⠀⠀⠈⠉⠁⠀⠀⠀⠉⠉⠀⠀⠀" << std::endl;
	std::cout << "⣴⣄⠀⠀⠀⠀⢀⣴⡄⠀⢀⣤⣴⣦⣤⡀⠀⢠⣦⡀⠀⠀⠀⠀⣠⣦" << std::endl;
	std::cout << "⣿⣿⠀⠀⠀⠀⢸⣿⠇⢠⣿⡟⠋⠙⢻⣿⡄⠸⣿⡇⠀⠀⠀⠀⣿⣿" << std::endl;
	std::cout << "⢸⣿⣄⣴⣶⡄⣾⣿⠀⢾⣿⡁⠀⠀⢈⣿⡷⠀⣿⣷⢠⣶⣦⣠⣿⡇" << std::endl;
	std::cout << "⠈⣿⣿⡿⠻⣿⣿⡿⠀⠘⣿⣧⣄⣠⣼⣿⠃⠀⢿⣿⣿⠟⢿⣿⣿⠁" << std::endl;
	std::cout << "⠀⠻⠛⠁⠀⠘⠻⠃⠀⠀⠈⠛⠻⠟⠛⠁⠀⠀⠘⠟⠃⠀⠈⠛⠟⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⣀⣀⠀⠀⠀⢀⣀⡀⠀⠀⢀⣀⡀⠀⠀⠀⣀⣀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⢀⣾⣿⡿⠀⠀⠀⣿⣿⡇⠀⠀⢸⣿⣿⠀⠀⠀⢿⣿⣧⠀⠀" << std::endl;
	std::cout << "⠀⠀⠘⠿⠟⠁⠀⠀⠰⣿⣿⠃⠀⠀⠘⣿⣿⠆⠀⠀⠘⠿⠟⠀⠀" << std::endl;
	std::system(PLAY_WOW);
	std::cout << std::endl;
}