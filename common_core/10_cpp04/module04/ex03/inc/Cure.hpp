/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:01:05 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 20:13:13 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(Cure const& rhs);
		~Cure(void);

		Cure& operator=(Cure const& rhs);
		
		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif
