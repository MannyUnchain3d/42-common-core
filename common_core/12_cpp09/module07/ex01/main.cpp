/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:05:37 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/20 19:26:40 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "colors.h"

int main(void) {
	std::cout << GREEN << "#----- INT ARRAY ---------#" << NC << std::endl;
	int array[] = {1, 2, 3, 4, 5};
	::iter(array, 5, print<int>);
	std::cout << std::endl << std::endl;
	
	std::cout << YELLOW << "#----- STRING ARRAY ------#" << NC <<std::endl;
	std::string array2[] = {"Hello", "42", "Bangkok"};
	::iter(array2, 3, print<std::string>);
	std::cout << std::endl << std::endl;
	
	std::cout << BLUE << "#----- FLOAT ARRAY -------#" << NC << std::endl;
	float array3[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	::iter(array3, 5, print<float>);
	std::cout << std::endl << std::endl;
	
	return (0);
}
