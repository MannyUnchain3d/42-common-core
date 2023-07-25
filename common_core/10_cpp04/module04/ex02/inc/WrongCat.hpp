/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:00:22 by Manny             #+#    #+#             */
/*   Updated: 2023/07/24 21:44:06 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <cstdlib>

# include "WrongAnimal.hpp"

# ifdef __linux__
# define PLAY_WTF_CAT "aplay ../sfx/nani.wav 2> /dev/null"
# else
# define PLAY_WTF_CAT "afplay ../sfx/nani.wav 2> /dev/null"
# endif

class	WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(WrongCat const& rhs);
		virtual ~WrongCat(void);

		WrongCat&	operator=(WrongCat const& rhs);
		void		makeSound(void) const;
};

#endif