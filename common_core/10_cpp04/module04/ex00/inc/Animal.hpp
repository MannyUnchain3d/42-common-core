/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:36:41 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/21 22:17:19 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal {
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const& rhs);
		virtual ~Animal(void);

		Animal&	operator=(Animal const& rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string		_type;
};

#endif