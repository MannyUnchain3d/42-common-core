/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:44:18 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 01:44:20 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

class Character {
	public:
		Character(void);
		Character(std::string name);
		Character(const Character& rhs);
		virtual ~Character(void);

		Character& operator=(const Character& rhs);

	protected:
		void _protectedMethod(void);
		int _protectedAttribute;

	private:
		void _privateMethod(void);
		int _privateAttribute;
};

#endif
