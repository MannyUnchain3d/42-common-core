/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:32 by Manny             #+#    #+#             */
/*   Updated: 2023/11/15 21:10:05 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
ScalarConverter::ScalarConverter(void) {}

/* Copy Constructor */
ScalarConverter::ScalarConverter(ScalarConverter const& c) {
	*this = c;
}

/* ----- DESTRUCTOR ------------------- */

ScalarConverter::~ScalarConverter(void) {}

/* ----- OPERATOR OVERLOADS ----------- */

ScalarConverter &ScalarConverter::operator=(ScalarConverter const& c) {
	(void)c;
	return (*this);
}

/* ----- PUBLIC METHODS ---------------- */

void	ScalarConverter::convertChar(double input) {
	char	c;
	std::stringstream ss;
	if (isnan(input) == 1) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (isprint(input) == 1) {
		c = static_cast<char>(input);
		std::cout << "char: " << "'" + ss.str() + "'" << std::endl;
	}
	std::cout << "char: Non displayable" << std::endl;
	return ;
}

void	ScalarConverter::convertInt(double input) {
	if (isnan(input) || isinf(input))
		std::cout << "int: impossible" << std::endl;
	return ;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
}

void	ScalarConverter::convertFloat(double input) {
	std::stringstream c;
	c << input ;
	if (isnan(input) == 1) {
		std::cout << "float: " << c.str() + 'f' <<std::endl;
		return ;
	}
	double cast = static_cast<double>(input);
	std::cout << "float: " << std::fixed << std::setprecision(1) << cast << 'f' << std::endl;
	return ;
}

void	ScalarConverter::convertDouble(double input) {
	std::cout << "double: " << std::fixed << std::setprecision(1) << input << std::endl;
	return ;
}

void	ScalarConverter::convert(char* input) {
	char *endPtr;
	double c = std::strtod(input, &endPtr);
	convertChar(c);
	convertInt(c);
	convertFloat(c);
	convertDouble(c);
}
