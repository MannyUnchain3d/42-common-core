/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:43:18 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/23 00:24:59 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>
# include <list>

/* Defines a template class for a stack with added features.
 * Uses std::stack as the base and allows customization of the underlying container.
 * Default container used is std::deque. */
template < typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack(void) {};
		MutantStack(MutantStack const& src) { *this = src; };
		~MutantStack(void) {};

		MutantStack& operator=(MutantStack const& rhs) {
			std::stack<T, Container>::operator=(rhs);
			return (*this);
		}
		
		/* Iterator type definition for convenience. */
		typedef typename Container::iterator	iterator;
		
		iterator	begin() { return (this->c.begin()); }
		iterator	end() { return (this->c.end()); }
};

#endif
