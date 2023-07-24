/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:36:41 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/21 20:27:04 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <cstdlib>

# include "Animal.hpp"

# ifdef __linux__
# define PLAY_CAT "aplay ../sfx/cat.wav 2> /dev/null"
# else
# define PLAY_CAT "afplay ../sfx/cat.wav 2> /dev/null"
# endif

class	Cat : public Animal {
	public:
		Cat(void);
		Cat(Cat const& rhs);
		virtual ~Cat(void);

		Cat&	operator=(Cat const& rhs);

	protected:
		void	makeSound(void) const;
};

#endif