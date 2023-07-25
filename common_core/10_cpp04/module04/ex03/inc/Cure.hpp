/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:01:05 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 01:15:24 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(std::string name);
		Cure(const Cure& rhs);
		virtual ~Cure(void);

		Cure& operator=(const Cure& rhs);

	protected:
		void	use(ICharacter& target);

	private:
		std::string	_type;
};

#endif
