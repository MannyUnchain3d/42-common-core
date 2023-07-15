/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:20:36 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/15 17:01:28 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ----- CONSTRUCTOR -------------------*/

/* Default Constructor */
Point::Point(void) : _x(0), _y(0) {
}

/* Copy Constructor */
Point::Point(Point const& src) : _x(src.getX()), _y(src.getY()) {
}

/* Constructor with parameters */
Point::Point(float const x, float const y) : _x(x), _y(y) {
}

/* ----- DESTRUCTOR ------------------ */

Point::~Point(void) {
}

/* ----- OPERATOR OVERLOAD ---------- */

Point&	Point::operator=(Point const& rhs) {
	if (this != &rhs) {
		(Fixed)this->_x = rhs.getX();
		(Fixed)this->_y = rhs.getY();
	}
	return (*this);
}

bool	Point::operator==(Point const& rhs) const {
	return (this->_x == rhs._x && this->_y == rhs._y);
}

/* ----- GETTER ----------------------- */

Fixed	Point::getX(void) const {
	return (this->_x);
}

Fixed	Point::getY(void) const {
	return (this->_y);
}