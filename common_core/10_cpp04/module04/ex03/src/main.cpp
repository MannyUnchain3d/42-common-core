/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:40:49 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 16:36:01 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int		main(void) {
	std::cout << RED "/* ----- MateriaSource Creation ---------------- */" NC << std::endl;
	IMateriaSource*	src = new MateriaSource();
	std::cout << std::endl;

	std::cout << RED "/* ----- MateriaSource Learn ------------------- */" NC << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;
	
	std::cout << RED "/* ----- Character Creation -------------------- */" NC << std::endl;
	ICharacter*	me = new Character("me");
	std::cout << std::endl;

	std::cout << RED "/* ----- MateriaSource Equip ------------------- */" NC << std::endl;
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	//tmp = src->createMateria("ice");
	//me->equip(tmp);
	std::cout << std::endl;

	me->printInventory();
	std::cout << std::endl;

	std::cout << RED "/* ----- Target Creation ----------------------- */" NC << std::endl;
	ICharacter*	bob = new Character("bob");
	std::cout << std::endl;

	std::cout << RED "/* ----- Materia Use --------------------------- */" NC << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	// me->use(2, *bob);
	// me->use(3, *bob);
	std::cout << std::endl;

	std::cout << RED "/* ----- MateriaSource Unequip ----------------- */" NC << std::endl;
	me->unequip(0);
	me->unequip(1);
	// me->unequip(2);
	// me->unequip(3);
	std::cout << std::endl;

	me->printInventory();
	std::cout << std::endl;

	std::cout << RED "/* ----- MateriaSource Equip 2 ------------------ */" NC << std::endl;
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	//tmp = src->createMateria("cure");
	//me->equip(tmp);
	std::cout << std::endl;
	
	std::cout << RED "/* ----- Materia Use 2 -------------------------- */" NC << std::endl;
	//me->use(0, *bob);
	// me->use(1, *bob);
	// me->use(2, *bob);
	// me->use(3, *bob);
	std::cout << std::endl;

	delete src;
	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;
	delete me;
	
	return (0);
}