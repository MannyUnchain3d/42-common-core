/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:47:49 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/24 00:12:37 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#include "colors.h"

#include <iostream>

int main(void) {
	std::cout << RED "--------------- Animal ---------------" NC << std::endl;
	const Animal*	meta = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << std::endl;

	std::cout <<"dog type: " << BLUE << dog->getType() << " " NC << std::endl;
	std::cout <<"cat type: " << MAGENTA << cat->getType() << " " NC << std::endl;

	std::cout << std::endl;
	
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl;
	
	std::cout << RED "--------------- Wrong Animal ---------------" NC << std::endl;

	const WrongAnimal*	wrongCat = new WrongCat();
	WrongCat nani = WrongCat();

	std::cout << std::endl;

	std::cout <<"wrongCat type: " << RED << wrongCat->getType() << NC << std::endl;
	std::cout <<"nani type: " << RED << nani.getType() << NC << std::endl;

	std::cout << std::endl;

	wrongCat->makeSound();
	nani.makeSound();

	delete wrongCat;

	return 0;
}