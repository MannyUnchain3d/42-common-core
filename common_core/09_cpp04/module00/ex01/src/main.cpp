/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:40:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/06 18:58:04 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

std::string	getInput(PhoneBook* book) {
	std::string input;

	if (!std::getline(std::cin, input) || std::cin.eof()) {
		std::cout << "EXIT" << std::endl;
		return ("EXIT");
	}
	input = book->trimSpace(input);
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = std::toupper(*it);
	return (input);
}

int	main(void) {
	PhoneBook	book;
	std::string	input;

	std::cout << std::endl << BOLD << RED << "📞 42 BANGKOK ANGRY PHONEBOOK ಠ_ಠ╭∩╮" << RESET << std::endl;
	while (true) {
		std::cout	<< std::endl << "Type something... hurry up..." << std::endl << std::endl;
		input = getInput(&book);
		std::cout	<< std::endl;
		if (input == "EXIT")
			break ;
		else if (input == "ADD") {
			if (!book.addContact())
				break ;
		}
		else if (input == "SEARCH") {
			if (!book.searchContact())
				break ;
		}
		else {
			std::cout 	<< BOLD << RED << BLINK << "#---------- MENU FOR DUMMIES ----------#" << RESET << std::endl
						<< std::endl
						<< BOLD << LRED << "ಠ_ಠ Type correctly or go back to school!" << RESET << std::endl
						<< std::endl
						<< BOLD << MAGENTA << BLINK << "\tADD\t" << RESET 		<< ": Do you even have friends?" << std::endl
						<< BOLD << MAGENTA << BLINK << "\tSEARCH\t" << RESET 	<< ": Did you forget your mom's number?" << std::endl
						<< BOLD << MAGENTA << BLINK << "\tEXIT\t" << RESET 		<< ": Come on... Do I have to explain everything?" << std::endl;
		}
	}
	std::cout << std::endl << BOLD << RED << "Finally... (╯°□°）╯︵ ┻━┻" << RESET << std::endl;
	return (0);
}