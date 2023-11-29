/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:34:07 by Manny             #+#    #+#             */
/*   Updated: 2023/11/29 16:44:55 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <algorithm>
# include <map>

typedef std::string string;

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const& src);
		~BitcoinExchange(void);

		BitcoinExchange& operator=(BitcoinExchange const& rhs);

		void	extract(string const& filename);

	private:
		std::map<string, string>	_data;

		string	_previousDate(string const& date);
		string	_nextDate(string const& date);
		string	_trimWS(string const& str);

		bool	_fileExists(string const& filename);
		bool	_isEmpty(string const& filename);
		bool	_isLeapYear(int year);
		bool	_isAllDigit(string const& str, int (*isDigit)(int));

		void	_checkValue(string const& str);
		bool	_validDate(string const& str);

		int		_toInt(string const& str);
		double	_toDouble(string const& str);
		string	_toStr(int value);;
};

#endif
