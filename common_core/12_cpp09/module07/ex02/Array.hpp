/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:15:07 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/21 14:34:47 by etetopat         ###   ########.fr       */
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
		Array(Array const& src);
		~Array();
		
		Array&			operator=(Array const& rhs);
		T&				operator[](unsigned int index);
		T const&		operator[](unsigned int index) const;
		
		unsigned int	size() const;
		void			print() const;
		
		class OutOfRangeException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

#endif
