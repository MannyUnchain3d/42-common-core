/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:27:04 by Manny             #+#    #+#             */
/*   Updated: 2023/11/19 22:45:40 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Serializer.hpp"

int	main(void) {
	Data	save;

	std::cout << BLUE << "----- Raw Data -----" << NC << std::endl;
	save.name = "Manny";
	save.level = 42;

	std::cout << "Name: " << save.name << std::endl;
	std::cout << "Level: " << save.level << std::endl << std::endl;
	
	std::cout << YELLOW << "----- Serialized -----" << NC << std::endl;
	
	uintptr_t	serialized = Serializer::serialize(&save);
	std::cout << serialized << std::endl << std::endl;

	std::cout << GREEN << "----- Deserialized -----" << NC << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Name: " << deserialized->name << std::endl;
	std::cout << "Level: " << deserialized->level << std::endl;

	return (0);
}