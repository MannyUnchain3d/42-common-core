/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:40:19 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/25 05:05:32 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Cat.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Cat::Cat(void) {
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << MAGENTA "[Default Constructor Cat] " << NC << "A wild " << this->_type << " appeared" << std::endl;
}

/* Copy Constructor */
Cat::Cat(Cat const& rhs) : Animal(rhs) {
	*this = rhs;
	std::cout << MAGENTA "[Copy Constructor Cat] " << NC << "A twin " << rhs._type << " appeared" << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

/* Default Deconstructor */
Cat::~Cat(void) {
	delete this->_brain;
	std::cout << MAGENTA "[Destructor Cat] " << NC << "The cat was scared and ran away" << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

Cat&	Cat::operator=(Cat const& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = rhs.getBrain()->clone();
	}
	return (*this);
}

/* ----- GETTER -------------------------- */

Brain*	Cat::getBrain(void) const {
	return (this->_brain);
}

/* ----- PROTECTED METHOD --------------- */

void Cat::makeSound(void) const {
	std::cout << MAGENTA "เหมียว... เหมียว... เหมียว..." << std::endl;
	std::cout << "⠀⠀⠀⠀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⣠⠾⠛⠶⣄⢀⣠⣤⠴⢦⡀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⢠⡿⠉⠉⠉⠛⠶⠶⠖⠒⠒⣾⠋⠀⢀⣀⣙⣯⡁⠀⠀⠀⣿⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏⠀⠀⢯⣼⠋⠉⠙⢶⠞⠛⠻⣆⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⢸⣧⠆⠀⠀⠀⠀⠀⠀⠀⠀⠻⣦⣤⡤⢿⡀⠀⢀⣼⣷⠀⠀⣽⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⣼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⢏⡉⠁⣠⡾⣇⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⢰⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠋⠉⠀⢻⡀⠀⠀" << std::endl;
	std::cout << "⣀⣠⣼⣧⣤⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠐⠖⢻⡟⠓⠒" << std::endl;
	std::cout << "⠀⠀⠈⣷⣀⡀⠀⠘⠿⠇⠀⠀⠀⢀⣀⣀⠀⠀⠀⠀⠿⠟⠀⠀⠀⠲⣾⠦⢤⠀" << std::endl;
	std::cout << "⠀⠀⠋⠙⣧⣀⡀⠀⠀⠀⠀⠀⠀⠘⠦⠼⠃⠀⠀⠀⠀⠀⠀⠀⢤⣼⣏⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⢀⠴⠚⠻⢧⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⠞⠉⠉⠓⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠛⠶⠶⠶⣶⣤⣴⡶⠶⠶⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::system(PLAY_CAT);
	std::cout << NC << std::endl;
}