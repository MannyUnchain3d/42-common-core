/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:08:38 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/14 23:22:10 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const& src);
		~Fixed(void);

		Fixed&	operator=(Fixed const& rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

#endif