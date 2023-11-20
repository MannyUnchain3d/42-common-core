/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:18:37 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/20 18:58:24 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "colors.h"

int main (void) {
	int a = 2;
	int b = 3;

	std::cout << GREEN << "# ---------- DATA ------------- #\n" << NC;
	std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;
	
	std::cout << YELLOW << "# ---------- SWAP ------------- #\n" << NC;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;
	
	std::cout << BLUE << "# ---------- MIN MAX ---------- #\n" << NC;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl << std::endl;

	std::cout << GREEN << "# ---------- DATA ------------- #\n" << NC;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;
	
	std::cout << YELLOW << "# ---------- SWAP ------------- #\n" << NC;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;
	
	std::cout << BLUE << "# ---------- MIN MAX ---------- #\n" << NC;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl << std::endl;

	return (0);
}
