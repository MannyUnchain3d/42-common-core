/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:41:16 by Manny             #+#    #+#             */
/*   Updated: 2023/07/11 01:54:17 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

/* ----- CONSTRUCTOR ------------------ */

PhoneBook::PhoneBook(void) : _index(-1),
							 _abort(false) {
}

/* ----- DESTRUCTOR ------------------- */

PhoneBook::~PhoneBook(void) {
}

/* ----- PUBLIC METHODS --------------- */

/* Trims the given string of whitespaces and tabs
 * Returns the trimmed string or the original string if there is nothing to trim */
std::string	PhoneBook::trimSpace(std::string str) {
	std::string	space = " \t\n\r\v\f";
	size_t		start;
	size_t		end;

	start = str.find_first_not_of(space);
	end = str.find_last_not_of(space);
	if (start == end)
		return (str);
	return (str.substr(start, end - start + 1));
}

/* Adds a contact to the next index of the list. Prompts the user to enter
 * the information of the contact. Aborts if EOF is encountered.
 * Returns true if the contact was successfully added, false otherwise. */
bool	PhoneBook::addContact(void) {
	std::string	input;
	
	_incrementIndex();
	std::cout << std::endl << BOLD << RED << BLINK << "#---------- ADD CONTACT ----------#" << NC << std::endl << std::endl;
	while (!_abort) {
		input = _getInput("firstname");
		if (_abort || this->_list[_index].setFirstname(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("lastname");
		if (_abort || this->_list[_index].setLastname(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("nickname");
		if (_abort || this->_list[_index].setNickname(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("phone number");
		if (_abort || this->_list[_index].setPhoneNumber(input))
			break ;
	}
	while (!_abort) {
		input = _getInput("darkest secret");
		if (_abort || this->_list[_index].setSecret(input))
			break ;
	}
	if (_abort) {
		_abort = false;
		return (false);
	}
	std::cout << std::endl << BOLD << GREEN << "Contact saved... Whatever... " << NC << std::endl;
	return (true);
}

/* Searches for a contact by index. Prompts the user to enter the index.
 * If the index is valid, it prints the information of the contact. Otherwise, it prints an error message.
 * Returns true if the contact was successfully printed, false otherwise. */
bool	PhoneBook::searchContact(void) {
	std::string	input;

	std::cout << std::endl << BOLD << RED << BLINK << "#---------- SEARCH ----------#" << NC << std::endl << std::endl;
	if (_index == -1) {
		std::cout << BOLD << RED << "ADD a contact first you dumb dumb..." << NC << std::endl;
		return (true);
	}
	this->_printTable();
	while (true) {
		input = _getInput("index of the contact (between 0 and 7)");
		if (!input.empty()) {
			this->_printContactByIndex((std::string const)input);
			break ;
		}
	}
	return (true);
}

/* ----- PRIVATE METHODS -------------- */

/* Prompts the user to enter a string and returns it trimmed of whitespaces
 * and tabs. If the user enters an empty string or EOF, the `_abort` flag is set
 * to true and it returns an empty string. */
std::string	PhoneBook::_getInput(std::string const prompt) {
	std::string	input;

	std::cout	<< "Enter the " << prompt << ": " << std::endl << "> ";
	if (!std::getline(std::cin, input) || std::cin.eof()) {
		_abort = true;
		std::cout << std::endl;
		return (std::string());
	}
	input = trimSpace(input);
	return (input);
}

/* Increments the `_index` attribute and resets it to 0 if it goes over 7 */
void	PhoneBook::_incrementIndex(void) {
	_index++;
	if (_index > 7) {
		_index = 0;
	}
}

/* Prints the table of contacts */
void	PhoneBook::_printTable(void) const {
	std::cout << YELLOW << "#----------+----------+----------+----------#" << std::endl
						<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
						<< "#----------+----------+----------+----------#" << NC << std::endl;
	for (int i = 0; i < 8; i++) {
		_printInfo(i);
	}
	std::cout << std::endl;
}

/* Prints the information of a contact at the given index.
 * If the contact is empty, it does nothing. */
void	PhoneBook::_printInfo(int const index) const {
	if (this->_list[index].isEmpty())
		return ;
	std::cout 	<< YELLOW << "|" << NC << std::setw(10) << index << YELLOW << "|" << NC;
	_printTableString(this->_list[index].getFirstname());
	_printTableString(this->_list[index].getLastname());
	_printTableString(this->_list[index].getNickname());
	std::cout 	<< std::endl
				<< YELLOW << "#----------+----------+----------+----------#" << NC << std::endl;
}

/* Prints a string in a 10 characters wide column. If the string is too long,
 * it is truncated to 9 characters and a dot is added at the end.
 * If the string is empty, it does nothing. */
void	PhoneBook::_printTableString(std::string str) const {
	if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << YELLOW << "|" << NC;
}

/* Prints the information of a contact at the given index is valid.
 * If the contact is empty, it prints an error message and returns false. */
bool	PhoneBook::_printContactByIndex(std::string const input) const {
	int	index;

	if (input.length() == 1 && std::isdigit(input[0])) {
		index = input[0] - '0';
		if (index >= 0 && index <= 7) {
			if (this->_list[index].printContactInfo())
				return (true);
			else {
				std::cout << std::endl << BOLD << RED << "Index [" << index << "] is empty, like your head..." << NC << std::endl;
				return (false);
			}
		}
	}
	std::cout << std::endl << BOLD << RED << "Back to the menu because you can't count..." << NC << std::endl;
	return (false);
}