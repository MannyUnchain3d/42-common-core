/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:22:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 06:24:50 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "colors.h"

/* ----- CONSTRUCTOR -------------------*/

/* Default Constructor */
ScavTrap::ScavTrap(void) :
	ClapTrap("Default"), _scavHp(100), _scavHpMax(100), _scavEp(50), _scavAd(20) {
	this->_hp = this->_scavHp;
	this->_hpMax = this->_scavHpMax;
	this->_ep = this->_scavEp;
	this->_ad = this->_scavAd;
	std::cout << GREEN "[ScavTrap] " NC "Default Constructor called" << std::endl;
}

/* Copy Constructor */
ScavTrap::ScavTrap(ScavTrap const& rhs) : ClapTrap(rhs) {
	*this = rhs;
	std::cout << L_GREEN "[ScavTrap] " NC "A twin appears..." << std::endl;
}

/* Parameter Constructor */
ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name), _scavHp(100), _scavHpMax(100), _scavEp(50), _scavAd(20) {
	this->_hp = this->_scavHp;
	this->_hpMax = this->_scavHpMax;
	this->_ep = this->_scavEp;
	this->_ad = this->_scavAd;
	std::cout << GREEN "[ScavTrap] " << this->_name << NC " enters the arena with " << this->_hp << " hit points, ";
	std::cout << this->_ep << " energy points and " << this->_ad << " attack points!" << std::endl;
}

/* ----- DESTRUCTOR ------------------ */

ScavTrap::~ScavTrap(void) {
	std::cout << GREEN "[ScavTrap] " << this->_name << NC " end of fight...\\(ᵔᵕᵔ)/" << std::endl;
}

/* ----- OPERATOR OVERLOAD ---------- */

ScavTrap&	ScavTrap::operator=(ScavTrap const& rhs) {
	if (this != &rhs) {
		this->_name = rhs._name + "_twin";
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

/* ----- PUBLIC METHOD ------------- */

void	ScavTrap::attack(std::string const& target) {
	if (this->_hp <= 0) {
		std::cout << GREEN "[ScavTrap] " << this->_name << NC " can't attack..." << std::endl;
		return ;
	}
	if (this->_ep <= 0) {
		std::cout << GREEN "[ScavTrap] " << this->_name << NC " is out of energy!" << std::endl;
		return ;
	}
	this->_ep -= 1;
	std::cout << GREEN "[ScavTrap] " << this->_name << NC " attacks " << target << " causing " << this->_ad << " damage points!" << std::endl;
	std::cout << GREEN "[ScavTrap] " << this->_name << NC " has " << this->_ep << " energy points left!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	if (this->_hp <= 0) {
		std::cout << GREEN << "[ScavTrap] " << this->_name << NC " can't do that while dead..." << std::endl;
		return ;
	}
	if (this->_ep <= 0) {
		std::cout << GREEN << "[ScavTrap] " << this->_name << NC " is out of energy!" << std::endl;
		return ;
	}
	std::cout << GREEN << "[ScavTrap] " << this->_name << NC " is in Gate Keeper mode" << std::endl;
}