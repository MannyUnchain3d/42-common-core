/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:44:18 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 00:15:52 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"


class Character : public ICharacter {
	public:
		Character(std::string const& name);
		Character(Character const& rhs);
		~Character(void);

		Character& operator=(Character const& rhs);

		std::string const&	getName(void) const;
		virtual void		equip(AMateria* m);
		virtual void		unequip(int idx);
		virtual void		use(int idx, ICharacter& target);

	private:
		std::string			_name;
		std::string			_materiaType;
		static const int	_inventorySize = 4;
		AMateria*			_inventory[_inventorySize];
		int					_nbMateria;

};

#endif
