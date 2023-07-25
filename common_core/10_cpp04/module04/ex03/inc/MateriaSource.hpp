/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:44:49 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 01:44:51 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>

class MateriaSource {
	public:
		MateriaSource(void);
		MateriaSource(std::string name);
		MateriaSource(const MateriaSource& rhs);
		virtual ~MateriaSource(void);

		MateriaSource& operator=(const MateriaSource& rhs);

	protected:
		void _protectedMethod(void);
		int _protectedAttribute;

	private:
		void _privateMethod(void);
		int _privateAttribute;
};

#endif
