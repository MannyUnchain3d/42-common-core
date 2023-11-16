/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:32 by Manny             #+#    #+#             */
/*   Updated: 2023/11/16 00:10:12 by Manny            ###   ########.fr       */
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
	if (isnan(input) || isinf(input)) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (isprint(input)) {
		c = static_cast<char>(input);
		std::cout << "char: " << "'" << c << "'" << std::endl;
	}
	std::cout << "char: Non displayable" << std::endl;
}

void	ScalarConverter::convertInt(double input) {
	if (isnan(input) || isinf(input)) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(input) << std::endl;
}

void	ScalarConverter::convertFloat(double input) {
	if (isnan(input) || isinf(input)) {
		std::cout << "float: " << input << "f" <<std::endl;
		return ;
	}
	std::cout << "float: " << std::fixed;
	if (input - static_cast<float>(input) == 0)
		std::cout << static_cast<float>(input) << std::endl;
	else
		std::cout << std::setprecision(1) << static_cast<float>(input) << "f" << std::endl;
}

void ScalarConverter::convertDouble( double input ) {
	if (isnan(input) || isinf(input))
		std::cout << "double: " << input << std::endl;
	else
		std::cout << "double: " << input << ".0" << std::endl;
}

void	ScalarConverter::convert(char* input) {
	char *endPtr;
	double c = std::strtod(input, &endPtr);
	convertChar(c);
	convertInt(c);
	convertFloat(c);
	convertDouble(c);
}
