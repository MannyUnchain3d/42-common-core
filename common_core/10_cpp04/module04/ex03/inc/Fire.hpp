/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:01:13 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 20:13:21 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
# define FIRE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Fire : public AMateria {
	public:
		Fire(void);
		Fire(Fire const& rhs);
		~Fire(void);

		Fire& operator=(Fire const& rhs);
		
		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif
