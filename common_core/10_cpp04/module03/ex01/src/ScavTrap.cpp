/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:22:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/16 18:33:18 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ----- CONSTRUCTOR -------------------*/

/* Default Constructor */
ScavTrap::ScavTrap(void) {
	std::cout << GREEN << "[ScavTrap] " << NC << "Default Constructor called" << std::endl;
}

/* Copy Constructor */
ScavTrap::ScavTrap(ScavTrap const& rhs) : ClapTrap(rhs) {
	std::cout << GREEN << "[ScavTrap] " << NC << "Copy Constructor called" << std::endl;
}

/* Parameter Constructor */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << GREEN << "[ScavTrap] " << this->_name << NC << " enters the arena with " << this->_hitPoints << " hit points, ";
	std::cout << this->_energyPoints << " energy points and " << this->_attackDamage << " attack damage!" << std::endl;
}

/* ----- DESTRUCTOR ------------------ */

ScavTrap::~ScavTrap(void) {
	std::cout << GREEN << "[ScavTrap] " << NC << "End of the fight..." << std::endl;
}

/* ----- PUBLIC METHOD ------------- */

void	ScavTrap::guardGate(void) {
	std::cout << GREEN << "[ScavTrap] " << this->_name << NC << " is in Gate keeper mode." << std::endl;
}