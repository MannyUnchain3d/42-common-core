/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:32 by Manny             #+#    #+#             */
/*   Updated: 2023/11/14 22:39:40 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
ScalarConverter::ScalarConverter(void) {}

/* Parameter Constructor */
ScalarConverter::ScalarConverter(std::string s) :
	_s(s), _valid(true), _special(false), _onlyDouble(false), _noChar(false) {}

/* Copy Constructor */
ScalarConverter::ScalarConverter(ScalarConverter const& c) :
	_s(c._s), _int(c._int), _float(c._float),_double(c._double),_valid(c._valid),
	_special(c._special),_onlyDouble(c._onlyDouble), _noChar(false) {}

/* ----- DESTRUCTOR ------------------- */

ScalarConverter::~ScalarConverter(void) {}

/* ----- OPERATOR OVERLOAD ------------ */

ScalarConverter &ScalarConverter::operator=(ScalarConverter const& c) {
	if (this != &c)
	{
		this->_int = c._int;
		this->_char = c._char;
		this->_float = c._float;
		this->_double = c._double;
		this->_valid = c._valid;
	}
	return (*this);
}

/* ----- PUBLIC METHODS ---------------- */

bool	ScalarConverter::isNum(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}

bool	ScalarConverter::isSpecialCase(void) {
	std::string cases[6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
	int	i = 0;
	
	while (i < 6 && this->_s != cases[i])
		i++;
	if (i < 6)
		return (true);
	return (false);
}

bool	ScalarConverter::isSpecialCaseFloat(void) {
	std::string cases[3] = {"nanf", "+inff", "-inff"};
	int	i = 0;
	
	while (i < 3 && this->_s != cases[i])
		i++;
	if (i < 3)
		return (true);
	return (false);
}

bool	ScalarConverter::isSpecialCaseDouble(void) {
	std::string cases [3] = {"nan", "+inf", "-inf"};
	int	i = 0;

	while (i < 3 && this->_s != cases[i])
		i++;
	if (i < 3)
		return (true);
	return (false);
}

bool	ScalarConverter::isFloatOrDouble(int mode) {
	int	dot = 0;
	int	f	= 0;

	if (mode == 0 && isSpecialCaseFloat())
		return (true);
	else if (mode == 1 && isSpecialCaseDouble())
		return (true);
	for (int i = 0; i < (int)this->_s.length(); i++)
	{
		if ( i == 0 && (this->_s[i] == '+' || this->_s[i] == '-'))
			continue;
		else if (this->_s.c_str()[i] == '.') {
			if (++dot > 1)
				return (false);
		}
		else if (mode == 0 && this->_s.c_str()[i] =='f') {
			if (++f > 1 || i < (int)this->_s.length() - 1)
				return (false);
		}
		else if (!isNum(this->_s.c_str()[i]))
			return (false);
	}
	if (mode == 0 && (this->_s.find_first_of('.') == this->_s.find_first_of('f') - 1 || f == 0))
		return (false);
	else if (mode == 1 && this->_s.find_first_of('.') == this->_s.length() - 1)
		return (false);
	return (true);
}

int	ScalarConverter::toInt(char const* s) {
	if (s == NULL || *s == '\0')
		throw std::invalid_argument("null or empty string argument");
	bool	negate = (s[0] == '-');
	if (*s == '+' || *s == '-')
		++s;
	if (*s == '\0')
		throw std::invalid_argument("sign character only.");
	long long int	result = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			throw std::invalid_argument("invalid input string");
		result = result * 10 - (*s - '0'); //assume negative number
		if ((negate && result < -2147483648) || (!negate && result < -2147483647))
			throw std::invalid_argument("invalid argument");
		++s;
	}
	return (negate ? result : -result); //-result is positive! 
}

float	ScalarConverter::toFloat(const char *s) {
	if ( s == NULL || *s == '\0')
	   throw std::invalid_argument("null or empty string argument");
	bool	negate = (s[0] == '-');
	if (*s == '+' || *s == '-')
		++s;
	if (*s == '\0')
		throw std::invalid_argument("sign character only.");
	long double	result = 0;
	while (*s != '.') {
		if (*s < '0' || *s > '9')
			throw std::invalid_argument("invalid input string 1");
		result = result * 10 - (*s - '0'); //assume negative number
		if (result > FLT_MAX || result < -FLT_MAX)
			throw std::invalid_argument("invalid argument 1");
		++s;
	}
	double	mul = 0.1;
	s++;
	while (*s != 'f') {
		if (*s < '0' || *s > '9')
			throw std::invalid_argument("invalid input string 2");
		result = result - (*s - '0') * mul;
		if (result > FLT_MAX || result < -FLT_MAX)
			throw std::invalid_argument("invalid argument 2");
		mul *= 0.1;
		++s;
	}
	return (negate ? static_cast<float>(result) : -static_cast<float>(result)); //-result is positive!
}

