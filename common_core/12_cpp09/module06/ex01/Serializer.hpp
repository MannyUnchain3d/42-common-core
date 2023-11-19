/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:03:57 by Manny             #+#    #+#             */
/*   Updated: 2023/11/19 22:21:16 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h> // for uintptr_t

typedef struct Data {
	std::string	name;
	int			level;
} Data;

class Serializer {
	private:
		Serializer(void);
		Serializer(Serializer const& src);
		~Serializer(void);

		Serializer& operator=(Serializer const& rhs);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
