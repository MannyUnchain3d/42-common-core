/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:40 by Manny             #+#    #+#             */
/*   Updated: 2023/11/15 20:34:28 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <sstream>
# include <iomanip>

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& c);

		ScalarConverter &operator=(ScalarConverter const& c);
		~ScalarConverter(void);

		static void convertChar(double input);
		static void convertInt(double input);
		static void convertFloat(double input);
		static void convertDouble(double input);
		static void	convert(char* input);
};

#endif
