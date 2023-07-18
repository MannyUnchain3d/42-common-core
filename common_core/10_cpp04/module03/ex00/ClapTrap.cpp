/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:48:06 by Manny             #+#    #+#             */
/*   Updated: 2023/07/18 19:37:25 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ----- CONSTRUCTOR -------------------*/

/* Default Constructor */
ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

/* Copy Constructor */
ClapTrap::ClapTrap(ClapTrap const& rhs) {
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = rhs;
}

/* Parameter Constructor */
ClapTrap::ClapTrap(std::string name) : 	_name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0) {
	std::cout << this->_name << " enters the arena with " << this->_hitPoints << " hit points, ";
	std::cout << this->_energyPoints << " energy points and " << this->_attackDamage << " attack damage!" << std::endl;
}

/* ----- DESTRUCTOR ------------------ */

ClapTrap::~ClapTrap(void) {
	std::cout << "End of the fight..." << std::endl;
}

/* ----- OPERATOR OVERLOAD ---------- */

ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

/* ----- PUBLIC METHOD ------------- */

void	ClapTrap::attack(std::string const& target) {
	if (this->_energyPoints <= 0) {
		std::cout << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << target << " causing ";
	std::cout << this->_attackDamage << " damage!" << std::endl;
	this->_energyPoints -= 1;
	std::cout << this->_name << " has " << this->_energyPoints << " energy points left!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= amount) {
		std::cout << this->_name << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->_name << " takes " << amount << " damage!" << std::endl;
	this->_hitPoints -= amount;
	std::cout << this->_name << " has " << this->_hitPoints << " hit points left!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0) {
		std::cout << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << this->_name << " heals " << amount << " hit points!" << std::endl;
	_energyPoints -= 1;
	_hitPoints += amount;
	std::cout << this->_name << " has " << this->_hitPoints << " hit points";
	std::cout << " and " << this->_energyPoints << " energy points left!" << std::endl;

}