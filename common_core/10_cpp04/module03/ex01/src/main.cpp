/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:40:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/16 03:40:15 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	ClapTrap("Ryu");

	ClapTrap.attack("Ken");
	ClapTrap.takeDamage(5);
	ClapTrap.beRepaired(5);
	return (0);
}