/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 06:16:01 by Manny             #+#    #+#             */
/*   Updated: 2023/07/25 06:18:02 by Manny            ###   ########.fr       */
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
		virtual void	makeSound(void) const = 0;

	protected:
		std::string		_type;
};

#endif