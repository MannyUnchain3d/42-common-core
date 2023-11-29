/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:34:02 by Manny             #+#    #+#             */
/*   Updated: 2023/11/29 22:18:32 by etetopat         ###   ########.fr       */
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
		string	date = _trimWS(line.substr(0, delim));
		string	value = _trimWS(line.substr(delim + 1, line.length()));
		
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

void BitcoinExchange::extract(string const& filename) {
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
		
		string	date  = _trimWS(line.substr(0, delim));
		string	value = _trimWS(line.substr(delim + 1));

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
				<< _toDouble(it->second) * _toDouble(value) << std::endl;

		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	file.close();
}

/* ----- PRIVATE METHOD --------------- */

string	BitcoinExchange::_previousDate(string const& date) {
	int	year  = _toInt(date.substr(0, 4));
	int	month = _toInt(date.substr(5,2));
	int	day   = _toInt(date.substr(8, 2));
	
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
	
	// Format date
	string	newYear  = _toStr(year);
	string	newMonth = (month < 10) ? "0" + _toStr(month) : _toStr(month);
	string	newDay   = (day < 10) ? "0" + _toStr(day) : _toStr(day);

	return (newYear + "-" + newMonth + "-" + newDay); 
}

string	BitcoinExchange::_nextDate(string const& date) {
	string	year  = date.substr(0, 4);
	string	month = date.substr(5, 2);
	string	day   = date.substr(8, 2);
	
	int	yearInt  = _toInt(year);
	int	monthInt = _toInt(month);
	int	dayInt   = _toInt(day);

	int	daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
	
	if (_isLeapYear(yearInt))
		daysInMonth[2] = 29;
	dayInt++;

	if (dayInt > daysInMonth[monthInt]) {
		dayInt = 1;
		monthInt++;

		if (monthInt > 12) {
			yearInt++;
			monthInt = 1;
		}		
	}
	
	string	newYear  = _toStr(yearInt);
	string	newMonth = (monthInt < 10) ? "0" + _toStr(monthInt) : _toStr(monthInt);
	string	newDay   = (dayInt < 10) ? "0" + _toStr(dayInt) : _toStr(dayInt);
	
	return (newYear + "-" + newMonth + "-" + newDay);
}

string	BitcoinExchange::_trimWS(string const& str) {
	size_t	start = str.find_first_not_of(' ');
	if (start == string::npos)
		return (str);

	size_t	end = str.find_last_not_of(' ');
	return (str.substr(start, end - start + 1));
}

bool	_fileExists(string const& filename) {
	std::ifstream	file(filename);
	
	bool exists = file.good();
	file.close();
	return (exists);
}

bool	_isEmpty(string const& filename) {
	std::ifstream	file(filename);

	bool	empty = file.peek() == std::ifstream::traits_type::eof();
	file.close();
	return (empty);
}

bool	BitcoinExchange::_isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool	BitcoinExchange::_isAllDigit(string const& str, int (*isDigit)(int)) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!isDigit(str[i]))
			return (false);
	}
	return (true);
}

void	BitcoinExchange::_checkValue(string const& str) {
	double	value;
	
	try {
		if (std::find(str.begin(), str.end(), '.') != str.end()) {
			size_t	dot = str.find('.');
			if (std::find(str.begin() + dot + 1, str.end(), '.') != str.end())
				throw std::invalid_argument("invalid value: '" + str + "'");
		}
		
		bool	hasSign = str[0] == '+' || str[0] == '-';
		for (size_t i = hasSign ? 1 : 0; i < str.length(); i++) {
			if (::isdigit(str[i]) || str[i] == '.')
				continue;
			throw std::invalid_argument("not a number => " + str);
		}

		value = _toDouble(str);
	} catch (std::exception &e) {
		throw std::invalid_argument("not a number => " + str);
	}

	if (value < 0)
		throw std::invalid_argument("not a positive number");
	
	if (value > 1000.0)
		throw std::invalid_argument("number too big");
}

bool	BitcoinExchange::_validDate(string const& date) {
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	
	string	year  = date.substr(0, 4);
	string	month = date.substr(5, 2);
	string	day   = date.substr(8, 2);

	if (!_isAllDigit(year, ::isdigit)
		|| !_isAllDigit(month, ::isdigit)
		|| !_isAllDigit(day, ::isdigit))
		return (false);

	int	yearInt, monthInt, dayInt;

	std::stringstream	ssYear(year);
	std::stringstream	ssMonth(month);
	std::stringstream	ssDay(day);

	ssYear >> yearInt;
	ssMonth >> monthInt;
	ssDay >> dayInt;

	if ((yearInt < 2009 || yearInt > 2022)
		|| (monthInt < 1 || monthInt > 12)
		|| (dayInt < 1 || dayInt > 31))
		return (false);
	
	// Check that April, June, September and November have 30 days
	if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
			return (false);

	// Check for leap year
	if (monthInt == 2) {
		bool	leapYear = _isLeapYear(yearInt);
		if (dayInt > (leapYear ? 29 : 28))
			return (false);
	}
	return (true);
}

int		BitcoinExchange::_toInt(string const& str) {
	std::stringstream	ss(str);
	int					value;

	ss >> value;
	return (value);
}

double	BitcoinExchange::_toDouble(string const& str) {
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
