/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:04:14 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/14 16:45:58 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const& src);
		~Fixed(void);
		Fixed&	operator=(Fixed const& rhs);

		bool	operator>(Fixed const& rhs);
		bool	operator<(Fixed const& rhs);
		bool	operator>=(Fixed const& rhs);
		bool	operator<=(Fixed const& rhs);
		bool	operator==(Fixed const& rhs);
		bool	operator!=(Fixed const& rhs);

		Fixed	operator+(Fixed const& rhs);
		Fixed	operator-(Fixed const& rhs);
		Fixed	operator*(Fixed const& rhs);
		Fixed	operator/(Fixed const& rhs);

		Fixed&	operator++(void);	// prefix
		Fixed	operator++(int);	// postfix
		Fixed&	operator--(void);	// prefix
		Fixed	operator--(int);	// postfix

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static Fixed const&	min(Fixed const& a, Fixed const& b);
		static Fixed const&	max(Fixed const& a, Fixed const& b);

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream& out, Fixed const& rhs);

#endif