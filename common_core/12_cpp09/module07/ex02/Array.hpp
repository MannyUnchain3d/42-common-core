/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:15:07 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/20 21:05:04 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
	private:
		T*				_elements;
		unsigned int	_arraySize;
		
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& src);
		~Array();
		
		Array&			operator=(const Array& rhs);
		T&				operator[](unsigned int index);
		
		unsigned int	size() const;
		void			print() const;
		
		class OutOfRangeException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

#endif
