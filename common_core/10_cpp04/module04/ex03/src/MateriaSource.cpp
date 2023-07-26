/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:42:51 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 00:30:49 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "MateriaSource.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
MateriaSource::MateriaSource(void) {
	for(int i = 0; i < MateriaSource::_materiasMax; i++)
		this->_materials[i] = NULL;
	std::cout << L_CYAN "[MateriaSource Default Constructor] The MateriaSource has been created." NC << std::endl;
}

/* Copy Constructor */
MateriaSource::MateriaSource(const MateriaSource& rhs) {
	*this = rhs;
	std::cout << L_CYAN "[MateriaSource Copy Constructor] An existing MateriaSource has been copied." NC << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

MateriaSource::~MateriaSource(void) {
	for(int i = 0; i < MateriaSource::_materiasMax; i++)
		delete this->_materials[i];
	std::cout << L_CYAN "[MateriaSource Destructor] A MateriaSource has been destroyed." NC << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	if (this != &rhs)
	{
		for(int i = 0; i < MateriaSource::_materiasMax; i++)
			this->_materials[i] = rhs._materials[i];
	}
	std::cout << L_CYAN "[MateriaSource Assignation Operator] A MateriaSource has been assigned." NC << std::endl;
	return (*this);
}

/* ----- GETTER ----------------------- */

AMateria*	MateriaSource::getMaterial(std::string const& type) {
	for(int i = 0; i < MateriaSource::_materiasMax; i++)
	{
		if (this->_materials[i] != NULL && this->_materials[i]->getType() == type)
			return (this->_materials[i]);
	}
	return (NULL);
}

/* ----- PUBLIC METHOD ---------------- */

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for(int i = 0; i < MateriaSource::_materiasMax; i++)
	{
		if (this->_materials[i] && this->_materials[i]->getType() == type)
			return (this->_materials[i]->clone());
	}
	return (NULL);
}

void 	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MateriaSource::_materiasMax; i++) {
		if (this->_materials[i] == NULL) {
			this->_materials[i] = m;
			std::cout << L_CYAN "The " NC << m->getType() << L_CYAN " Materia has been learned." NC << std::endl;
			return;
		}
	}
	std::cout << L_CYAN "Can't learn more than " << MateriaSource::_materiasMax << " Materia." NC << std::endl;
}