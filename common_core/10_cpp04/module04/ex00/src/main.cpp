/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:47:49 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/24 21:45:31 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.h"

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

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