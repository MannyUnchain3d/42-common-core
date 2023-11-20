/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:27:40 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/20 19:27:41 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

class iter {
	public:
		iter(void);
		iter(std::string name);
		iter(iter const& src);
		~iter(void);

		iter& operator=(iter const& rhs);

	protected:
		void _protectedMethod(void);
		int _protectedAttribute;

	private:
		void _privateMethod(void);
		int _privateAttribute;
};

#endif
