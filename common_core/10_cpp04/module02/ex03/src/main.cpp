/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:20:39 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/15 17:35:43 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	pointOnEdge(Point const point, Point const vertex1, Point const vertex2) {
	Fixed	area1 = abs(area(point, vertex1, vertex2));
	Fixed	area2 = abs(area(point, vertex2, vertex1));
	Fixed	totalArea = abs(area(vertex1, vertex2, point));
	
	Fixed	tolerance = 0.0001f;

	return (area1 <= tolerance && area2 <= tolerance && (area1 + area2) <= (totalArea + tolerance));
}

int	main(void) {
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point point(30, 15);

	if (bsp(a, b, c, point) == true) {
		if (point == a || point == b || point == c)
			std::cout << "Point is on a vertex" << std::endl;
		else if (pointOnEdge(point, a, b) || pointOnEdge(point, b, c) || pointOnEdge(point, a, c))
			std::cout << "Point is on an edge" << std::endl;
		else
		std::cout << "Point is inside the triangle" << std::endl;
	}
	else
		std::cout << "Point is outside the triangle" << std::endl;
	return (0);
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
						 /       \      P(30,15)
						/         \
				 A(0,0) ----------- C(20,0)

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(0, 0)
Output: On a vertex

						B(10,30)
							/ \
						   /   \
						  /     \
						 /       \
						/         \
			   A/P(0,0) ----------- C(20,0)

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(5, 0)
Output: On an edge

						B(10,30)
							/ \
						   /   \
						  /     \
						 /       \
						/         \
				 A(0,0) --P------- C(20,0)

*/