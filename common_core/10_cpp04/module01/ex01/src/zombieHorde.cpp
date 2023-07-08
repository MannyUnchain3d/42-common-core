/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:46:35 by Manny             #+#    #+#             */
/*   Updated: 2023/07/09 02:37:45 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (NULL);
	Zombie* zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return (zombies);
}