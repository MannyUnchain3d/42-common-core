/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:49:32 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/13 22:55:15 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ----- CONSTRUCTOR(S) -------------------*/

/* Default Constructor */
Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

/* Copy Constructor */
Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}


/* ----- DESTRUCTOR ------------------ */

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/* ----- OPERATOR OVERLOAD ---------- */

Fixed&	Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

/* ----- GETTER ----------------------- */

int		Fixed::getRawBits(void) const {
	return (this->_fixedPointValue);
}

/* ----- SETTER ----------------------- */

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

/* ----- PUBLIC METHOD --------------- */

int		Fixed::toInt(void) const {
	return (this->_fixedPointValue >> this->_fractionalBits);
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

/* ----- EXTERNAL FUNCTION ----------- */

std::ostream&	operator<<(std::ostream& out, Fixed const& rhs) {
	out << rhs.toFloat();
	return (out);
}