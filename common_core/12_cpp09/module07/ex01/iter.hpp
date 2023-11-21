/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:11:45 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/21 15:49:35 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename Func>
void	iter(T *array, size_t length, Func f) {
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void	print(T const& c) {
	std::cout << c << ", ";
}

#endif
