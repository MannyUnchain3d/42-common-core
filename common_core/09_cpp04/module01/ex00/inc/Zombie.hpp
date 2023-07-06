/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:07:12 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/06 19:25:53 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;

	private:
		std::string	_name;
		std::string _getName(void) const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif