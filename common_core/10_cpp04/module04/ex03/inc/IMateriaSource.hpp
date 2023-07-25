/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:44:40 by Manny             #+#    #+#             */
/*   Updated: 2023/07/26 01:44:42 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>

class IMateriaSource {
	public:
		IMateriaSource(void);
		IMateriaSource(std::string name);
		IMateriaSource(const IMateriaSource& rhs);
		virtual ~IMateriaSource(void);

		IMateriaSource& operator=(const IMateriaSource& rhs);

	protected:
		void _protectedMethod(void);
		int _protectedAttribute;

	private:
		void _privateMethod(void);
		int _privateAttribute;
};

#endif
