/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:36:41 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/21 22:30:21 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class	Dog : public Animal {
	public:
		Dog(void);
		Dog(std::string type);
		Dog(Dog const& rhs);
		virtual ~Dog(void);

		Dog&	operator=(Dog const& rhs);

	protected:
		std::string	_type;
		virtual void	makeSound(void) const;
};

#endif