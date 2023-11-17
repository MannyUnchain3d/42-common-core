/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:32 by Manny             #+#    #+#             */
/*   Updated: 2023/11/18 00:54:25 by Manny            ###   ########.fr       */
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
	if (input >= std::numeric_limits<char>::min()
		&& input <= std::numeric_limits<char>::max())
		c = static_cast<char>(input);
	if (isprint(static_cast<unsigned char>(c)))
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	ScalarConverter::convertInt(double input) {
	if (isnan(input) || isinf(input) || input < std::numeric_limits<int>::min()
		|| input > std::numeric_limits<int>::max()) {
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
	if (input < -std::numeric_limits<float>::max() || input > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else if (input - static_cast<float>(input) == 0)
		std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input) << "f" << std::endl;
}

void ScalarConverter::convertDouble( double input ) {
	if (isnan(input) || isinf(input)) {
		std::cout << "double: " << input << std::endl;
		return ;
	}
	if (input < -std::numeric_limits<double>::max() || input > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else if (input - static_cast<double>(input) == 0)
		std::cout << "double: " << std::fixed << std::setprecision(1) << input << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << input << ".0" <<std::endl;
}

void	ScalarConverter::convert(char* input) {
	char *endPtr;
	double c = std::strtod(input, &endPtr);
	
	if (*endPtr != '\0' && !(endPtr == input + 1 && *input == '-')) {
		std::cout << "Use digits only. First non-digit character found: " << "'" << *endPtr << "'" << std::endl;
		return ;
	}

	ScalarConverter sc;
	if (input[0] == '-') {
		// Handle negative number
		sc.convertChar(c);
		sc.convertInt(c);
		sc.convertFloat(c);
		sc.convertDouble(c);
	} else {
		// Handle positive number
		sc.convertChar(c);
		sc.convertInt(c);
		sc.convertFloat(c);
		sc.convertDouble(c);
	}
}
