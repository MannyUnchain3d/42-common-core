/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:06:54 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/06 23:40:19 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* ----- CONSTRUCTOR ------------------ */

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << "Aaaahhhh! " << this->_getName()  << " is alive!" << std::endl;
	return ;
}

/* ----- DESTRUCTOR ------------------- */

Zombie::~Zombie(void) {
	std::cout << "Aaaahhhh! " << this->_getName()  << " died for real this time!" << std::endl;
	return ;
}

/* ----- GETTER ----------------------- */

std::string	Zombie::_getName(void) const {
	return (this->_name);
}

/* ----- PUBLIC METHOD ---------------- */

void	Zombie::announce(void) const {
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}