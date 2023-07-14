/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:33:34 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/14 19:20:10 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed x) {
	return (x < 0 ? x * -1 : x);
}

static Fixed	area(Point const a, Point const b, Point const c) {
	return (((a.getX() * (b.getY() - c.getY()))
			+ (b.getX() * (c.getY() - a.getY()))
			+ (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	totalArea = abs(area(a, b, c));
	Fixed	area1 = abs(area(point, a, b));
	Fixed	area2 = abs(area(point, b, c));
	Fixed	area3 = abs(area(point, c, a));

	return (totalArea == (area1 + area2 + area3));
}