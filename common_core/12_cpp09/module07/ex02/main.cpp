/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:36:24 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/20 21:41:06 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include "colors.h"

int main() {
	std::cout << GREEN << "#----- ARRAY OF INT -------#" << NC << std::endl;
	{
		Array<int>* intArray = new Array<int>(5);

		try {
			for (unsigned int i = 0; i < intArray->size(); ++i)
				(*intArray)[i] = static_cast<int>(i);
			intArray->print();
		} catch (std::exception &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		delete intArray;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "#----- ARRAY OF FLOAT -----#" << NC << std::endl;
	{
		Array<float> floatArray(5);

		try {
			for (unsigned int i = 0; i < floatArray.size(); ++i)
				floatArray[i] = i * 3.0f;
			floatArray.print();
		} catch (std::exception &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << BLUE << "#----- ARRAY OF STRING ----#" << NC << std::endl;
	{
		Array<std::string> strArray(2);

		try {
			strArray[0] = "HELLO";
			strArray[1] = "WORLD";
			strArray.print();
		} catch (std::exception &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	// std::cout << RED << "#----- ARRAY OF DOUBLE ----#" << NC << std::endl;
	// {
	// 	Array<double>  dblArray;

	// 	try {
	// 		std::cout <<  dblArray[0] << std::endl;
	// 	} catch (std::exception &e) {
	// 		std::cout << "Exception caught: " << e.what() << std::endl;
	// 	}
	// }

	return 0;
}