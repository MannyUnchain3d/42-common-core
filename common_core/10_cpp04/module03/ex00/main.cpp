/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:48:21 by Manny             #+#    #+#             */
/*   Updated: 2023/07/16 03:23:43 by Manny            ###   ########.fr       */
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