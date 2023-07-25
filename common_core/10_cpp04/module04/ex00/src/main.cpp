/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:47:49 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/25 20:45:04 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.h"

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void) {
	std::cout << RED "/ -------------------- Animal ------------------- /" NC << std::endl;
	const Animal*	meta = new Animal();
	std::cout << std::endl;

	const Animal*	dog = new Dog();
	std::cout << std::endl;

	const Animal*	cat = new Cat();
	std::cout << std::endl;

	std::cout <<"dog type: " << BLUE << dog->getType() << " " NC << std::endl;
	std::cout <<"cat type: " << MAGENTA << cat->getType() << " " NC << std::endl;

	std::cout << std::endl;
	
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete cat;
	delete dog;
	delete meta;

	std::cout << std::endl;
	
	std::cout << RED "/ ----------------- WrongAnimal ----------------- /" NC << std::endl;

	const WrongAnimal*	fox = new WrongCat();
	std::cout << std::endl;

	WrongCat nani = WrongCat();
	std::cout << std::endl;

	std::cout <<"fox type: " << RED << fox->getType() << NC << std::endl;
	std::cout <<"nani type: " << RED << nani.getType() << NC << std::endl;
	std::cout << std::endl;

	fox->makeSound();
	nani.makeSound();

	delete fox;
	
	return 0;
}