/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:40 by Manny             #+#    #+#             */
/*   Updated: 2023/11/14 22:39:46 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cfloat> // for FLT_MIN
# include <iomanip>
# include <stdexcept>

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(std::string s);
		ScalarConverter(ScalarConverter const& c);

		ScalarConverter &operator=(ScalarConverter const& c);
		~ScalarConverter(void);

		bool	isNum(char c);
		bool	isSpecialCase(void);
		bool	isSpecialCaseFloat(void);
		bool	isSpecialCaseDouble(void);
		bool	isFloatOrDouble(int mode);

		int		toInt(char const* s);
		float	toFloat(char const* s);
		double	toDouble(char const* s);

		int		tryFloatOrDouble(void);
		int		tryChar(void);
		int		tryInt(void);

		bool	charDisplayable(void);

		void	convert(void);

	private:
		std::string const	_s;
		int		_int;
		char	_char;
		float	_float;
		double	_double;
		bool	_valid;
		bool	_special;
		bool	_onlyDouble;
		bool	_noChar;
};

#endif
