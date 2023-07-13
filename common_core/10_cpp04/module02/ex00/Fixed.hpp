/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:08:38 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/13 20:42:47 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"
# define BLINK		"\033[5m"
# define NC			"\033[0m"
class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const& src);
		~Fixed(void);
		Fixed	&operator=(Fixed const& rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

#endif