/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:41:16 by Manny             #+#    #+#             */
/*   Updated: 2023/07/05 00:15:49 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.class.hpp"

/* ----- CONSTRUCTOR ------------------ */

PhoneBook::PhoneBook(void) : _index(-1),
							 _abort(false) {
	return ;
}

/* ----- DESTRUCTOR ------------------- */

PhoneBook::~PhoneBook(void) {
	return ;
}

/* ----- PRIVATE METHODS -------------- */

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

void	PhoneBook::_incrementIndex(void) {
	_index++;
	if (_index > 7) {
		_index = 0;
	}
}

void	PhoneBook::_printTable(void) const {
	std::cout << YELLOW << "#----------+----------+----------+----------#" << std::endl
						<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
						<< "#----------+----------+----------+----------#" << RESET << std::endl;
	for (int i = 0; i < 8; i++) {
		_printInfo(i);
	}
	std::cout << std::endl;
}

void	PhoneBook::_printInfo(int const index) const {
	if (this->_list[index].isEmpty())
		return ;
	std::cout 	<< YELLOW << "|" << RESET << std::setw(10) << index << YELLOW << "|" << RESET;
	_printTableString(this->_list[index].getFirstname());
	_printTableString(this->_list[index].getLastname());
	_printTableString(this->_list[index].getNickname());
	std::cout 	<< std::endl
				<< YELLOW << "#----------+----------+----------+----------#" << RESET << std::endl;
}

void	PhoneBook::_printTableString(std::string str) const {
	if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << YELLOW << "|" << RESET;
}

bool	PhoneBook::_printContactByIndex(std::string const input) const {
	int	index;

	if (input.length() == 1 && std::isdigit(input[0])) {
		index = input[0] - '0';
		if (index >= 0 && index <= 7) {
			if (this->_list[index].printContactInfo())
				return (true);
			else {
				std::cout << BOLD << LRED << "Index [" << index << "] is empty, like your head..." << RESET << std::endl;
				return (false);
			}
		}
	}
	std::cout << std::endl << BOLD << LRED << "Back to the menu because you can't count..." << RESET << std::endl;
	return (false);
}

/* ----- PUBLIC METHODS --------------- */

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

bool	PhoneBook::addContact(void) {
	std::string	input;
	
	_incrementIndex();
	std::cout << std::endl << BOLD << RED << BLINK << "#---------- ADD CONTACT ----------#" << RESET << std::endl << std::endl;
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
	std::cout << std::endl << BOLD << GREEN << "Contact saved... Whatever... " << RESET << std::endl;
	return (true);
}

bool	PhoneBook::searchContact(void) {
	std::string	input;

	std::cout << std::endl << BOLD << RED << BLINK << "#---------- SEARCH ----------#" << RESET << std::endl << std::endl;
	if (_index == -1) {
		std::cout << BOLD << LRED << "ADD a contact first you dumb dumb..." << RESET << std::endl;
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

void	PhoneBook::printContact(int index) const {
	if (index >= 0 && index <= 7) {
		if (this->_list[index].printContactInfo())
			return ;
	}
	std::cout << BOLD << LRED << "No contact... Congrats! You have 0 friends!" << RESET << std::endl;
}