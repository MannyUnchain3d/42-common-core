/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:24:32 by Manny             #+#    #+#             */
/*   Updated: 2023/07/03 13:01:26 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string const msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	
	if (ac == 1)
		std::cout << msg;
	for (int i = 1; av[i]; i++)
	{
		std::string s = av[i];
		for (std::string::iterator it = s.begin(); it != s.end(); it++)
			*it = std::toupper(*it);
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}
