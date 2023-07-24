/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:40:19 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/24 21:45:05 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Cat.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Cat::Cat(void) {
	this->_type = "Cat";
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
	std::cout << MAGENTA "[Destructor Cat] " << NC << "The cat was scared and ran away" << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

Cat&	Cat::operator=(Cat const& rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
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