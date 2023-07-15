/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:48:06 by Manny             #+#    #+#             */
/*   Updated: 2023/07/15 20:48:09 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ----- CONSTRUCTOR -------------------*/

/* Default Constructor */
ClapTrap::ClapTrap(void) {
	// Make your Constructor here
}

/* Copy Constructor */
ClapTrap::ClapTrap (ClapTrap const& src) {
	// Make your Copy Constructor here
	*this = src;
}

/* Parameter Constructor */
ClapTrap::ClapTrap (int const n) {
	// Make your Constructor here
}

/* ----- DESTRUCTOR ------------------ */

ClapTrap::~ClapTrap(void) {
	// Make your Destructor here
}

/* ----- OPERATOR OVERLOAD ---------- */

ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs) {
	// Make your Assignment here
	return (*this);
}

/* ----- GETTER ----------------------- */

/* ----- SETTER ----------------------- */

/* ----- PUBLIC METHOD ------------- */

/* ----- PRIVATE METHOD ------------ */

/* ----- EXTERNAL FUNCTION --------- */

