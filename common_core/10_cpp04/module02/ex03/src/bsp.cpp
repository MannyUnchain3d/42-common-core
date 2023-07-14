/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:33:34 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/15 02:19:54 by etetopat         ###   ########.fr       */
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
	Fixed	totalArea = abs(area(a, b, c));
	Fixed	area1 = abs(area(point, a, b));
	Fixed	area2 = abs(area(point, b, c));
	Fixed	area3 = abs(area(point, c, a));

    Fixed tolerance = 0.0001f;

    // Check if the point is on a vertex of the triangle
    if (area1 < tolerance || area2 < tolerance || area3 < tolerance)
        return false; // Point is not inside the triangle

    // Check if the point is on an edge of the triangle
    if ((area1 + area2 + area3) > (totalArea - tolerance)
		&& (area1 + area2 + area3) < (totalArea + tolerance))
        return false; // Point is not inside the triangle

    // Check if the point is inside the triangle
    return true;
}

/* Examples:

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
Output: Inside

              B(10,30)
                / \
               /   \
              /     \
             /   P   \
            /         \
     A(0,0) ----------- C(20,0)

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
Output: Outside

              B(10,30)
                / \
               /   \
              /     \
             /       \      P
            /         \
     A(0,0) ----------- C(20,0)

*/