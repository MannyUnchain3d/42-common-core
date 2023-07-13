/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:11:51 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/13 20:43:33 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ----- CONSTRUCTOR -------------------*/

/* Default Constructor */
Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

/* Copy Constructor */
Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

/* ----- DESTRUCTOR ------------------ */

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/* ----- OPERATOR OVERLOADS ---------- */

Fixed&	Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

/* ----- GETTER ----------------------- */

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

/* ----- SETTER ----------------------- */

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}