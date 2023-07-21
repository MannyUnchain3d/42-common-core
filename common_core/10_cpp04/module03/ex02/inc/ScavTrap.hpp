/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:22:16 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 12:29:42 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& rhs);
		~ScavTrap(void);

		ScavTrap&	operator=(ScavTrap const& rhs);

		void	attack(std::string const& target);
		void	guardGate(void);

	protected:
		ScavTrap(void);

		unsigned int	_scavHp;
		unsigned int	_scavHpMax;
		unsigned int	_scavEp;
		unsigned int	_scavAd;
};

#endif