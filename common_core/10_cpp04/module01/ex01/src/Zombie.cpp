/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:06:54 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/11 01:59:26 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

Zombie::Zombie(void) {
	std::cout << "Aaaahhhh! A zombie is alive!" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Aaaahhhh! " << this->_getName() << " died for real this time!" << std::endl;
}

/* ************************ GETTERS / SETTERS ******************************* */

std::string	Zombie::_getName(void) const {
	return (this->_name);
}

void	Zombie::setName(std::string const name) {
	this->_name = name;
}

/* ************************ PUBLIC METHODS ********************************** */

void	Zombie::announce(void) const {
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}