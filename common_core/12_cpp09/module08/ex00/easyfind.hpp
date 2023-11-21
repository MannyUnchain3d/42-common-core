/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:45:41 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/21 23:18:34 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template <typename T>
void	easyFind(T& container, int value) {
	if (std::find(container.begin(), container.end(), value) != container.end())
		std::cout << "Value " << value << " found" << std::endl;
	else
		throw std::exception();
}

#endif
