/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:42:51 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 01:42:53 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "MateriaSource.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
MateriaSource::MateriaSource(void) {
	// Make your Constructor here
}

/* Parameter Constructor */
MateriaSource::MateriaSource(std::string name) {
	// Make your Constructor here
}

/* Copy Constructor */
MateriaSource::MateriaSource(const MateriaSource& rhs) {
	*this = rhs;
	// Make your Copy Constructor here
}

/* ----- DESTRUCTOR ------------------- */

MateriaSource::~MateriaSource(void) {
	// Make your Destructor here
}

/* ----- OPERATOR OVERLOAD ------------ */

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	// Make your Assignment here
	return (*this);
}

/* ----- GETTER ----------------------- */

/* ----- PUBLIC METHOD ---------------- */

/* ----- PROTECTED METHOD ------------- */

/* ----- PRIVATE METHOD --------------- */
