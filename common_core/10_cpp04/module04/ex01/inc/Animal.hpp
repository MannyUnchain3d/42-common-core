/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:36:41 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/25 02:50:20 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <cstdlib>

# include "Brain.hpp"

# ifdef __linux__
# define PLAY_WOW "aplay ../sfx/wow.wav 2> /dev/null"
# else
# define PLAY_WOW "afplay ../sfx/wow.wav 2> /dev/null"
# endif

class	Animal : public Brain {
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