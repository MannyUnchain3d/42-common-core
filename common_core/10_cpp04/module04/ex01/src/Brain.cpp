/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:20:51 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/25 20:10:48 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Brain.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Brain::Brain(void) {
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Eureka! I have an idea!";
	std::cout << GREEN "[Default Constructor Brain]" NC << " I think... so I am..." << std::endl;
}

/* Copy Constructor */
Brain::Brain(Brain const& rhs) {
	std::string* ideas = rhs.getIdeas();
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[i];
	std::cout << GREEN "[Copy Constructor Brain]" NC << " Copying ideas..." << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

/* Default Deconstructor */
Brain::~Brain(void) {
	delete[] this->_ideas;
	std::cout << GREEN "[Destructor Brain]" NC << " I can't think anymore..." << std::endl;
}

/* ----- OPERATOR OVERLOAD ------------ */

Brain&	Brain::operator=(Brain const& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	std::cout << GREEN "[Assignation Operator Brain]" NC << " Transfering ideas..." << std::endl;
	return (*this);
}

/* ----- GETTER -------------------------- */

std::string*	Brain::getIdeas(void) const {
	return (this->_ideas);
}

/* ----- PUBLIC METHOD ------------------- */

Brain*	Brain::clone(void) const {
	return (new Brain(*this));
}