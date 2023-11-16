/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:40 by Manny             #+#    #+#             */
/*   Updated: 2023/11/16 20:46:22 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <limits>
# include <cmath> // for linux only

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

		template <typename T>
    	static void printType(const T& value) {
        	std::cout << "Type of " << value << " is: " << typeid(value).name() << std::endl;
		}
};

#endif
