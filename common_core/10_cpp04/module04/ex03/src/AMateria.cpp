/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:58:46 by Manny             #+#    #+#             */
/*   Updated: 2023/07/28 01:30:47 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "AMateria.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Parameter Constructor */
AMateria::AMateria(std::string const& type) : _type(type) {
	//std::cout << L_CYAN "[AMateria Constructor] The Materia " NC << this->_type << L_CYAN " has been created." NC << std::endl;
}

/* Copy Constructor */
AMateria::AMateria(const AMateria& rhs) {
	*this = rhs;
	//std::cout << L_CYAN "[AMateria Copy Constructor] An existing Materia has been copied." NC << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

AMateria::~AMateria(void) {
	//std::cout << L_CYAN "[AMateria Destructor] A Materia has been destroyed." NC << std::endl;
}

/* ----- GETTER -------------- */

std::string const&	AMateria::getType(void) const {
	return (this->_type);
}

/* ----- PUBLIC METHOD --------------- */

void	AMateria::use(ICharacter& target) {
	std::cout << L_CYAN "[AMateria Use] The Materia " << this->_type << " has been used on " << target.getName() << "." NC << std::endl;
}
