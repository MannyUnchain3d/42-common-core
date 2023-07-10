/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:06:54 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/11 01:56:06 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* ----- CONSTRUCTOR ------------------ */

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << "Aaaahhhh! " << this->_getName()  << " is alive!" << std::endl;
}

/* ----- DESTRUCTOR ------------------- */

Zombie::~Zombie(void) {
	std::cout << "Aaaahhhh! " << this->_getName()  << " died for real this time!" << std::endl;
}

/* ----- GETTER ----------------------- */

std::string	Zombie::_getName(void) const {
	return (this->_name);
}

/* ----- PUBLIC METHOD ---------------- */

void	Zombie::announce(void) const {
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}