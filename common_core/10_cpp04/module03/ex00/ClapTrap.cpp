/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:48:06 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 06:34:39 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.h"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
ClapTrap::ClapTrap(void) : _name("Default"), _hp(10), _hpMax(10), _ep(10), _ad(0) {
	std::cout << YELLOW "[ClapTrap] " NC "Default Constructor called" << std::endl;
}

/* Copy Constructor */
ClapTrap::ClapTrap(ClapTrap const& rhs) {
	*this = rhs;
	std::cout << L_YELLOW "[ClapTrap] " NC "A twin appears..." << std::endl;
}

/* Parameter Constructor */
ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _hpMax(10), _ep(10), _ad(0) {
	std::cout << YELLOW "[ClapTrap] " << this->_name << NC " enters the arena with " << this->_hp << " hit points, ";
	std::cout << this->_ep << " energy points and " << this->_ad << " attack points!" << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

ClapTrap::~ClapTrap(void) {
	std::cout << YELLOW "[ClapTrap] " << this->_name << NC " end of fight...\\(ᵔᵕᵔ)/" << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name + "_twin";
		this->_hp = rhs._hp;
		this->_hpMax = rhs._hpMax;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

void	ClapTrap::attack(std::string const& target) {
	if (this->_hp <= 0) {
		std::cout << YELLOW "[ClapTrap] " << this->_name << NC " can't attack..." << std::endl;
		return ;
	}
	if (this->_ep <= 0) {
		std::cout << YELLOW "[ClapTrap] " << this->_name << NC " is out of energy!" << std::endl;
		return ;
	}
	this->_ep -= 1;
	std::cout << YELLOW "[ClapTrap] " << this->_name << NC " attacks " << target << " causing " << this->_ad << " damage points!" << std::endl;
	std::cout << YELLOW "[ClapTrap] " << this->_name << NC " has " << this->_ep << " energy points left!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << YELLOW "[ClapTrap] " << this->_name << NC " takes " << amount << " damage points!" << std::endl;
	if (this->_hp <= amount) {
		this->_hp = 0;
		std::cout << YELLOW "[ClapTrap] " << this->_name << NC " is dead..." << std::endl;
		return ;
	}
	this->_hp -= amount;
	std::cout << YELLOW "[ClapTrap] " << this->_name << NC " has " << this->_hp << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_ep <= 0) {
		std::cout << YELLOW "[ClapTrap] " << this->_name << NC " is out of energy!" << std::endl;
		return;
	}
	if (_hp <= 0) {
		std::cout << YELLOW "[ClapTrap] " << this->_name << NC " can't be revived..." << std::endl;
		return;
	}
	if (_hp >= _hpMax) {
		std::cout << YELLOW "[ClapTrap] " << this->_name << NC " is already at full health!" << std::endl;
		return;
	}
	unsigned int	heal = std::min(amount, _hpMax - _hp);
	_ep -= 1;
	_hp += heal;
	_hp = std::min(_hp, _hpMax);
	std::cout << YELLOW "[ClapTrap] " << this->_name << NC << " recovers " << heal << " hit points!" << std::endl;
	std::cout << YELLOW "[ClapTrap] " << this->_name << NC << " has " << _hp << " hit points";
	std::cout << " and " << _ep << " energy points left!" << std::endl;
}