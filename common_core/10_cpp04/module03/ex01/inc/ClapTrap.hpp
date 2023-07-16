/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:40:08 by Manny             #+#    #+#             */
/*   Updated: 2023/07/16 15:21:43 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& rhs);
		ClapTrap(std::string name);
		~ClapTrap(void);

		ClapTrap& operator=(const ClapTrap& rhs);

		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string			_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;
};

#endif