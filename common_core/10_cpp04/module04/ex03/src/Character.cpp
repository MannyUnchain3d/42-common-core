/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:45:02 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 03:02:48 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Character.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Parameter Constructor */
Character::Character(std::string const& name) : _name(name), _nbMateria(0) {
	for(int i = 0; i < Character::_inventorySize; i++)
		this->_inventory[i] = NULL;
	std::cout << YELLOW "[Character Constructor] " NC << this->_name << YELLOW " has been created." NC << std::endl;
}

/* Copy Constructor */
Character::Character(Character const& rhs) : _name(rhs.getName()) {
	for (int i = 0; i < Character::_inventorySize; i++) {
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		if (rhs._inventory[i])
			this->_nbMateria++;
	}
	std::cout << YELLOW "[Character Copy Constructor] An existing Character has been copied." NC << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

Character::~Character(void) {
	for(int i = 0; i < Character::_inventorySize; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	std::cout << YELLOW "[Character Destructor] A Character has been destroyed." NC << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

Character& Character::operator=(Character const& rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_nbMateria = 0;
		for(int i = 0; i < Character::_inventorySize; i++) {
			if (this->_inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			if (rhs._inventory[i])
				this->_nbMateria++;
		}
	}
	//std::cout << YELLOW "[Character Assignation Operator] A Character has been assigned." NC << std::endl;
	return (*this);
}

/* ----- GETTER ----------------------- */

std::string const&	Character::getName(void) const {
	return (this->_name);
}

/* ----- PUBLIC METHOD ---------------- */

void	Character::equip(AMateria* m) {
	if (!m)
		std::cout << YELLOW "Invalid Materia..." NC << std::endl;
	else if (this->_nbMateria < Character::_inventorySize) {
		for(int i = 0; i < Character::_inventorySize; i++) {
			if (!this->_inventory[i]) {
				this->_inventory[i] = m;
				this->_nbMateria++;
				std::cout << YELLOW "The Materia " NC << m->getType() << YELLOW " has been equipped." NC << std::endl;
				return ;
			}
		}
	}
	std::cout << YELLOW "Inventory is full..." NC << std::endl;
}

void	Character::unequip(int idx) {
	if (idx <= 0 || idx > Character::_inventorySize)
		std::cout << YELLOW "Invalid index..." NC << std::endl;
	if (idx > 0 && idx <= Character::_inventorySize && this->_inventory[idx - 1]) {
		std::string _materiaType = this->_inventory[idx - 1]->getType();
		this->_inventory[idx - 1] = NULL;
		this->_nbMateria--;
		std::cout << YELLOW "Unequipped " NC << _materiaType << YELLOW " Materia." NC << std::endl;
	}
	std::cout << YELLOW "Inventory slot is empty..." NC << std::endl;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= Character::_inventorySize - 1 && this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
		return ;
	}
	std::cout << YELLOW "Nothing to use..." NC << std::endl;
}
