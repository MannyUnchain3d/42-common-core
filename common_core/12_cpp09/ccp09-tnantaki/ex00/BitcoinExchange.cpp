#include "BitcoinExchange.hpp"

// ********************************************************** //
// ----------------- Orthodox Canonical Form ---------------- //
// ********************************************************** //

BTC::BTC()
{
	_setDataBase("data.csv");
	// std::cout << YELLOW << "[BTC] Default Constructor Called" << RESET << std::endl;
}

BTC::BTC(BTC const& other) : _dataBase(other._dataBase), _lowestDate(other._lowestDate)
{
	// std::cout << YELLOW << "[BTC] Copy Constructor Called" << RESET << std::endl;
}

BTC&	BTC::operator=(BTC const& rhs)
{
	if (this != &rhs)
	{
		_dataBase = rhs._dataBase;
		_lowestDate = rhs._lowestDate;
		// std::cout << YELLOW << "[BTC] Copy Assignment Operator Called" << RESET << std::endl;
	}
	return *this;
}

BTC::~BTC()
{
	// std::cout << YELLOW << "[BTC] Destructor Called" << RESET << std::endl;
}
// ********************************************************** //
// --------------------- Member Functions ------------------- //
// ********************************************************** //

static bool	validFormat(std::string const& line, date_num_t& input);
static bool	isdate_str(std::string date);
static bool	validNumber(std::string number);
static bool	validDate(std::string date, std::string const lowestDate);

void	BTC::evaluate(char* fileName) const
{
	std::ifstream	inputFile;
	date_num_t		input;
	std::string		line;

	std::cout << std::fixed;
	inputFile.open(fileName);
	if (!inputFile.is_open())
		throw CouldNotOpenFile();
	getline(inputFile, line); // Call Head line
	while(getline(inputFile, line)) {
		if (!validFormat(line, input))
			continue ;
		if (!validDate(input.date, _lowestDate))
			continue ;
		if (!validNumber(input.num))
			continue ;
		std::cout << GREEN << input.date << " => " << input.num\
		<< " = " << _getPrice(input.date) * atof((input.num).c_str()) << RESET << std::endl;
	}
	inputFile.close();
}

void	BTC::prtDataBase() const
{
	for (date_price_t::const_iterator it = _dataBase.begin(); it != _dataBase.end(); it++)
		std::cout << it->first << "," << it->second << std::endl;
}

// ********************************************************** //
// ---------------- Private Member Functions ---------------- //
// ********************************************************** //

void	BTC::_setDataBase(const char* fileName)
{
	std::ifstream	csv;
	std::string		line;
	std::size_t		pos;

	csv.open(fileName);
	if (!csv.is_open())
		throw NoDataBase();
	getline(csv, line);
	while (!csv.eof()) {
		getline(csv, line);
		pos = line.find(',');
		if (pos == std::string::npos)	// check in case of there aren't data in line
			continue;
		_dataBase.insert(std::pair<std::string, float>(line.substr(0, pos), atof(line.substr(pos + 1).c_str())));
	}
	date_price_t::iterator	it = _dataBase.begin();
	_lowestDate = it->first;	// store the lowest date
	csv.close();
}

// lower_bound will take the next key if doesn't found key value.
// So I have to take one step back to get lower date
float	BTC::_getPrice(const std::string& date) const
{
	date_price_t::const_iterator	it;

	it = _dataBase.find(date);
	if (it == _dataBase.end())
		it = --_dataBase.lower_bound(date);
	return it->second;
}

// ********************************************************** //
// --------------------- Utils Functions -------------------- //
// ********************************************************** //

static bool	validFormat(std::string const& line, date_num_t& input)
{
	std::string	date;
	std::string	number;
	std::size_t	pos;
	
	pos = line.find("|");
	if (pos == std::string::npos)
		return prtErrMsg("Error: bad input => " + line), false;
	date = line.substr(0, pos);
	ft_strtirm(date, " \t");
	if (!isdate_str(date))
		return prtErrMsg("Error: bad input => " + line), false;
	number = line.substr(pos + 1);
	ft_strtirm(number, " \t");
	if (!ft_isdigit_str(number))
		return prtErrMsg("Error: bad input => " + line), false;
	input.date = date;
	input.num = number;
	return true;
}

static bool	isdate_str(std::string date)
{
	size_t	i = 0;

	while (isdigit(date[i]))
		i++;
	if (i != 4 || date[i] != '-')
		return false;
	date.erase(0, 5);
	i = 0;
	while (isdigit(date[i]))
		i++;
	if (i != 2 || date[i] != '-')
		return false;
	date.erase(0, 3);
	i = 0;
	while (isdigit(date[i]))
		i++;
	if (i != 2 || date[i] != '\0')
		return false;
	return true;
}

static bool	validNumber(std::string number)
{
	long	num = atol(number.c_str());

	if (num > std::numeric_limits<int>::max() || number.length() >> 11)
		prtErrMsg("Error: too large a number.");
	else if (num <= 0)
		prtErrMsg("Error: not a positive number.");
	else
		return true;
	return false;
}

static bool	validDate(std::string date, std::string const lowestDate)
{
	size_t	pos;
	int		year, month, day;

	if (date < lowestDate)
		return prtErrMsg("Error: there aren't data before " + lowestDate), false;
	pos = date.find('-');
	year = atoi(date.substr(0, pos).c_str());
	date.erase(0, pos + 1);
	pos = date.find('-');
	month = atoi(date.substr(0, pos).c_str());
	date.erase(0, pos + 1);
	day = atoi(date.substr(0, date.length()).c_str());
	if (year >= 1900 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
	{
		if ((month == Apr || month == Jun || month == Sep || month == Nov)) {
			if (day <= 30)
				return true;
		}
		else if (month == Feb) {
			if (day <= 28)
				return true;
			else if (day == 29) {
				if (year % 4 == 0 && year % 100 != 0)
					return true;
				else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
					return true;
			}
		}
		else
			return true;
	}
	return prtErrMsg("Error: the specified date is invalid."), false;
}

// ********************************************************** //
// -------------------- Library Functions ------------------- //
// ********************************************************** //

void	prtErrMsg(const std::string msg)
{
	std::cerr << RED << msg << RESET << std::endl;
}

void	ft_strtirm(std::string& str, const char* set)
{
	std::size_t	pos;

	pos = str.find_first_not_of(set);
	str = str.substr(pos);
	pos = str.find_last_not_of(set);
	str = str.substr(0, pos + 1);
}

bool	ft_isdigit_str(const std::string& str)
{
	size_t	i = 0;
	size_t	dot = 0;

	if (str[i] == '-')
		i++;
	while (isdigit(str[i]) || str[i] == '.')
	{
		if (str[i++] == '.')
			dot++;
	}
	// for protect the case of first/last char is '.'
	if (str[i] == '\0' && dot <= 1 && str[i - 1] != '.' && str[0] != '.')
		return true;
	return false;
}
