/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:45:48 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/21 23:14:29 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void) {
	std::vector<int>	v;
	std::list<int>		l;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	try {
		easyFind(v, 3);
		easyFind(l, 6);
	}
	catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}
	return (0);
}