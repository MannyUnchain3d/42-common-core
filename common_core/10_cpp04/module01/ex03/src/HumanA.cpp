/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:53:17 by Manny             #+#    #+#             */
/*   Updated: 2023/07/10 02:00:02 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
	std::cout << "Human A " << RED << this->_name << NC << " created" << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "Human A " << RED << this->_name << NC << " destroyed" << std::endl;
}

/* ************************* MEMBER FUNCTIONS ******************************** */

void	HumanA::attack(void) const {
	std::cout << RED << this->_name << NC << " attacks with their ",
	std::cout << YELLOW << this->_weapon.getType() << NC << std::endl;
}