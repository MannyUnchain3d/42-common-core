/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:42:51 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 02:58:38 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "MateriaSource.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
MateriaSource::MateriaSource(void) {
	for(int i = 0; i < MateriaSource::_materiasMax; i++)
		this->_materias[i] = NULL;
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
		delete this->_materias[i];
	std::cout << L_CYAN "[MateriaSource Destructor] A MateriaSource has been destroyed." NC << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	if (this != &rhs)
	{
		for(int i = 0; i < MateriaSource::_materiasMax; i++)
			this->_materias[i] = rhs._materias[i];
	}
	std::cout << L_CYAN "[MateriaSource Assignation Operator] A MateriaSource has been assigned." NC << std::endl;
	return (*this);
}

/* ----- GETTER ----------------------- */

AMateria*	MateriaSource::getMaterial(std::string const& type) {
	for(int i = 0; i < MateriaSource::_materiasMax; i++)
	{
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
			return (this->_materias[i]);
	}
	return (NULL);
}

/* ----- PUBLIC METHOD ---------------- */

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for(int i = 0; i < MateriaSource::_materiasMax && this->_materias[i]; i++) {
		if (this->_materias[i]->getType() == type) {
			//std::cout << L_CYAN "The " NC << type << L_CYAN " Materia has been created." NC << std::endl;
			return (this->_materias[i]->clone());
		}
	}
	return (NULL);
}

void 	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MateriaSource::_materiasMax; i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = m;
			std::cout << L_CYAN "The " NC << m->getType() << L_CYAN " Materia has been learned." NC << std::endl;
			return;
		}
	}
	std::cout << L_CYAN "Can't learn more than " << MateriaSource::_materiasMax << " Materia." NC << std::endl;
}