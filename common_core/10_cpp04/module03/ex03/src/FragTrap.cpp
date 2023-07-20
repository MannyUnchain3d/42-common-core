/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:22:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 06:19:01 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "colors.h"

/* ----- CONSTRUCTOR -------------------*/

/* Default Constructor */
FragTrap::FragTrap(void) :
	ClapTrap("Default"), _fragHp(70), _fragHpMax(70), _fragEp(80), _fragAd(90) {
	this->_hp = this->_fragHp;
	this->_hpMax = this->_fragHp;
	this->_ep = this->_fragEp;
	this->_ad = this->_fragAd;
	std::cout << BLUE "[FragTrap] " NC "Default Constructor called" << std::endl;
}

/* Copy Constructor */
FragTrap::FragTrap(FragTrap const& rhs) : ClapTrap(rhs) {
	*this = rhs;
	std::cout << L_BLUE "[FragTrap] " NC "A twin appears..." << std::endl;
}

/* Parameter Constructor */
FragTrap::FragTrap(std::string name) :
	ClapTrap(name), _fragHp(70), _fragHpMax(70), _fragEp(80), _fragAd(90) {
	this->_hp = this->_fragHp;
	this->_hpMax = this->_fragHpMax;
	this->_ep = this->_fragEp;
	this->_ad = this->_fragAd;
	std::cout << BLUE "[FragTrap] " << this->_name << NC " enters the arena with " << this->_hp << " hit points, ";
	std::cout << this->_ep << " energy points and " << this->_ad << " attack points!" << std::endl;
}

/* ----- DESTRUCTOR ------------------ */

FragTrap::~FragTrap(void) {
	std::cout << BLUE "[FragTrap] " << this->_name << NC " end of fight...\\(ᵔᵕᵔ)/" << std::endl;
}

/* ----- OPERATOR OVERLOAD ---------- */

FragTrap&	FragTrap::operator=(FragTrap const& rhs) {
	if (this != &rhs) {
		this->_name = rhs._name + "_twin";
		this->_hp = rhs._hp;
		this->_hpMax = rhs._hpMax;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

/* ----- PUBLIC METHOD ------------- */

void	FragTrap::highFivesGuys(void) {
	if (this->_hp <= 0) {
		std::cout << BLUE << "[FragTrap] " << this->_name << NC << " can't do that while dead..." << std::endl;
		return ;
	}
	if (this->_ep <= 0) {
		std::cout << BLUE "[FragTrap] " << this->_name << NC " is out of energy!" << std::endl;
		return ;
	}
	std::cout << BLUE "[FragTrap] " << this->_name << NC " is asking for a high five!" << std::endl;
}