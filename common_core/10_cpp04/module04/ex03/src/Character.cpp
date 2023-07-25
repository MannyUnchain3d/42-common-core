/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:45:02 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 01:45:03 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Character.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Character::Character(void) {
	// Make your Constructor here
}

/* Parameter Constructor */
Character::Character(std::string name) {
	// Make your Constructor here
}

/* Copy Constructor */
Character::Character(const Character& rhs) {
	*this = rhs;
	// Make your Copy Constructor here
}

/* ----- DESTRUCTOR ------------------- */

Character::~Character(void) {
	// Make your Destructor here
}

/* ----- OPERATOR OVERLOAD ------------ */

Character& Character::operator=(const Character& rhs) {
	// Make your Assignment here
	return (*this);
}

/* ----- PROTECTED METHOD ------------- */

void Character::_protectedMethod(void) {
	// Implement protected method here
}

/* ----- PRIVATE METHOD --------------- */

void Character::_privateMethod(void) {
	// Implement private method here
}
