/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:00:22 by Manny             #+#    #+#             */
/*   Updated: 2023/07/24 00:25:23 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <cstdlib>

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