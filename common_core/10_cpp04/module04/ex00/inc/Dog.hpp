/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:36:41 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/23 23:53:09 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <cstdlib>

# ifdef __linux__
# define PLAY_DOG "aplay ../sfx/dog.wav 2> /dev/null"
# else
# define PLAY_DOG "afplay ../sfx/dog.wav 2> /dev/null"
# endif

class	Dog : public Animal {
	public:
		Dog(void);
		Dog(Dog const& rhs);
		~Dog(void);

		Dog&	operator=(Dog const& rhs);

	protected:
		void		makeSound(void) const;
};

#endif