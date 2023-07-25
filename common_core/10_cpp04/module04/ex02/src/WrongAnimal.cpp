/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:05:58 by Manny             #+#    #+#             */
/*   Updated: 2023/07/25 02:46:14 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "WrongAnimal.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << CYAN "[Default Constructor WrongAnimal] " << NC << "A wild " << this->_type << " appeared" << std::endl;
}

/* Copy Constructor */
WrongAnimal::WrongAnimal(WrongAnimal const& rhs) {
	*this = rhs;
	std::cout << CYAN "[Copy Constructor WrongAnimal] " << NC << "A twin " << rhs._type << " appeared" << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

/* Default Deconstructor */
WrongAnimal::~WrongAnimal(void) {
	std::cout << CYAN "[Destructor WrongAnimal] " << NC << "That wrong thing was scared and ran away" << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/* ----- GETTER ----------------------- */

std::string	WrongAnimal::getType(void) const {
	return (this->_type);
}

/* ----- PROTECTED METHOD --------------- */

void	WrongAnimal::makeSound(void) const {
	std::cout << CYAN "Ring-ding-ding-ding-dingeringeding!" << std::endl;
	std::cout << "Gering-ding-ding-ding-dingeringeding!" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠙⠻⢶⣄⡀⠀⠀⠀⢀⣤⠶⠛⠛⡇⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣇⠀⠀⣙⣿⣦⣤⣴⣿⣁⠀⠀⣸⠇⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣌⠋⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣷⣄⡈⢻⣿⡟⢁⣠⣾⣿⣦⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⠘⣿⠃⣿⣿⣿⣿⡏⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠈⠛⣰⠿⣆⠛⠁⠀⡀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣦⠀⠘⠛⠋⠀⣴⣿⠁⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣾⣿⣿⣿⡇⠀⠀⠀⢸⣿⣏⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠀⠀⠀⠾⢿⣿⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⣁⣠⣤⣀⣀⣤⣤⣤⣄⠈⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⢰⣿⣿⣮⣉⣉⣉⣤⣴⣶⣿⣿⣿⣋⡥⠄⠀⠀⠀⠀⠉⢻⣄⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣋⣁⣤⣀⣀⣤⣤⣤⣄⣿⡄⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠋⠉⠁⠀⠀⠀⠀⠈⠛⠃⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::system(PLAY_WTF);
	std::cout << NC << std::endl;
}