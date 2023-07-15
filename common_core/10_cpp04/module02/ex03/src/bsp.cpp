/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:33:34 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/15 17:23:40 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	abs(Fixed x) {
	return (x < 0 ? x * -1 : x);
}

Fixed	area(Point const a, Point const b, Point const c) {
	return (((a.getX() * (b.getY() - c.getY()))
			+ (b.getX() * (c.getY() - a.getY()))
			+ (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	areaTriangle = abs(area(a, b, c));
	Fixed	areaPAB = abs(area(point, a, b));
	Fixed	areaPBC = abs(area(point, b, c));
	Fixed	areaPAC = abs(area(point, a, c));

	return ((areaPAB + areaPBC + areaPAC) == areaTriangle);
}