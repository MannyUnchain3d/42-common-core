/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:46:18 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 02:14:59 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria {
	public:
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(const AMateria& rhs);
		virtual ~AMateria(void);

		// Assignation operator not needed

		std::string const&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

	private:
		std::string	_type;
};

#endif
