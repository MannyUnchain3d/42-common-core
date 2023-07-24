/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:40:19 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/23 18:36:42 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "WrongCat.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
WrongCat::WrongCat(void) {
	this->_type = "WrongCat";
	std::cout << RED "[Default Constructor WrongCat] " << NC << "A wild " << this->_type << " appeared" << std::endl;
}

/* Copy Constructor */
WrongCat::WrongCat(WrongCat const& rhs) : WrongAnimal(rhs) {
	*this = rhs;
	std::cout << RED "[Copy Constructor WrongCat] " << NC << "A twin " << rhs._type << " appeared" << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

/* Default Deconstructor */
WrongCat::~WrongCat(void) {
	std::cout << RED "[Destructor WrongCat] " << NC << "That wrong thing was scared and ran away" << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

WrongCat&	WrongCat::operator=(WrongCat const& rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/* ----- PROTECTED METHOD --------------- */

void WrongCat::makeSound(void) const {
	std::cout << RED "なに! なに! なに!" << std::endl;
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
	std::system(PLAY_WTF_CAT);
	std::cout << NC << std::endl;
}