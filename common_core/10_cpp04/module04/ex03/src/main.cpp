/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:40:49 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 03:47:55 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int		main(void) {
	std::cout << RED "/* ----- MateriaSource Assignment -------------- */" NC << std::endl;
	IMateriaSource*	src = new MateriaSource();
	std::cout << std::endl;

	std::cout << RED "/* ----- MateriaSource Learn ------------------- */" NC << std::endl;
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	std::cout << std::endl;
	
	std::cout << RED "/* ----- Character Creation -------------------- */" NC << std::endl;
	ICharacter*	me = new Character("me");
	std::cout << std::endl;

	std::cout << RED "/* ----- MateriaSource Equip ------------------- */" NC << std::endl;
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << RED "/* ----- Target Creation ---------------------- */" NC << std::endl;
	ICharacter*	bob = new Character("bob");
	std::cout << std::endl;

	std::cout << RED "/* ----- Materia Use -------------------------- */" NC << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << std::endl;

	std::cout << RED "/* ----- MateriaSource Unequip ----------------- */" NC << std::endl;
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);
	std::cout << std::endl;

	std::cout << RED "/* ----- MateriaSource Equip ------------------ */" NC << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << RED "/* ----- Materia Use -------------------------- */" NC << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << std::endl;

	delete me;
	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;
	delete src;
	
	return (0);
}