/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:22:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/18 20:02:06 by Manny            ###   ########.fr       */
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

void	ScavTrap::attack(std::string const& target) {
	if (this->_energyPoints <= 0) {
		std::cout << GREEN << "[ScavTrap] " << this->_name << NC << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << GREEN << "[ScavTrap] " << this->_name << NC << " attacks " << target << " causing ";
	std::cout << this->_attackDamage << " damage!" << std::endl;
	this->_energyPoints -= 1;
	std::cout << GREEN << "[ScavTrap] " << this->_name << NC << " has " << this->_energyPoints << " energy points left." << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << GREEN << "[ScavTrap] " << this->_name << NC << " is in Gate keeper mode." << std::endl;
}