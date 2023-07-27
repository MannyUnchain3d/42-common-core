/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:44:49 by Manny             #+#    #+#             */
/*   Updated: 2023/07/27 20:36:17 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const& rhs);
		~MateriaSource(void);

		MateriaSource& operator=(MateriaSource const& rhs);

		virtual AMateria*	getMateria(std::string const& type);
		virtual AMateria*	createMateria(std::string const& type);
		virtual void		learnMateria(AMateria* materia);

	private:
		static int const	_materiasMax = 4;
		AMateria* 			_materias[MateriaSource::_materiasMax];
};

#endif
