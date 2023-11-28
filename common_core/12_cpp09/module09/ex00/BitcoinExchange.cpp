/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:34:02 by Manny             #+#    #+#             */
/*   Updated: 2023/11/24 20:32:03 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ----- CONSTRUCTOR ------------------ */

/* Default Constructor */
BitcoinExchange::BitcoinExchange(void) {
	std::ifstream	file("data.csv");
	string			line;

	std::getline(file, line); // Skip first line
	while (std::getline(file, line)) {
		size_t	delim = line.find(',');
		string	date = _trim(line.substr(0, delim));
		string	value = _trim(line.substr(delim + 1, line.length()));
		
		_data[date] = value;
	}
	file.close();
}

/* Copy Constructor */
BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) {
	*this = src;
}

/* ----- DESTRUCTOR ------------------- */

BitcoinExchange::~BitcoinExchange(void) {}

/* ----- OPERATOR OVERLOAD ------------ */

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs) {
	if (this != &rhs)
		_data = rhs._data;
	return (*this);
}

/* ----- PUBLIC METHOD ---------------- */

void BitcoinExchange::convert(string const& filename) {
	std::ifstream	file(filename.c_str());
	string			line;

	if (!file.is_open()) {
		std::cout << "Error: file does not exist or can't be opened" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Error: file is empty" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::getline(file, line); // Skip first line

	if (line != "date | value") {
		std::cout << "Error: invalid file format" << std::endl;
		exit(EXIT_FAILURE);
	}

	while (getline(file, line)) {
		size_t delim = line.find('|');
		if (delim == string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		string	date  = _trim(line.substr(0, delim));
		string	value = _trim(line.substr(delim + 1));

		try {
			if (!_validDate(date))
				throw std::invalid_argument("invalid date: " + (date.empty() ? "\"\"" : "'" + date + "'"));
			if (value.empty())
				throw std::invalid_argument("invalid value: " + (value.empty() ? "\"\"" : "'" + value + "'"));
			
			_checkValue(value);
			
			std::map<string, string>::iterator	it;
			string	prevDate = date;
			it = _data.find(date);

			while (it == _data.end()) {
				string const& currentDate = prevDate;
				prevDate = _previousDate(currentDate);
				it = _data.find(prevDate);
			}
			std::cout << date << " => " << value << " = "
				<< _toDigit(it->second) * _toDigit(value) << std::endl;

		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	file.close();
}

/* ----- PRIVATE METHOD --------------- */

bool	BitcoinExchange::_isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int		BitcoinExchange::_toInt(string const& str) {
	std::stringstream	ss(str);
	int					value;

	ss >> value;
	return (value);
}

double	BitcoinExchange::_toDigit(string const& str) {
	std::stringstream	ss(str);
	double				value;

	ss >> value;
	return (value);
}

string	BitcoinExchange::_toStr(int value) {
	std::stringstream	ss;
	
	ss << value;
	return (ss.str());
}

string	BitcoinExchange::_previousDate(string const& date) {
	int	year  = _toInt(date.substr(0, 4));
	int	month = _toInt(date.substr(5,2));
	int	day   = _toDigit(date.substr(8, 2));
	
	int	daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (_isLeapYear(year))
		daysInMonth[2] = 29;
	day--;
	
	if (day == 0) {
		month--;
		
		if (month == 0) {
		month = 12;
		year--;
		}
		day = daysInMonth[month];
	}
	
	string	newYear  = _toStr(year);
	string	newMonth = (month < 10) ? "0" + _toStr(month) : _toStr(month);
	string	newDay   = (day < 10) ? "0" + _toStr(day) : _toStr(day);

	return (newYear + "-" + newMonth + "-" + newDay); 
}
