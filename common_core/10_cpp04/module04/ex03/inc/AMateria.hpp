/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:46:18 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 01:32:01 by Manny            ###   ########.fr       */
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

		AMateria& operator=(const AMateria& rhs);

		std::string const&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

	protected:
		

	private:
		std::string	_type;
};

#endif
