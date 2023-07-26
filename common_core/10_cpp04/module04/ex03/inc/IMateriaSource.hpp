/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:44:40 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 20:27:35 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>

class AMateria;

class IMateriaSource {
	public:
		virtual ~IMateriaSource(void) {};
		virtual void		learnMateria(AMateria* m) = 0;
		virtual AMateria*	createMateria(std::string const& type) = 0;
};

#endif
