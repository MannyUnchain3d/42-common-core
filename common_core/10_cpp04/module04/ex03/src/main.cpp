/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:40:49 by Manny             #+#    #+#             */
/*   Updated: 2023/07/28 02:15:34 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "Ice.hpp"

int		main(void) {
	std::cout << RED "/* ----- Materia Creation ---------------------- */" NC << std::endl;
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); // cannot learn more than 4
	std::cout << std::endl;
	
	std::cout << RED "/* ----- Character Creation -------------------- */" NC << std::endl;
	ICharacter*	me = new Character("me");
	std::cout << std::endl;

	std::cout << RED "/* ----- Materia Equip ------------------------- */" NC << std::endl;
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp); // cannot equip more than 4
	std::cout << std::endl;

	me->printInventory();
	std::cout << std::endl;

	std::cout << RED "/* ----- Character Creation -------------------- */" NC << std::endl;
	ICharacter*	bob = new Character("bob");
	std::cout << std::endl;

	std::cout << RED "/* ----- Materia Use --------------------------- */" NC << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob); // nothing to use
	std::cout << std::endl;

	std::cout << RED "/* ----- Materia Unequip ----------------------- */" NC << std::endl;
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(3); // is empty already
	me->unequip(4); // is invalid index
	std::cout << std::endl;

	me->printInventory();
	std::cout << std::endl;

	std::cout << RED "/* ----- Character Destruction ---------------- */" NC << std::endl;
	delete bob;
	delete me;
	std::cout << std::endl;

	std::cout << RED "/* ----- Materia Destruction ------------ */" NC << std::endl;
	delete src;

	return (0);
}