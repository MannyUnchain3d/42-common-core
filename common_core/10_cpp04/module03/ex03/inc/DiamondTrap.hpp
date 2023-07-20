/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:22:16 by Manny             #+#    #+#             */
/*   Updated: 2023/07/20 21:39:30 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& rhs);
		~DiamondTrap(void);

		DiamondTrap&	operator=(DiamondTrap const& rhs);

		void	whoAmI(void);
		using	ScavTrap::attack;

	protected:
		DiamondTrap(void);

	private:
		std::string	_name;
};

#endif