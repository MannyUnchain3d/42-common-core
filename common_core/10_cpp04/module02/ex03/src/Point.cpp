/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:20:36 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/14 19:14:22 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(Point const& src) : _x(src.getX()), _y(src.getY()) {
}

Point::Point(float const x, float const y) : _x(x), _y(y) {
}

Point::~Point(void) {
}

Point&	Point::operator=(Point const& rhs) {
	if (this != &rhs) {
		(Fixed)this->_x = rhs.getX();
		(Fixed)this->_y = rhs.getY();
	}
	return (*this);
}

Fixed	Point::getX(void) const {
	return (this->_x);
}

Fixed	Point::getY(void) const {
	return (this->_y);
}