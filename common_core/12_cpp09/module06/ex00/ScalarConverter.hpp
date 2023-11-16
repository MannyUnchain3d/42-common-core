/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:40 by Manny             #+#    #+#             */
/*   Updated: 2023/11/15 23:49:57 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cmath>

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
