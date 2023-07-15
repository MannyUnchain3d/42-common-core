/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:41:33 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/15 17:03:36 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {
	public:
		Point(void);
		Point(Point const& src);
		Point(float const x, float const y);
		~Point(void);

		Point&	operator=(Point const& src);
		bool	operator==(Point const& rhs) const;

		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
Fixed	abs(Fixed x);
Fixed	area(Point const a, Point const b, Point const c);

#endif