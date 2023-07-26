/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:48:46 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/27 00:39:20 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Cure.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Cure::Cure(void) : AMateria("cure") {
	std::cout << GREEN "[Cure Default Constructor] The Materia " NC << this->_type << GREEN" has been created." NC << std::endl;
}

/* Copy Constructor */
Cure::Cure(const Cure& rhs) : AMateria(rhs){
	*this = rhs;
	std::cout << GREEN "[Cure Copy Constructor] An existing Cure Materia has been copied." NC << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

Cure::~Cure(void) {
	std::cout << GREEN "[Cure Destructor] A Cure Materia has been destroyed." NC << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

Cure& Cure::operator=(const Cure& rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/* ----- PUBLIC METHOD --------------- */

AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << GREEN "* heals " NC << target.getName() << GREEN "'s wounds *" NC << std::endl;
}
