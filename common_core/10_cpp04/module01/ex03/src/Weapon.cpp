/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:47:38 by Manny             #+#    #+#             */
/*   Updated: 2023/07/10 02:02:45 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */
Weapon::Weapon(std::string type) {
	this->setType(type);
}

Weapon::~Weapon(void) {
}

/* ************************ GETTERS / SETTERS ******************************* */
std::string const&	Weapon::getType(void) {
	return (this->_type);
}

void				Weapon::setType(std::string type) {
	this->_type = type;
}