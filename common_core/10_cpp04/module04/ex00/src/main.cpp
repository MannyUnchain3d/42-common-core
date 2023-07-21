/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:47:49 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/21 22:51:00 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "colors.h"

#include <iostream>

int	main(void) {
	Animal*	animal = new Animal("Animal");
	Animal*	dog = new Dog("Dog");

	std::cout << std::endl;

	std::cout << "Animal Type: " << animal->getType() << std::endl;
	std::cout << "Dog Type: " << dog->getType() << std::endl;

	std::cout << std::endl;

	animal->makeSound();
	dog->makeSound();
	
	std::cout << std::endl;

	delete animal;
	delete dog;

return 0;
}