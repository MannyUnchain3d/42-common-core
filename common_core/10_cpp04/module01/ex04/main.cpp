/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:18:36 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/11 02:02:55 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BetterSed.hpp"

int	main(int ac, char** av) {
	if (ac != 4) {
		std::cout << "Error: usage: ./better_sed <filename> <s1> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}
	else {
		BetterSed	replace(av[1]);
		replace.replace(av[2], av[3]);
	}
	return (EXIT_SUCCESS);
}