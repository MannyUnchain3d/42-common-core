/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:36:41 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/23 23:10:27 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <cstdlib>

# ifdef __linux__
# define PLAY_WOW "aplay ../sfx/wow.wav 2> /dev/null"
# else
# define PLAY_WOW "afplay ../sfx/wow.wav 2> /dev/null"
# endif

class	Animal {
	public:
		Animal(void);
		Animal(Animal const& rhs);
		virtual ~Animal(void);

		Animal&	operator=(Animal const& rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string		_type;
};

#endif