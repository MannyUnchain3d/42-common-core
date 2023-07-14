/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:41:33 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/15 01:47:21 by etetopat         ###   ########.fr       */
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