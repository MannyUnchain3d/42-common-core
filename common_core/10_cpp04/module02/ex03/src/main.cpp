/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:20:39 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/15 02:19:19 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void) {
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point point(12, 10);

	if (bsp(a, b, c, point) == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else {
		Fixed area1 = abs(area(point, a, b));
		Fixed area2 = abs(area(point, b, c));
		Fixed area3 = abs(area(point, c, a));
		Fixed totalArea = abs(area(a, b, c));

		Fixed tolerance = 0.0001f;

	  	// Check if the point is on a vertex or an edge of the triangle
        if ((area1 + area2 + area3) > (totalArea - tolerance)
            && (area1 + area2 + area3) < (totalArea + tolerance)) {
            if (area1 < tolerance || area2 < tolerance || area3 < tolerance)
                std::cout << "Point is on a vertex of the triangle" << std::endl;
			else
                std::cout << "Point is on an edge of the triangle" << std::endl;
		}
		else
			std::cout << "Point is outside the triangle" << std::endl;
	}
	return (0);
}