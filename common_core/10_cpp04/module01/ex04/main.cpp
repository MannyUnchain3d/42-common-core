/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:18:36 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/10 23:50:52 by etetopat         ###   ########.fr       */
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