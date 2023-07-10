/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:41:08 by Manny             #+#    #+#             */
/*   Updated: 2023/07/11 01:53:57 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

/* ----- CONSTRUCTOR ------------------ */

Contact::Contact(void) : _firstname(""),
						 _lastname(""),
						 _nickname(""),
						 _phoneNumber(""),
						 _secret("") {
}

/* ----- DESTRUCTOR ------------------- */

Contact::~Contact(void) {
}

/* ----- GETTERS ---------------------- */

/*	Returns the value of the private firstname attribute */
std::string const	Contact::getFirstname(void) const {
	return (this->_firstname);
}

/*	Returns the value of the private lastname attribute */
std::string const	Contact::getLastname(void) const {
	return (this->_lastname);
}

/*	Returns the value of the private nickname attribute */
std::string const	Contact::getNickname(void) const {
	return (this->_nickname);
}

/*	Returns the value of the private phoneNumber attribute */
std::string const	Contact::getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

/*	Returns the value of the private secret attribute */
std::string const	Contact::getSecret(void) const {
	return (this->_secret);
}

/* ----- SETTERS ---------------------- */

/* Sets the value of the private firstname attribute with the given string,
 * except if the string is empty or contains non-alphabetical characters
 * Returns true if the value was set, false otherwise */
bool	Contact::setFirstname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_onlyAlpha(str)) {
		std::cout << BOLD << RED << "Only letters, spaces and hyphens... I don't have time for weird name..." << NC << std::endl;
		return (false);
	}
	this->_firstname = str;
	return (true);
}

/* Sets the value of the private lastname attribute with the given string,
 * except if the string is empty or contains non-alphabetical characters
 * Returns true if the value was set, false otherwise */
bool	Contact::setLastname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_onlyAlpha(str)) {
		std::cout << BOLD << RED << "Only letters, spaces and hyphens... I don't have time for weird name..." << NC << std::endl;
		return (false);
	}
	this->_lastname = str;
	return (true);
}

/* Sets the value of the private nickname attribute with the given string,
 * except if the string is empty or contains non-alphabetical characters
 * Returns true if the value was set, false otherwise */
bool	Contact::setNickname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_onlyAlpha(str)) {
		std::cout << BOLD << RED << "Only letters, spaces and hyphens... Argghhh! How many time do I have to repeat myself???" << NC << std::endl;
		return (false);
	}
	this->_nickname = str;
	return (true);
}

/* Sets the value of the private phoneNumber attribute with the given string,
 * except if the string is empty or contains non-numerical characters
 * Returns true if the value was set, false otherwise */
bool	Contact::setPhoneNumber(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_onlyDigit(str)) {
		std::cout << BOLD << RED << "Hey! I can play stupid too... Don't try me!" << NC << std::endl;
		return (false);
	}
	this->_phoneNumber = str;
	return (true);
}

/* Sets the value of the private secret attribute with the given string,
 * except if the string is empty.
 * Returns true if the value was set, false otherwise */
bool	Contact::setSecret(std:: string const str) {
	if (str.empty()) {
		return (false);
	}
	this->_secret = str;
	return (true);
}

/* ----- PUBLIC METHODS --------------- */

/* Checks if any of the class attributes are empty.
 * Returns true if this instance of Contact is empty, false otherwise */
bool	Contact::isEmpty(void) const {
	if (this->_firstname.empty()
		|| this->_lastname.empty()
		|| this->_nickname.empty()
		|| this->_phoneNumber.empty()
		|| this->_secret.empty())
		return (true);
	return (false);
}

/* Prints the contact information of this instance of Contact.
 * Returns true if the information was printed, false otherwise */
bool	Contact::printContactInfo(void) const {
	if (this->isEmpty())
		return (false);
	std::cout 	<< std::endl;
	std::cout	<< "* Firstname\t: "		<< this->getFirstname()		<< std::endl
				<< "* Lastname\t: "			<< this->getLastname()		<< std::endl
				<< "* Nickname\t: "			<< this->getNickname()		<< std::endl
				<< "* Phone Number\t: "		<< this->getPhoneNumber()	<< std::endl
				<< "* Darkest Secret: "		<< this->getSecret()		<< std::endl;
	return (true);
}

/* ----- PRIVATE METHODS -------------- */

/* Checks if the given string contains only alphabetical characters, spaces and hyphens.
 * Returns true if the string is valid, false otherwise */
bool	Contact::_onlyAlpha(std::string const s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isalpha(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}

/* Checks if the given string contains only numerical characters, spaces and hyphens.
 * Returns true if the string is valid, false otherwise */
bool	Contact::_onlyDigit(std::string const s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isdigit(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}