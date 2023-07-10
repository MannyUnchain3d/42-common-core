/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:58:35 by Manny             #+#    #+#             */
/*   Updated: 2023/07/10 01:59:45 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

HumanB::HumanB(std::string name) : _name(name) {
	this->_weapon = NULL;
	std::cout << "Human B " << BLUE << this->_name << NC << " created" << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "Human B " << BLUE << this->_name << NC << " destroyed" << std::endl;
}

/* ************************ GETTERS / SETTERS ******************************* */

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

/* ************************* MEMBER FUNCTIONS ******************************** */

void	HumanB::attack(void) const {
	if (this->_weapon != NULL && this->_weapon->getType() != "") {
		std::cout << BLUE << this->_name << NC << " attacks with their ",
		std::cout << YELLOW << this->_weapon->getType() << NC << std::endl;
	}
	else
		std::cout << BLUE << this->_name << NC << " has no weapon" << std::endl;
}