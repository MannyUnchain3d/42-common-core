/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:09:46 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/22 20:10:42 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <exception>

class Span {
	public:
		Span(unsigned int n);
		Span(Span const& src);
		~Span(void);

		Span&			operator=(Span const& rhs);
		void			addNumber(int n);
		void			addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		
		std::list<int> const&	getList(void) const;

	private:
		std::list<int>	_list;
		unsigned int	_n;
		
		Span(void);
};

std::ostream&	operator<<(std::ostream& out, Span const& rhs);

#endif