double	ScalarConverter::toDouble(const char *s) {
	if (s == NULL || *s == '\0')
		throw std::invalid_argument("null or empty string argument");
	bool	negate = (s[0] == '-');
	if (*s == '+' || *s == '-')
		++s;
	if (*s == '\0')
		throw std::invalid_argument("sign character only.");
	long double	result = 0;
	while (*s != '.') {
		if (*s < '0' || *s > '9')
			throw std::invalid_argument("invalid input string 1");
		result = result * 10 - (*s - '0'); //assume negative number
		if (result > DBL_MAX || result < -DBL_MAX)
			throw std::invalid_argument("invalid argument 1");
		++s;
	}
	double	mul = 0.1;
	s++;
	while (*s) {
		if (*s < '0' || *s > '9')
			throw std::invalid_argument("invalid input string 2");
		result = result - (*s - '0') * mul;
		if (result > DBL_MAX || result < -DBL_MAX)
			throw std::invalid_argument("invalid argument 2");
		mul *= 0.1;
		++s;
	}
	return (negate ? static_cast<double>(result) : -static_cast<double>(result)); //-result is positive!
}

int	ScalarConverter::tryChar() {
	if (this->_s.length() == 3) {
		this->_char = this->_s.c_str()[1];
		this->_int = static_cast<int>(this->_char);
		this->_float = static_cast<float>(this->_int);
		this->_double = static_cast<double>(this->_int);
	} else {
		std::cout << "Error: Wrong argument" << std::endl;
		this->_valid = false;
	}
	return 0;
}

int	ScalarConverter::tryFloatOrDouble() {
	if (this->_s.find_first_of('.') != this->_s.find_last_of('.')) {
		std::cout << "Error: Wrong argument" << std::endl;
		this->_valid = false;
	} else {
		if (isFloatOrDouble(0)) {
			if (isSpecialCaseFloat()) {
				std::string	cases[3] = {"nanf", "+inff", "-inff"};
				int	i = 0;
				while (i < 3 && this->_s != cases[i])
					i++;
				this->_float = (1.0f - i) / 0.0f;
				this->_double = static_cast<double>(this->_float);
				this->_special = true;
			} else {
				try {
					this->_float = this->toFloat(this->_s.c_str());
					this->_double = static_cast<double>(this->_float);
					long long int	a = static_cast<long long int>(this->_float);
					if (a > INT_MAX || a < INT_MIN)
						this->_special = true;
					else {
						this->_int = static_cast<int>(this->_float);
						if (this->_int > 127)
							this->_noChar = true;
						else
							this->_char = static_cast<char>(this->_int);
					}
				}
				catch (const std::exception &e) {
					std::cout << e.what() << '\n';
					this->_valid = false;
					return (0);
				}
			}
		} else if (isFloatOrDouble(1)) {
			if (isSpecialCaseDouble()) {
				std::string cases[3] = { "nan", "+inf", "-inf"};
				int	i = 0;
				while (i < 3 && this->_s != cases[i])
					i++;
				this->_double = (1.0 - i) / 0.0;
				this->_float = static_cast<float>(this->_double);
				this->_special = true;
			} else {
				try {
					this->_double = this->toDouble(this->_s.c_str());
					if (this->_double > FLT_MAX || this->_double < -FLT_MAX)
						this->_onlyDouble = true;
					else {
						this->_float = static_cast<float>(this->_double);
						long long int	a = static_cast<long long int>(this->_float);
						if (a > INT_MAX || a < INT_MIN)
							this->_special = true;
						else {
							this->_int = static_cast<int>(this->_float);
							if (this->_int > 127)
								this->_noChar = true;
							else
								this->_char = static_cast<char>(this->_int);
						}
					}
				}
				catch (const std::exception &e) {
					std::cout << e.what() << '\n';
					this->_valid = false;
					return (0);
				}
			}
		} else {
			std::cout << "Error: Wrong argument" << std::endl;
			this->_valid = false;
			return (0);
		}
	}
	return (0);
}

int	ScalarConverter::tryInt() {
	try {
		this->_int = toInt(this->_s.c_str());
		if (this->_int > 127)
			this->_noChar = true;
		else
			this->_char = static_cast<char>(this->_int);
		this->_float = static_cast<float>(this->_int);
		this->_double = static_cast<double>(this->_int);
	}
	catch(const std::exception& e) {
		std::cout << "Error: Wrong argument" << std::endl;
		this->_valid = false;
		return (0);
	}
	return (0);
}

bool	ScalarConverter::charDisplayable() {
	if (this->_char < 32)
		return false;
	return true;
}

void	ScalarConverter::convert() {
	if (this->_s[0] == 39 && this->_s[this->_s.length() - 1] == 39)
		tryChar();
	else if (this->_s.find_first_of('.') != std::string::npos || isSpecialCase())
		tryFloatOrDouble();
	else
		tryInt();
	if (this->_valid) {
		std::cout << std::fixed;
		std::cout << std::setprecision(1);

		std::cout << "char: ";
		if (this->_special || this->_onlyDouble || this->_noChar)
			std::cout << "impossible" << std::endl;
		else if (this->charDisplayable())
			std::cout << this->_char << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

		std::cout << "int: ";
		if (this->_special || this->_onlyDouble)
			std::cout << "impossible" << std::endl;
		else
			std::cout << this->_int << std::endl;

		std::cout << "float: ";
		if (this->_onlyDouble)
			std::cout << "impossible" << std::endl;
		else
			std::cout << this->_float << "f" << std::endl;

		std::cout << "double: " << this->_double << std::endl;
	}
}