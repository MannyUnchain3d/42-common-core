/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:17:40 by Manny             #+#    #+#             */
/*   Updated: 2023/11/18 00:19:08 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <limits>
# include <cmath> // for linux only
# include <typeinfo> // for linux only

class ScalarConverter {
	public:
		void convertChar(double input);
		void convertInt(double input);
		void convertFloat(double input);
		void convertDouble(double input);
		static void	convert(char* input);
		
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& c);
		ScalarConverter &operator=(ScalarConverter const& c);
		~ScalarConverter(void);
};

#endif
