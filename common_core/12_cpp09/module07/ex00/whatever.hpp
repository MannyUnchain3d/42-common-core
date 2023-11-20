/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:18:21 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/20 19:02:37 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T_SWAP>

void swap(T_SWAP &a, T_SWAP &b) {
	T_SWAP tmp = a;
	a = b;
	b = tmp;
}

template<typename T_MIN>

T_MIN min(T_MIN a, T_MIN b) {
	if (a == b)
		return (b);
	return (a < b ? a : b);
}

template<typename T_MAX>

T_MAX max(T_MAX a, T_MAX b) {
	if (a == b)
		return (b);
	return (a > b ? a : b);
}

#endif
