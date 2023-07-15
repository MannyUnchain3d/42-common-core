/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:04:05 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/15 20:52:40 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ----- CONSTRUCTOR(S) -------------------*/

/* Default Constructor */
Fixed::Fixed(void){
	this->_fixedPointValue = 0;
}

/* Copy Constructor */
Fixed::Fixed(Fixed const& src) {
	*this = src;
}

/* Parameter Constructor */
Fixed::Fixed(int const value) {
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(float const value) {
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

/* ----- DESTRUCTOR ------------------ */

Fixed::~Fixed(void) {
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

/* ----- OPERATOR OVERLOAD ---------- */

/* Assignment Operator */
Fixed&	Fixed::operator=(Fixed const& rhs) {
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

/* Comparison Operator */
bool	Fixed::operator>(Fixed const& rhs) {
	return (this->_fixedPointValue > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const& rhs) {
	return (this->_fixedPointValue < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const& rhs) {
	return (this->_fixedPointValue >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const& rhs) {
	return (this->_fixedPointValue <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const& rhs) {
	return (this->_fixedPointValue == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const& rhs) {
	return (this->_fixedPointValue != rhs.getRawBits());
}

/* Arithmetic Operator */
Fixed	Fixed::operator+(Fixed const& rhs) {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const& rhs) {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const& rhs) {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const& rhs) {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

/* Increment operator */
Fixed&	Fixed::operator++(void) {
	this->_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

/* Decrement operator */
Fixed&	Fixed::operator--(void) {
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

/* ----- STATIC METHOD -------------- */
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

/* ----- EXTERNAL FUNCTION ----------- */

/* Output stream operator */
std::ostream&	operator<<(std::ostream& out, Fixed const& rhs) {
	out << rhs.toFloat();
	return (out);
}