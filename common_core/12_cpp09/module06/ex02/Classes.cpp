/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:18:15 by Manny             #+#    #+#             */
/*   Updated: 2023/11/19 23:34:49 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>


/* ----- DESTRUCTOR ------------------- */

Base::~Base(void) {}

/* ----- PUBLIC METHOD ---------------- */

Base* generate(void) {
	int	randNum = rand() % 3;
	switch (randNum) {
		case 0 : return new A;
		case 1 : return new B;
		case 2 : return new C;
		default : return NULL; // Should never happen
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown Type" << std::endl;
}

void	identify(Base& p) {
	try {
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
	} catch (std::exception& e) {
		try {
			static_cast<void>(dynamic_cast<B&>(p));
			std::cout << "B" << std::endl;
		} catch (std::exception& e) {
			try {
				static_cast<void>(dynamic_cast<C&>(p));
				std::cout << "C" << std::endl;
			} catch (std::exception& e) {
				std::cout << "Unknown Type" << std::endl;
			}
		}
	}
}