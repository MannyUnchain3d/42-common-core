/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:58:46 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 03:46:50 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "AMateria.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Parameter Constructor */
AMateria::AMateria(std::string const& type) : _type(type) {
	//std::cout << CYAN "[AMateria Constructor] The Materia " NC << this->_type << CYAN " has been created." NC << std::endl;
}

/* Copy Constructor */
AMateria::AMateria(const AMateria& rhs) {
	*this = rhs;
	//std::cout << CYAN "[AMateria Copy Constructor] An existing Materia has been copied." NC << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

AMateria::~AMateria(void) {
	std::cout << CYAN "[AMateria Destructor] A Materia has been destroyed." NC << std::endl;
}

/* ----- GETTER -------------- */

std::string const&	AMateria::getType(void) const {
	return (this->_type);
}

/* ----- PUBLIC METHOD --------------- */

void	AMateria::use(ICharacter& target) {
	std::cout << CYAN "[AMateria Use] The Materia " << this->_type << " has been used on " << target.getName() << "." NC << std::endl;
}
