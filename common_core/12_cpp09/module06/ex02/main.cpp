/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:28:43 by Manny             #+#    #+#             */
/*   Updated: 2023/11/19 23:47:27 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include "colors.h"

int main() {
	// Seed the random number generator
	std::srand(static_cast<unsigned int>(std::time(0)));

	const int numObjects = 10;

	for (int i = 0; i < numObjects; ++i) {
		Base* obj = generate();

		std::cout << GREEN << "Object " << i + 1 << " (using pointer): ";
		identify(obj);
		std::cout << L_BLUE << "Object " << i + 1 << " (using reference): ";
		identify(*obj);
		delete obj;
	}
	std::cout << NC;
	return (0);
}