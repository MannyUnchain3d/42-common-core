/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:46:18 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 00:43:05 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	public:
		AMateria(std::string const& type);
		AMateria(const AMateria& rhs);
		virtual ~AMateria(void);

		// No assignation operator overload because this abstract class cannot be instanciated

		std::string const&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string	_type;
};

#endif
