/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:39:30 by Manny             #+#    #+#             */
/*   Updated: 2023/07/12 03:06:56 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char** av) {
	if (ac != 2)
		return (std::cout << "Usage: " << av[0] << " \"level\"" << std::endl, 1);

	std::string	input = av[1];
	Harl		harl;

	harl.complain(input);
	return (0);
}