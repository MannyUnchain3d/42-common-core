/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:49:46 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 01:49:48 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Ice.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Ice::Ice(void) {
	// Make your Constructor here
}

/* Parameter Constructor */
Ice::Ice(std::string name) {
	// Make your Constructor here
}

/* Copy Constructor */
Ice::Ice(const Ice& rhs) {
	*this = rhs;
	// Make your Copy Constructor here
}

/* ----- DESTRUCTOR ------------------- */

Ice::~Ice(void) {
	// Make your Destructor here
}

/* ----- OPERATOR OVERLOAD ------------ */

Ice& Ice::operator=(const Ice& rhs) {
	// Make your Assignment here
	return (*this);
}

/* ----- PROTECTED METHOD ------------- */

/* ----- PRIVATE METHOD --------------- */
