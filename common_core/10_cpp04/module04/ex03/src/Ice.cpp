/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:49:46 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 23:37:40 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Ice.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Ice::Ice(void) : AMateria("ice") {
	std::cout << BLUE "[Ice Default Constructor] The Materia " NC << this->_type << BLUE " has been created." NC << std::endl;
}

/* Copy Constructor */
Ice::Ice(const Ice& rhs) : AMateria(rhs){
	*this = rhs;
	std::cout << BLUE "[Ice Copy Constructor] An existing Ice Materia has been copied." NC << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

Ice::~Ice(void) {
	std::cout << BLUE "[Ice Destructor] An Ice Materia has been destroyed." NC << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

Ice& Ice::operator=(const Ice& rhs) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

/* ----- PUBLIC METHOD --------------- */

AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << BLUE "* shoots an ice bolt at " NC << target.getName() << BLUE " *" NC << std::endl;
}