/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:36:41 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/25 15:25:04 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <cstdlib>

# include "Animal.hpp"
# include "Brain.hpp"

# ifdef __linux__
# define PLAY_DOG "aplay ../sfx/dog.wav 2> /dev/null"
# else
# define PLAY_DOG "afplay ../sfx/dog.wav 2> /dev/null"
# endif

class	Dog : public Animal {
	public:
		Dog(void);
		Dog(Dog const& rhs);
		virtual ~Dog(void);

		Dog&	operator=(Dog const& rhs);
		Brain*	getBrain(void) const;


	protected:
		void	makeSound(void) const;

	private:
		Brain*	_brain;
};

#endif