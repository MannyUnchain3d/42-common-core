/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:40:14 by Manny             #+#    #+#             */
/*   Updated: 2023/07/16 18:37:51 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap	scav("Ryu");

	scav.attack("Ken");
	scav.takeDamage(10);
	scav.beRepaired(10);
	scav.guardGate();
	return (0);
}