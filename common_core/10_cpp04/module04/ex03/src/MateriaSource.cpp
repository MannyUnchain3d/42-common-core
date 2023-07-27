/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:42:51 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 23:25:06 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "MateriaSource.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
MateriaSource::MateriaSource(void) : _nbMateriasLearned(0) {
	for(int i = 0; i < MateriaSource::_materiasMax; i++)
		this->_materias[i] = NULL;
	std::cout << CYAN "[MateriaSource Default Constructor] The MateriaSource has been created." NC << std::endl;
}

/* Copy Constructor */
MateriaSource::MateriaSource(const MateriaSource& rhs) {
	*this = rhs;
	std::cout << CYAN "[MateriaSource Copy Constructor] An existing MateriaSource has been copied." NC << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

MateriaSource::~MateriaSource(void) {
	for(int i = 0; i < MateriaSource::_materiasMax; i++)
		delete this->_materias[i];
	std::cout << CYAN "[MateriaSource Destructor] A MateriaSource has been destroyed." NC << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	if (this != &rhs) {
		for(int i = 0; i < MateriaSource::_materiasMax; i++) {
			delete this->_materias[i];
			this->_materias[i] = rhs._materias[i] ? rhs._materias[i]->clone() : NULL;
		}
	}
	std::cout << CYAN "[MateriaSource Assignation Operator] A MateriaSource has been assigned." NC << std::endl;
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for(int i = 0; i < MateriaSource::_materiasMax && this->_materias[i]; i++) {
		if (this->_materias[i]->getType() == type) {
			//std::cout << CYAN "The " NC << type << CYAN " Materia has been created." NC << std::endl;
			return (this->_materias[i]);
		}
	}
	return (NULL);
}

void 	MateriaSource::learnMateria(AMateria* m) {
	if (this->_nbMateriasLearned >= MateriaSource::_materiasMax) {
		std::cout << CYAN "Can't learn more than " << MateriaSource::_materiasMax << " Materia." NC << std::endl;
		delete m;
		return;
	} else {
		for (int i = 0; i < MateriaSource::_materiasMax; i++) {
			if (this->_materias[i] == NULL) {
				this->_materias[i] = m;
				this->_nbMateriasLearned++;
				//std::cout << CYAN "The " NC << m->getType() << CYAN " Materia has been learned." NC << std::endl;
				return;
			}
		}
	}
}