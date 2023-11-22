/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:09:31 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/22 20:27:09 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "colors.h"

int main()
{
	std::cout << GREEN << "#----- TEST 1 -----#" << NC << std::endl;
	
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//sp.addNumber(42); // Should throw an exception

		std::cout << YELLOW << "List: " << NC << sp << std::endl;
		std::cout << GREEN << "Shortest Span: " << NC << sp.shortestSpan() << std::endl;
		std::cout << RED << "Longest Span: " << NC << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << BLUE << "#----- TEST 2 -----#" << NC << std::endl;
	
	try {
		std::list<int> lst(10000);
		if (lst.size() > 1) {
			std::srand(time(NULL));
			std::generate(lst.begin(), lst.end(), std::rand);
		}
		
		Span sp2(lst.size());
		sp2.addNumber(lst.begin(), lst.end());
		//sp2.addNumber(42); // Should throw an exception
		
		//std::cout << YELLOW << "List 2: " << sp2 << NC << std::endl;
		std::cout << GREEN << "Shortest Span: " << NC << sp2.shortestSpan() << std::endl;
		std::cout << RED << "Longest Span: " << NC << sp2.longestSpan() << std::endl << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	return EXIT_SUCCESS;
}
