/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:04:03 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/21 22:46:55 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "colors.h"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Animal::Animal(void) : _type("Animal"){
	std::cout << YELLOW "[Default Constructor] A wild animal appeared" NC << std::endl;
}

/* Parameter Constructor */
Animal::Animal(std::string type) : _type(type) {
	this->_type = type;
	std::cout << YELLOW "[Param Constructor] A wild " << type << " appeared" NC << std::endl;
}

/* Copy Constructor */
Animal::Animal(Animal const& rhs) {
	*this = rhs;
	std::cout << YELLOW "[Copy Constructor] A twin" << rhs._type << " appeared" NC << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

/* Default Deconstructor */
Animal::~Animal(void) {
	std::cout << YELLOW "[Default Destructor] The animal was scared and ran away" NC << std::endl;
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
	std::cout << YELLOW "What does the fox say?!" << std::endl;
	std::cout << "Ring-ding-ding-ding-dingeringeding!" << std::endl;
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
	std::cout << NC << std::endl;
}