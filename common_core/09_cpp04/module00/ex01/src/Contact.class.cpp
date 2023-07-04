/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:41:08 by Manny             #+#    #+#             */
/*   Updated: 2023/07/05 00:26:14 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

/* ----- CONSTRUCTOR ------------------ */

Contact::Contact(void) : _firstname(""),
						 _lastname(""),
						 _nickname(""),
						 _phoneNumber(""),
						 _secret("") {
	return ;
}

/* ----- DESTRUCTOR ------------------- */

Contact::~Contact(void) {
	return ;
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

bool	Contact::setFirstname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_onlyAlpha(str)) {
		std::cout << BOLD << LRED << "Only letters, spaces and hyphens... I don't have time for weird name..." << RESET << std::endl;
		return (false);
	}
	this->_firstname = str;
	return (true);
}

bool	Contact::setLastname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_onlyAlpha(str)) {
		std::cout << BOLD << LRED << "Only letters, spaces and hyphens... I don't have time for weird name..." << RESET << std::endl;
		return (false);
	}
	this->_lastname = str;
	return (true);
}

bool	Contact::setNickname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_onlyAlpha(str)) {
		std::cout << BOLD << LRED << "Only letters, spaces and hyphens... Argghhh! How many time do I have to repeat myself???" << RESET << std::endl;
		return (false);
	}
	this->_nickname = str;
	return (true);
}

bool	Contact::setPhoneNumber(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	else if (!_onlyDigit(str)) {
		std::cout << BOLD << LRED << "Hey! I can play stupid too... Don't try me!" << RESET << std::endl;
		return (false);
	}
	this->_phoneNumber = str;
	return (true);
}

bool	Contact::setSecret(std:: string const str) {
	if (str.empty()) {
		return (false);
	}
	this->_secret = str;
	return (true);
}

/* ----- PRIVATE METHODS -------------- */

bool	Contact::_onlyAlpha(std::string const s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isalpha(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}

bool	Contact::_onlyDigit(std::string const s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (!std::isdigit(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}

/* ----- PUBLIC METHODS --------------- */

bool	Contact::isEmpty(void) const {
	if (this->_firstname.empty()
		|| this->_lastname.empty()
		|| this->_nickname.empty()
		|| this->_phoneNumber.empty()
		|| this->_secret.empty())
		return (true);
	return (false);
}

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