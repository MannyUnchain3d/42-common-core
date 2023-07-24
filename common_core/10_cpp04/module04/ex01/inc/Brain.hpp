/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:13:29 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/25 01:52:57 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	public:
		Brain(void);
		Brain(Brain const& rhs);
		virtual ~Brain(void);

		Brain& operator=(Brain const& rhs);

		std::string*	getIdeas(void) const;
		Brain*			clone(void) const;

	protected:
		std::string*	_ideas;

};

#endif