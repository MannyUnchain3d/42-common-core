/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:01:13 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 01:15:34 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice(void);
		Ice(std::string name);
		Ice(const Ice& rhs);
		virtual ~Ice(void);

		Ice& operator=(const Ice& rhs);

	protected:
		void	use(ICharacter& target);

	private:
		std::string	_type;
};

#endif
