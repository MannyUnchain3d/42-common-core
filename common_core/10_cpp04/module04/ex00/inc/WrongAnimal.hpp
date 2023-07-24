/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:52:00 by Manny             #+#    #+#             */
/*   Updated: 2023/07/24 19:22:00 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <cstdlib>

# ifdef __linux__
# define PLAY_WTF "aplay ../sfx/wtf.wav 2> /dev/null"
# else
# define PLAY_WTF "afplay ../sfx/wtf.wav 2> /dev/null"
# endif

class	WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const& rhs);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(WrongAnimal const& rhs);

		std::string		getType(void) const;
		void	makeSound(void) const; // not virtual to prove that it's not polymorphic

	protected:
		std::string		_type;
};

#endif