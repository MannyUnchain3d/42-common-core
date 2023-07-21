/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:36:41 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/21 20:27:04 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class	Cat : public Animal {
	public:
		Cat(void);
		Cat(std::string type);
		Cat(Cat* const& rhs);
		virtual ~Cat(void);

		Cat&	operator=(Cat const& rhs);

	protected:
		std::string		_type;
		virtual void	makeSound(void) const = 0;
};

#endif