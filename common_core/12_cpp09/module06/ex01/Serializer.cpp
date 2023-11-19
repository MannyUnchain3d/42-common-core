/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:49:35 by Manny             #+#    #+#             */
/*   Updated: 2023/11/19 22:58:18 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Serializer.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
Serializer::Serializer(void) {}

/* Copy Constructor */
Serializer::Serializer(Serializer const& src) {
	*this = src;
}

/* ----- DESTRUCTOR ------------------- */

Serializer::~Serializer(void) {}

/* ----- OPERATOR OVERLOAD ------------ */

Serializer& Serializer::operator=(Serializer const& rhs) {
	(void)rhs;
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

uintptr_t	Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
