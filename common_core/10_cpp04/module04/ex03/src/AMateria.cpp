/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:58:46 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 01:39:56 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "AMateria.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
AMateria::AMateria(void) : _type("Materia") {
	std::cout << YELLOW "[AMateria Default Constructor]" NC << std::endl;
}

/* Parameter Constructor */
AMateria::AMateria(std::string const& type) : _type(type) {
	std::cout << YELLOW "[AMateria Parameter Constructor]" NC << std::endl;
}

/* Copy Constructor */
AMateria::AMateria(const AMateria& rhs) {
	*this = rhs;
	std::cout << YELLOW "[AMateria Copy Constructor]" NC << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

AMateria::~AMateria(void) {
	std::cout << YELLOW "[AMateria Destructor]" NC << std::endl;
}

/* ----- GETTER -------------- */

std::string const&	AMateria::getType(void) const {
	return (this->_type);
}
