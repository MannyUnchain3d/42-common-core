/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:59 by Manny             #+#    #+#             */
/*   Updated: 2023/11/14 20:10:25 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert [value]" << std::endl;
		return (0);
	}
	std::string	toConvert = av[1];
	ScalarConverter c(toConvert);

	c.convert();
}
