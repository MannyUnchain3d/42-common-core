/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:48:28 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 06:39:11 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	public:
		ClapTrap(ClapTrap const& rhs);
		ClapTrap(std::string name);
		~ClapTrap(void);

		ClapTrap& operator=(const ClapTrap& rhs);

		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		ClapTrap(void);
		
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_hpMax;
		unsigned int	_ep;
		unsigned int	_ad;
};

#endif