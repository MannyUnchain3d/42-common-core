/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:49:37 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 06:18:47 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "colors.h"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
	this->_name = "Default";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_hpMax = FragTrap::_hpMax;
	this->_ep = ScavTrap::_ep;
	this->_ad = FragTrap::_ad;
	std::cout << CYAN "[DiamondTrap] " NC "Default Constructor called" << std::endl;
}

/* Copy Constructor */
DiamondTrap::DiamondTrap(DiamondTrap const& rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs) {
	*this = rhs;
	std::cout << L_CYAN << "[DiamondTrap] " << NC << "A twin appears..." << std::endl;
}

/* Parameter Constructor */
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_hpMax = FragTrap::_hpMax;
	this->_ep = ScavTrap::_scavEp;
	this->_ad = FragTrap::_ad;
	
	std::cout << CYAN "[DiamondTrap] " << this->_name << NC " enters the arena with " << this->_hp << " hit points, ";
	std::cout << this->_ep << " energy points and " << this->_ad << " attack points!" << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

DiamondTrap::~DiamondTrap(void) {
	std::cout << CYAN "[DiamondTrap] " << this->_name << NC " end of fight...\\(ᵔᵕᵔ)/" << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */
DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& rhs) {
	if (this != &rhs) {
		this->_name = rhs._name + "_twin";
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->_hp = rhs._hp;
		this->_hpMax = rhs._hpMax;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

void	DiamondTrap::whoAmI(void) {
	if (this->_hp <= 0) {
		std::cout << CYAN "[DiamondTrap] " << this->_name << NC " RIP... (⌣́_⌣̀)" << std::endl;
		return ;
	}
	if (this->_ep <= 0) {
		std::cout << CYAN "[DiamondTrap] " << this->_name << NC " is out of energy..." << std::endl;
		return ;
	}
	std::cout << CYAN "[DiamondTrap] " << this->_name << NC " is also known as " << this->ClapTrap::_name << std::endl;
}