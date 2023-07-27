/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:49:46 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 23:24:34 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Fire.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Fire::Fire(void) : AMateria("fire") {
	std::cout << RED "[Fire Default Constructor] The Materia " NC << this->_type << RED " has been created." NC << std::endl;
}

/* Copy Constructor */
Fire::Fire(const Fire& rhs) : AMateria(rhs){
	*this = rhs;
	std::cout << RED "[Fire Copy Constructor] An existing Fire Materia has been copied." NC << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

Fire::~Fire(void) {
	std::cout << RED "[Fire Destructor] An Fire Materia has been destroyed." NC << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

Fire& Fire::operator=(const Fire& rhs) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

/* ----- PUBLIC METHOD --------------- */

AMateria*	Fire::clone(void) const {
	return (new Fire(*this));
}

void	Fire::use(ICharacter& target) {
	std::cout << RED "* throws a fireball at " NC << target.getName() << RED " *" NC << std::endl;
}